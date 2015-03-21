
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Scene.hpp>
#include <Core.hpp>

/**
 * \class Menu
 *
 * \brief Menu of the Game
 *
 * Scene where the player can choose between different game mode
 * basically he can choose PLAY - SETTINGS or QUIT
 *
 * \author bog
 *
 **/
class Menu: public Scene
{
  
public:
  Menu(Core *owner, sf::RenderWindow *win);
  void update(float dt);
  void display();
  ~Menu();
  
private:
  Menu& operator=(Menu const& m) = delete;
  Menu(Menu const& m) = delete;
};


#endif
