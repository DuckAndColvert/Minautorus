#include <InGame.hpp>

InGame::InGame(Core *owner): Scene(owner)
{
  
}

void InGame::update(float dt)
{
}

void InGame::display(sf::RenderWindow *win)
{
  m_map.display(win);
}

InGame::~InGame()
{
  
}
