#include <InGame.hpp>
#include <cmath>
#include <Character.hpp>
#include <Player.hpp>
#include <TextureManager.hpp>
#include <unordered_map>

InGame::InGame(Core *owner, sf::RenderWindow *win): Scene(owner, win), m_view_area(8), m_view_speed(2)//TODO: DEPEND TO PLAYER SPEED
{
  m_view.reset(sf::FloatRect(0,0,SCREEN_WIDTH, SCREEN_HEIGHT));
  
  m_map = new Map(m_owner->getTextureManager()->get("tileset"));
  m_window->setView(m_view);
  
  m_player = new Player(m_map, m_owner->getTextureManager()->get("error"));
  m_characters.push_back( m_player );

}

void InGame::update(float dt)
{
  /* characters */
  for(Character* c:m_characters)
    {
      c->update(dt);
    }
  
  /* view */
  sf::Vector2f view_move(0,0);

  //set the view movement
  if( m_player->getPosition().x - m_view.getCenter().x > m_view_area )
    {
      view_move.x = m_view_speed;
    }
  else if(m_view.getCenter().x - m_player->getPosition().x > m_view_area )
    {
      view_move.x = -m_view_speed;
    }
  
  if( m_player->getPosition().y - m_view.getCenter().y > m_view_area )
    {
      view_move.y = m_view_speed;
    }
  else if(m_view.getCenter().y - m_player->getPosition().y > m_view_area )
    {
      view_move.y = -m_view_speed;
    }

  //check the view does't get out of the map
  if( m_view.getCenter().x + view_move.x < m_view.getSize().x/2
      || m_view.getCenter().x + view_move.x > WIDTH - m_view.getSize().x/2 )
    {
      view_move.x = 0;
    }
  
  if( m_view.getCenter().y + view_move.y < m_view.getSize().y/2
      || m_view.getCenter().y + view_move.y > HEIGHT - m_view.getSize().y/2 )
    {
      view_move.y = 0;
    }
  
  m_view.move(view_move);

  /* event */
  
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

  for(Character* c: m_characters)
    {
      c->display(m_window);
    }
}

InGame::~InGame()
{
  delete m_map;

  for(Character* c: m_characters)
    {
      delete c;
    }
  
}
