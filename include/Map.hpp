#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Global.hpp>

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


class Map
{
  
public:
  Map();
  ~Map();

  void display(sf::RenderWindow *win);
  
private:
  Tile* m_tiles[NB_TILE_HEIGHT][NB_TILE_WIDTH];
  void initTiles();

  sf::VertexArray m_vertex_array;
  void createVertexTile(size_t i, size_t j,size_t w,size_t h, sf::Color color); 
  
};

#endif
