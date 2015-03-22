#include <InGame.hpp>

InGame::InGame(Core *owner, sf::RenderWindow *win): Scene(owner, win)
{
  m_view.reset(sf::FloatRect(0,0,SCREEN_WIDTH, SCREEN_HEIGHT));
  m_window->setView(m_view);
}

void InGame::update(float dt)
{
  // TODO: keyboard manager here
  int speed = 5;
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
    {
      m_view.move(sf::Vector2f(0,-speed));
    }
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
    {
      m_view.move(sf::Vector2f(0,speed));
    }
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
    {
      m_view.move(sf::Vector2f(-speed,0));
    }
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
    {
      m_view.move(sf::Vector2f(speed,0));
    }

  m_map.update(m_view);
}

void InGame::display()
{
  m_window->setView(m_view);
  m_map.display(m_window);
}

InGame::~InGame()
{
  
}
