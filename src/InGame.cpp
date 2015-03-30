#include <InGame.hpp>
#include <Character.hpp>
#include <TextureManager.hpp>

InGame::InGame(Core *owner, sf::RenderWindow *win): Scene(owner, win)
{
  m_view.reset(sf::FloatRect(0,0,SCREEN_WIDTH, SCREEN_HEIGHT));
  //m_view.reset(sf::FloatRect(0,0,WIDTH, HEIGHT));

  m_map = new Map(m_owner);
  m_window->setView(m_view);
  
}

void InGame::update(float dt)
{
  // TODO: keyboard manager here
  int speed = 5;
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad8) )
    {
      m_view.move(sf::Vector2f(0,-speed));
    }
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad5) )
    {
      m_view.move(sf::Vector2f(0,speed));
    }
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4) )
    {
      m_view.move(sf::Vector2f(-speed,0));
    }
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6) )
    {
      m_view.move(sf::Vector2f(speed,0));
    }
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad7) )
    {
      m_view.zoom(1.02);
    }
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad9) )
    {
      m_view.zoom(0.98);
    }

}

void InGame::display()
{
  m_window->setView(m_view);
  m_map->display(m_window);
}

InGame::~InGame()
{
  delete m_map;
}
