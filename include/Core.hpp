#ifndef CORE_HPP
#define CORE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <chrono>


class Scene;
class TextureManager;
/**
 * \class Core
 *
 * \brief Core game management
 *
 * Main structure of the game, contain the differents
 * scene of the game.
 *
 * \author bog
 **/
class Core
{
public:
  Core(sf::RenderWindow *win);
  ~Core();

  TextureManager *getTextureManager(){return m_texture_manager;}
  
  void update(float dt);
  void display();

  /**
   * \fn void Core::render()
   * \brief Launch the main game loop 
   * \author bog
   **/ 
  void render();
  
private:
  Core(Core const& c) = delete;
  Core& operator=(Core const& c) = delete;

  TextureManager *m_texture_manager;
  sf::RenderWindow *m_window;
  Scene *m_currentScene;
  

  /* TIME */
  //chrono which take the m_dt
  std::chrono::steady_clock::time_point m_loopTimer;
  //duration of the main game loop in microseconds
  float m_dt;
  
};

#endif
