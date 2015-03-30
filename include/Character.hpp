/* Character */
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <SFML/Graphics.hpp>


/**
 * \class Character
 * \brief A Character is a moving actor of the game
 * which make some actions in the maze.
 * \author bog
 **/
class Character
{
public:
  Character();
  virtual ~Character();

  virtual void update(float dt) = 0;
  virtual void display(sf::RenderWindow *win) = 0;
  
protected:
 sf::Sprite m_sprite;
private:
  Character( Character const& character ) = delete;
  Character& operator=( Character const& character ) = delete;
  

};

#endif
