#ifndef PLAYER_HPP
#define PLAYER_HPP

#include<Character.hpp>

class TextureLoader;

class Player : public Character
{
public:

  Player(double x, double y, string id, TextureLoader* te);
  void move(double x, double y);
  void update(double dt);
  void display(sf::RenderWindow* w);

  virtual ~Player();
protected:



};

#endif // PLAYER_HPP
