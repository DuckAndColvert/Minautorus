/* Character */
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

class Map;
class Tile;

/**
 * \class Character
 * \brief A Character is a moving actor of the game
 * which make some actions in the maze.
 * \author bog
 **/
class Character
{
public:
  Character(Map *map, sf::Texture* spritesheet);
  virtual ~Character();

  virtual void update(float dt);
  virtual void display(sf::RenderWindow *win);

  virtual bool collideWithMap(sf::Vector2f const& pos);
  virtual bool collideWithTile(sf::Vector2f const& pos, Tile const* tile);

  virtual void moveUp();
  virtual void moveDown();
  virtual void moveLeft();
  virtual void moveRight();

  virtual void stopX();
  virtual void stopY();
  
protected:
  sf::Vector2f m_velocity;
  sf::Vector2f m_movement;
  
  Map* m_map;
  size_t m_map_i;
  size_t m_map_j;

  sf::Sprite m_sprite;
  sf::Texture *m_spritesheet;
  
private:
  Character( Character const& character ) = delete;
  Character& operator=( Character const& character ) = delete;
  

};

#endif
