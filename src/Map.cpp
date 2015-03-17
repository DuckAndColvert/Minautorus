#include <Map.hpp>


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
	    m_tiles[i][j]->type = GROUND;
	    createVertexTile(i, j, BLOC_WIDTH, BLOC_HEIGHT, sf::Color::Black);

	  }
    }
}


void Map::createVertexTile(size_t i, size_t j,size_t w,size_t h, sf::Color color)
{

  //real coordinate in the windows
  size_t I = i * BLOC_HEIGHT;
  size_t J = j * BLOC_WIDTH;

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
