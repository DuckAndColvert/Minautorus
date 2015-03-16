#include<Player.hpp>

#include<SFML/Window/Keyboard.hpp>
#include<assert.h>
#include<iostream>

using namespace sf;
using namespace std;

Player::Player(double x, double y, string id, TextureLoader* te) :
  Character(x,y,id,te)
{
  
}

void Player::move(double x, double y)
{
  m_x+=x;
  m_y+=y;
  assert(m_shape);
  m_shape->setPosition(getPosition());
}

void Player::update(double dt)
{
  if(Keyboard::isKeyPressed(Keyboard::Up)){move(0,-1);}
  if(Keyboard::isKeyPressed(Keyboard::Down)){move(0,1);}
  if(Keyboard::isKeyPressed(Keyboard::Left)){move(-1,0);}
  if(Keyboard::isKeyPressed(Keyboard::Right)){move(1,0);}
}

void Player::display(RenderWindow* w)
{
  assert(w && m_shape);
  w->draw(*m_shape);
}

Player::~Player()
{

}
