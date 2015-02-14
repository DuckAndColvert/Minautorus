#ifndef INGAME_H
#define INGAME_H
#include <SFML/Graphics.hpp>
#include <Scene.hpp>

using namespace sf;

class TextureLoader;

class InGame: public Scene
{
public:

  InGame(Core *c, TextureLoader* textLoad);
  ~InGame();
  void update(int dt);
  void display(RenderWindow *w);

protected:
};


#endif
