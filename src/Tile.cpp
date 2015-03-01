#include<Tile.hpp>

#include<TextureLoader.hpp>
#include<assert.h>
Tile::Tile(string id):
  m_id(id)
{

}

Tile::Tile(short id) 
// quick Conversion when creating the tile.
{
  m_id=TextureLoader::TILES_IDENTIFIER[id];
  assert(m_id!="");
}

Tile::~Tile()
{
  
}
