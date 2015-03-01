#ifndef POSITIONNABLE_HPP
#define POSITIONNABLE_HPP

#include<SFML/System/Vector2.hpp>

using namespace sf;

class Positionnable
{
public:
  Positionnable(double x, double y);
  Positionnable(Vector2f v);

  // ==== GETTER ===
  Vector2f getPosition() const {return Vector2f(m_x,m_y);}
  double getPositionX() const {return m_x;}
  double getPositionY() const {return m_y;}
  // ==== SETTER ===
  void setPosition(Vector2f v) {m_x=v.x; m_y=v.y;}
  void setPosition(double x, double y) {m_x=x; m_y=y;}

  ~Positionnable();
protected:
  double m_x;
  double m_y;
};




#endif // POSITIONNABLE_HPP
