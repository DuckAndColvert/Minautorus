#include<Positionnable.hpp>

Positionnable::Positionnable(double x, double y):
  m_x(x),
  m_y(y)
{
  
}

Positionnable::Positionnable(Vector2f v): 
  Positionnable(v.x,v.y)
{

}


Positionnable::~Positionnable()
{

}
