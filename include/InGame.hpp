#ifndef IN_GAME_HPP
#define IN_GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Global.hpp>
#include <Scene.hpp>
#include <Map.hpp>
#include <vector>

class Map;
class Character;
class Player;

class InGame: public Scene
{
public:
  InGame(Core *owner, sf::RenderWindow *win);
  ~InGame();

  virtual void update(float dt);
  virtual void display();
  
private:
  InGame& operator=(InGame const& ig) = delete;
  InGame(InGame const& ig) = delete;

  Map *m_map;

  sf::View m_view;
  int m_view_area;  
  int m_view_speed;
  
  std::vector<Character*> m_characters;
  Player *m_player;

};

#endif
