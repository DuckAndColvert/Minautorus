#ifndef SCENE_HPP
#define SCENE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Core.hpp>

/**
 * \class Scene
 *
 * \brief Abstract class that describe a Scene
 *
 * As in theatre, a Scene is a place where some events
 * takes place. It could be a menu, a dialog scene in a game etc.
 *
 * \author bog
 *
 **/
class Scene
{
public:
  Scene(Core* owner);
  virtual ~Scene();

  virtual void update(float dt) = 0;
  virtual void display(sf::RenderWindow *win) = 0;
  
protected:
  Core *m_owner;
  
private:
  Scene& operator=(Scene const& s) = delete;
  Scene(Scene const& s) = delete;
};

#endif
