#ifndef IN_GAME_HPP
#define IN_GAME_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Global.hpp>
#include <Scene.hpp>

enum TileType
  {
    GROUND = 0,
    WALL = 0
  };

struct Tile
{
  size_t i;
  size_t j;

  TileType type;
  bool obstacle;
};

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

  
  Tile* m_tiles[NB_TILE_HEIGHT][NB_TILE_WIDTH];
  void initTiles();

  sf::VertexArray m_vertex_array;
  void createVertexTile(size_t i, size_t j,size_t w,size_t h, sf::Color color);
  
};

#endif
