#ifndef INGAME_H
#define INGAME_H
#include <Scene.hpp>
#include <vector>

using namespace sf;
using namespace std;

class TextureLoader;
class Tile;

class InGame: public Scene
{
public:

  InGame(Core *c, TextureLoader* textLoad);
  ~InGame();
  void update(int dt);
  void display(RenderWindow *w);

protected:
  void initTiles(TextureLoader* te);
  vector<Tile*> m_tiles;
};


#endif
