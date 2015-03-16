#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include<Tile.hpp>
#include<SFML/Graphics/RenderWindow.hpp>

class Character : public Tile
{

public:
  Character(double x, double y, string id, TextureLoader* te);

  virtual void move(double x, double y)=0;
  virtual void display(sf::RenderWindow* w)=0 ;
  

  virtual ~Character();

protected:


};

#endif // CHARACTER_HPP
