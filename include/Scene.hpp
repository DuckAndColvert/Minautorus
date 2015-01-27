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

  virtual void update(int dt)=0;
  virtual void display(RenderWindow* w)=0;


protected:
    Core *m_core;
};

#endif
