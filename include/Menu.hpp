
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Scene.hpp>
#include <Core.hpp>

class Menu: public Scene
{
  
public:
  Menu(Core *owner);
  void update(float dt);
  void display(sf::RenderWindow *win);
  ~Menu();
  
private:
  Menu& operator=(Menu const& m) = delete;
  Menu(Menu const& m) = delete;
};


#endif
