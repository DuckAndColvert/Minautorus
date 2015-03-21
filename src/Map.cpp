#include <Map.hpp>
#include <Maze.hpp>
#include <cassert>

Map::Map()
{
  m_vertex_array = sf::VertexArray(sf::Quads, NB_TILE_HEIGHT * NB_TILE_WIDTH * 4);
  initTiles();
}


void Map::display(sf::RenderWindow *win)
{
  win->draw(m_vertex_array);
}


void Map::initTiles()
{
  
  for(size_t i=0; i < NB_TILE_HEIGHT; i++)
    {
        for(size_t j=0; j < NB_TILE_WIDTH; j++)
	  {
	    m_tiles[i][j] = new Tile;
	    m_tiles[i][j]->i = i;
	    m_tiles[i][j]->j = j;
	    m_tiles[i][j]->obstacle = false;
	    m_tiles[i][j]->type = NONE;
	    
	    createVertexTile(m_tiles[i][j]);

	  }
    }

  
  MazeGenerator::Maze maze(NB_BLOC_HEIGHT,NB_BLOC_WIDTH);
  maze.compute();
 
  for( size_t i = 0; i < NB_BLOC_HEIGHT; i++ )
    {
      for( size_t j = 0; j < NB_BLOC_WIDTH; j++ )
	{
	  bool *b = maze.get(i,j)->border;
	 
	  /* entrance and exit */
	  if( i == NB_BLOC_HEIGHT-1 && j == NB_BLOC_WIDTH-1 )
	    {
	      //b[1] = false;
	      b[3] = false ;
	    }

	  if( i == 0 && j == 0 )
	    {
	      //b[0] = false;
	      b[2] = false ;
	    }
	  
	  putBloc(i * (BLOC_SIZE+1), j * (BLOC_SIZE+1),
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
	  /*
	  if( ( i == 0 && border[0] ) || ( i == H+1 && border[1]) 
	      || ( j == 0 && border[2] ) || ( j == W+1 && border[3])
	      )
	    {
	      m_tiles[i + I][j + J]->type = WALL_UP;
	      }*/
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
	  
	  createVertexTile(m_tiles[i + I][j + J]);
	}
    }
}

void Map::createVertexTile(Tile *tile)
{
  assert(tile);
  
  sf::Color color;

  switch( tile->type )
    {
    case GROUND:
      color = sf::Color::Green;
      break;

    case WALL_UP:
    case WALL_DOWN:
    case WALL_LEFT:
    case WALL_RIGHT:
      color = sf::Color::Black;
      break;
      
    default:
      color = sf::Color::Red;
      break;
    }
  
  createVertexTile(tile->i, tile->j, TILE_WIDTH, TILE_HEIGHT,color);
}

void Map::createVertexTile(size_t i, size_t j,size_t w,size_t h, sf::Color color)
{

  //real coordinate in the windows
  size_t I = i * TILE_HEIGHT;
  size_t J = j * TILE_WIDTH;

  //get a pointer on the vertex at the coord (i,j)
  sf::Vertex* tile = &m_vertex_array[ (i * NB_TILE_WIDTH + j) * 4 ];
  
  tile[0].position = sf::Vector2f(J,I);
  tile[1].position = sf::Vector2f(J + w, I);
  tile[2].position = sf::Vector2f(J + w, I + h);
  tile[3].position = sf::Vector2f(J, I + h);

  //TODO Texture
  tile[0].color = color;
  tile[1].color = color;
  tile[2].color = color;
  tile[3].color = color;
  
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

}
