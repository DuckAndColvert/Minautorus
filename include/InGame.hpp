#ifndef IN_GAME_HPP
#define IN_GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Global.hpp>
#include <Scene.hpp>
#include <Map.hpp>

class Map;

class InGame: public Scene
{
public:
  InGame(Core *owner);
  ~InGame();

  virtual void update(float dt);
  virtual void display(sf::RenderWindow *win);
  
private:
  InGame& operator=(InGame const& ig) = delete;
  InGame(InGame const& ig) = delete;

  Map m_map;
};

#endif
