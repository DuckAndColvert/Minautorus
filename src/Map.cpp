#include <Map.hpp>
#include <Maze.hpp>
#include <cassert>
#include <Chunk.hpp>

Map::Map()
{
  initTiles();
}

Tile* Map::get(size_t i, size_t j)
{
  assert(i>=0);
  assert(j>=0);
  assert( i < NB_TILE_HEIGHT );
  assert( j < NB_TILE_WIDTH );
  
  return m_tiles[i][j];
}

void Map::initTiles()
{
  /* init Tiles */
  for(size_t i=0; i < NB_TILE_HEIGHT; i++)
    {
        for(size_t j=0; j < NB_TILE_WIDTH; j++)
	  {
	    m_tiles[i][j] = new Tile;
	    m_tiles[i][j]->i = i;
	    m_tiles[i][j]->j = j;
	    m_tiles[i][j]->obstacle = false;
	    m_tiles[i][j]->type = NONE;
	  }
    }

  /* place a maze */
  placeMaze(0, 0, NB_BLOC_WIDTH, NB_BLOC_HEIGHT);

  /* init chunks */
  for(size_t i=0; i < NB_CHUNK_HEIGHT; i++)
    {
      for(size_t j=0; j < NB_CHUNK_WIDTH; j++)
	  {
	    m_chunks.push_back( new Chunk(this,i*CHUNK_HEIGHT,j*CHUNK_WIDTH));
	  }
    }
 
  

}

void Map::placeMaze(size_t I, size_t J, size_t W, size_t H)
{
  MazeGenerator::Maze maze(H, W);
  maze.compute();
 
  for( size_t i = 0; i < H; i++ )
    {
      for( size_t j = 0; j < W; j++ )
	{
	  bool *b = maze.get(i,j)->border;
	 
	  /* entrance and exit */
	  if( i == H-1 && j == W-1 )
	    {
	      b[3] = false ;
	    }

	  if( i == 0 && j == 0 )
	    {
	      b[2] = false ;
	    }
	  
	  putBloc(I + i * (BLOC_SIZE+1), J + j * (BLOC_SIZE+1),
		  BLOC_SIZE, BLOC_SIZE, b);
	}
    }
}

void Map::putBloc(size_t I, size_t J, size_t W, size_t H, bool border[4])
{
  assert(border);
  assert( I >= 0 );
  assert( I < NB_TILE_HEIGHT );
  assert( J >= 0 );
  assert( J < NB_TILE_WIDTH );
  
  for(size_t i = 0; i < H+2; i++)
    {
      for(size_t j = 0; j < W+2; j++)
	{
	 
	  if( ( i == 0 && border[0] ) )
	    {
	      m_tiles[i + I][j + J]->type = WALL_UP;
	    }
	  else if( ( i == H+1 && border[1] ) )
	    {
	      m_tiles[i + I][j + J]->type = WALL_DOWN;
	    }
	  else if( ( j == 0 && border[2] ) )
	    {
	      m_tiles[i + I][j + J]->type = WALL_LEFT;
	    }
	  else if( ( j == W+1 && border[3] ) )
	    {
	      m_tiles[i + I][j + J]->type = WALL_RIGHT;
	    }
	  else
	    {
	      // walls can't be removed
	      if( !isAWall(i + I, j + J) )
		{
		  m_tiles[i + I][j + J]->type = GROUND;
		}
	      
	    }
	  
	}
    }
}


bool Map::isAWall(size_t i, size_t j)
{
  assert(m_tiles[i][j]);
  
  switch( m_tiles[i][j]->type )
    {
    case WALL_UP:
    case WALL_DOWN:
    case WALL_LEFT:
    case WALL_RIGHT:
      return true;
	    
    default:
      return false;
      break;
    }
}

bool Map::isInTheScreen(Tile const* t)
{
  assert(t);
  
  return (t->i >= 0 && t->i < NB_VISIBLE_TILE_HEIGHT
	  && t->j >= 0 && t->j < NB_VISIBLE_TILE_WIDTH);
}


void Map::display(sf::RenderWindow *win)
{
  for( Chunk *c: m_chunks )
    {
      c->draw(win);
    }
}

Map::~Map()
{
  //delete Tiles
  for(size_t i=0; i < NB_TILE_HEIGHT; i++)
    {
      for(size_t j=0; j < NB_TILE_WIDTH; j++)
	{
	  delete m_tiles[i][j];

	}
    }

  for( Chunk *c: m_chunks )
    {
      delete c;
    }
  
  //m_vertex_array.clear();

}
