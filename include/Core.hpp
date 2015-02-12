#ifndef CORE_H
#define CORE_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Scene;
class TextureLoader;

class Core
{
public:
  Core(RenderWindow *w);
  ~Core();

  void run();

private:
  void update(int dt);
  void display();
  void load();

  RenderWindow *m_window;
  double m_dt;
  Clock m_clock;
  Scene *m_current_scene;
  TextureLoader* m_textureLoader;
};

#endif
