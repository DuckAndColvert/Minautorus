#include <Character.hpp>
#include <Map.hpp>
#include <TextureManager.hpp>

Character::Character(Map *map, sf::Texture* spritesheet): m_map(map),
							  m_spritesheet(spritesheet)
							  
{
  m_sprite = sf::Sprite();

  m_sprite.setTexture(*m_spritesheet);
}

void Character::update(float dt)
{
}

void Character::display(sf::RenderWindow *win)
{
  win->draw(m_sprite);
}

Character::~Character()
{
  
}
