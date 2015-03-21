#include <InGame.hpp>

InGame::InGame(Core *owner, sf::RenderWindow *win): Scene(owner, win)
{
  m_view.reset(sf::FloatRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT));
  m_window->setView(m_view);
}

void InGame::update(float dt)
{
  
}

void InGame::display()
{
  
  m_map.display(m_window);
}

InGame::~InGame()
{
  
}
