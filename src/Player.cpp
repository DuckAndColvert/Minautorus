#include <Player.hpp>
#include <Map.hpp>

Player::Player(Map *map, sf::Texture* spritesheet): Character(map,spritesheet)
{
  m_sprite.setPosition(sf::Vector2f(TILE_WIDTH,2*TILE_HEIGHT));
}


void Player::display(sf::RenderWindow* win)
{
  Character::display(win);
}


void Player::update(float dt)
{
  Character::update(dt);
  
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      moveUp();
    }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      moveDown();
    }
  else
    {
      stopY();
    }
  
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      moveLeft();
    }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      moveRight();
    }
  else
    {
      stopX();
    }

  
}


Player::~Player()
{
  
}
