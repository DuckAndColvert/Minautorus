#ifndef SCENE_H
#define SCENE_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
class Core;

class Scene
{
public:
  Scene(Core* c);
  ~Scene();

  void update(int dt);
  void display(RenderWindow* w);


protected:
    Core *m_core;
};

#endif
