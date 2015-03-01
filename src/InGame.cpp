#include <InGame.hpp>

#include<TextureLoader.hpp>
#include<Tile.hpp>

InGame::InGame(Core *c, TextureLoader* textLoad): Scene(c)
{
  initTiles(textLoad);
}

void InGame::initTiles(TextureLoader* te)
// Initialize the tiles and their graphisms
// To do with the maze algoritm
{!
  for(size_t i(0);i<10;++i)
    {
      for(size_t j(0);j<10;++j)
	{
	  short randomInt= rand()%2;
	  m_tiles.push_back(new Tile(randomInt));
	}
    }
}

void InGame::update(int dt)
{

}

void InGame::display(RenderWindow *w)
{

}

InGame::~InGame()
{
  for(auto t: m_tiles){delete t;}
  m_tiles.clear();
}
