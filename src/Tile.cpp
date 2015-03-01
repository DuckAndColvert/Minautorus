#include<Tile.hpp>

#include<TextureLoader.hpp>
#include<assert.h>
#include<SFML/Graphics.hpp>
#include<Global.hpp>

using namespace sf;

Tile::Tile(double x, double y, string id, TextureLoader* te):
  Positionnable(x,y),
  m_id(id)
{
  assert(m_id!="" && te!=nullptr);
  m_currentTexture=te->get(m_id);
  assert(m_currentTexture);
  initShape();
}

Tile::Tile(double x, double y,short id, TextureLoader* te) :
// quick Conversion when creating the tile.
  Tile(x,y,TextureLoader::TILES_IDENTIFIER[id],te)
{
}

void Tile::initShape()
{
  m_shape=new RectangleShape(Vector2f(TILE_WIDTH,TILE_HEIGHT));
  m_shape->setTexture(m_currentTexture);
  m_shape->setPosition(getPosition());
}

void Tile::display(RenderWindow* w)  const
{
  assert(w && m_shape);
  w->draw(*m_shape);
}

Tile::~Tile()
{
  delete m_shape;
}
