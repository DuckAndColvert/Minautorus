#include <InGame.hpp>

#include<TextureLoader.hpp>
#include<Tile.hpp>
#include<assert.h>
#include<Global.hpp>
#include<Player.hpp>

InGame::InGame(Core *c, TextureLoader* textLoad): Scene(c)
{
  initTiles(textLoad);
  initCharacters(textLoad);
}

void InGame::initTiles(TextureLoader* te)
// Initialize the tiles and their graphisms
// To do with the maze algoritm
{
  assert(te);
  for(size_t i(0);i<10;++i)
    {
      for(size_t j(0);j<10;++j)
	{
	  short randomInt= rand()%1+1;
	  m_tiles.push_back(new Tile(j*TILE_WIDTH,i*TILE_HEIGHT,randomInt,te));
	}
    }
}

void InGame::initCharacters(TextureLoader* te)
{
  m_tiles.push_back(new Player(0,0,"Player",te));
}

void InGame::update(int dt)
{
  for(Tile* t:m_tiles)
    {
      assert(t);
      t->update(dt);
    }
}

void InGame::display(RenderWindow *w)
{
  displayTiles(w);
}

void InGame::displayTiles(RenderWindow* w) const
{
  for(Tile* t:m_tiles)
    {
      assert(t);
      t->display(w);
    }
}

InGame::~InGame()
{
  for(auto t: m_tiles){delete t;}
  m_tiles.clear();
}
