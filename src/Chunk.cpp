#include <Chunk.hpp>
#include <Map.hpp>
#include <cassert>

Chunk::Chunk(Map* map,size_t i, size_t j): m_map(map),m_i(i), m_j(j)
{
  m_vertex_array = sf::VertexArray(sf::Quads, 4*CHUNK_HEIGHT*CHUNK_WIDTH);

  initTiles();
}

void Chunk::initTiles()
{
  for(size_t i=0; i<CHUNK_HEIGHT;i++)
    {
      for(size_t j=0; j<CHUNK_WIDTH;j++)
	{
	   if( m_i + i>=0 && m_j + j>=0 && m_i + i < NB_TILE_HEIGHT && m_j + j < NB_TILE_WIDTH )
	    {
	      m_tiles[i][j] = m_map->get(i+m_i,j+m_j);
	    }
	   else
	     {
	       m_tiles[i][j] = nullptr;
	     }
	}
    }

  for(size_t i=0; i<CHUNK_HEIGHT;i++)
    {
      for(size_t j=0; j<CHUNK_WIDTH;j++)
	{
	  if( m_tiles[i][j] )
	    {
	      createVertexTile(m_tiles[i][j]);
	    }
	}
    }
}


void Chunk::createVertexTile(Tile *tile)
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
      color = sf::Color::Yellow;
      break;
    }

  createVertexTile(tile->i, tile->j, TILE_WIDTH, TILE_HEIGHT,color);
}

void Chunk::createVertexTile(size_t i, size_t j,size_t w,size_t h, sf::Color color)
{
 //real coordinate in the windows
  size_t I = i * TILE_HEIGHT;
  size_t J = j * TILE_WIDTH;

  //get a pointer on the vertex at the coord (i,j)
  sf::Vertex *tile = &m_vertex_array[ ((i-m_i) * CHUNK_WIDTH + (j-m_j)) * 4 ];
   

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

void Chunk::draw(sf::RenderWindow *win)
{
  win->draw(m_vertex_array);
}

Chunk::~Chunk()
{
}
