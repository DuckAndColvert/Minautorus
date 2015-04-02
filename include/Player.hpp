/* Player */
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Character.hpp>

class Map;
class Tile;

class Player: public Character
{
public:
  Player(Map *map, sf::Texture* spritesheet);
  virtual ~Player();

  virtual void display(sf::RenderWindow *win);
  virtual void update(float dt);
  
protected:
  
private:
  Player( Player const& player ) = delete;
  Player& operator=( Player const& player ) = delete;
  
  
};

#endif
