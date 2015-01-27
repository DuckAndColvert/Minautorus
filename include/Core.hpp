#ifndef CORE_H
#define CORE_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Core
{
public:
  Core(RenderWindow *w);
  ~Core();

  void update(int dt);
  void display();
  void run();

private:
  RenderWindow *m_window;
};

#endif
