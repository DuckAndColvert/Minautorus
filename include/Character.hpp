/* Character */
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

class Map;

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
  
protected:
  sf::Sprite m_sprite;
  Map* m_map;
  sf::Texture *m_spritesheet;
private:
  Character( Character const& character ) = delete;
  Character& operator=( Character const& character ) = delete;
  

};

#endif
