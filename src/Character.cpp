#include <Character.hpp>
#include <Map.hpp>
#include <TextureManager.hpp>

Character::Character(Map *map, sf::Texture* spritesheet): m_map(map),
							  m_spritesheet(spritesheet)
{
  m_sprite = sf::Sprite();
  m_sprite.setTexture(*m_spritesheet);

  m_velocity = sf::Vector2f(TILE_WIDTH*4,TILE_WIDTH*4);
  m_movement = sf::Vector2f(0,0);
}

sf::Vector2f Character::getPosition()
{
  return m_sprite.getPosition();
}

sf::Vector2f Character::getVelocity()
{
  return m_velocity;
}

sf::FloatRect Character::getLocalBounds()
{
  return m_sprite.getLocalBounds();
}

void Character::update(float dt)
{
  /* map coordinate */
  m_map_i = m_sprite.getPosition().y/TILE_HEIGHT;
  m_map_j = m_sprite.getPosition().x/TILE_WIDTH;

  /* movement */
  
  //next position
  float moveX = (m_movement.x*dt)/1000000.0;
  float moveY = (m_movement.y*dt)/1000000.0;
    
  sf::Vector2f next;
  next.x = m_sprite.getPosition().x + moveX;
  next.y = m_sprite.getPosition().y + moveY;
  
  //check X collisions
  if( !collideWithMap( sf::Vector2f(next.x, next.y-moveY) ) )
    {
      m_sprite.move(moveX, 0);
    }
  
  //check Y collisions
  if( !collideWithMap( sf::Vector2f(next.x - moveX,next.y) ) )
    {
      m_sprite.move(0, moveY);
    }

}

void Character::moveUp()
{
  m_movement.y = -m_velocity.y;
}

void Character::moveDown()
{
  m_movement.y = m_velocity.y;
}

void Character::moveLeft()
{
  m_movement.x = -m_velocity.x;
}

void Character::moveRight()
{
  m_movement.x = m_velocity.x;
}

void Character::stopX()
{
  m_movement.x = 0;
}

void Character::stopY()
{
  m_movement.y = 0;
}

bool Character::collideWithMap(sf::Vector2f const& pos)
{
  ssize_t pos_i = (pos.y)/TILE_HEIGHT;
  ssize_t pos_j = (pos.x)/TILE_WIDTH;

  for( ssize_t i = pos_i-1; i <= pos_i+1; i++ )
    {
      for( ssize_t j = pos_j-1; j <= pos_j+1; j++ )
	{
	  if( m_map->exists(i, j) )
	    {
	      if( collideWithTile(pos, m_map->get(i, j))
		&& m_map->get(i, j)->obstacle )
		{
		  return true;
		}
	    }
	}
    }

  return false;
}

bool Character::collideWithTile(sf::Vector2f const& pos, Tile const* tile)
{
  float tx = (tile->j)*TILE_WIDTH;
  float ty = (tile->i)*TILE_HEIGHT;

  float x = pos.x;
  float y = pos.y;
  float w = m_sprite.getLocalBounds().width;
  float h = m_sprite.getLocalBounds().height;

  //for avoid feeling
  //of not touching the wall (less than 1px)
  float margin = 1;
  
  if( ty + TILE_HEIGHT - margin < y || ty + margin > y + h
      || tx + TILE_WIDTH - margin < x || tx + margin > x + w )
    {
      return false;
    }


  return true;
}

void Character::display(sf::RenderWindow *win)
{
  win->draw(m_sprite);
}

Character::~Character()
{
  
}
