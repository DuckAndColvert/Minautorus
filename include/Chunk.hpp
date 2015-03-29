/* Chunk */
#ifndef CHUNK_HPP
#define CHUNK_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Global.hpp>

/**
 * \class Chunk
 * \brief area of the game to update/display
 * \author bog
 **/
class Map;
class Tile;

class Chunk
{
public:
  Chunk(Map* map,size_t i, size_t j);
  virtual ~Chunk();

  void draw(sf::RenderWindow *win);
protected:
  
private:
  Chunk( Chunk const& chunk ) = delete;
  Chunk& operator=( Chunk const& chunk ) = delete;
  
  /**
   * \fn   void Chunk::initTiles()
   * \brief init the tiles of the chunk with map tiles
   * \author
   **/
  void initTiles();
  
  /**
   * \fn void Chunk::createVertexTile(size_t i, size_t j,size_t w,size_t h, sf::Color color)
   * \brief Create a vertex in the  vertex array
   * \param i the coordinate of the vertex to create (line)
   * \param j the coordinate of the vertex to create (column)
   * \param w the width  of the vertex to create
   * \param h the height of the vertex to create
   * \param color color of the vertex to create
   * \author bog
   **/
  void createVertexTile(size_t i, size_t j,size_t w,size_t h, sf::Color color);

  /**
   * \fn   void Chunk::createVertexTile(sf::VertexArray &va, Tile *tile);
   * \brief Create a vertex related with a tile
   * \param tile 
   * \author bog
   **/
  void createVertexTile(Tile *tile);

  sf::VertexArray m_vertex_array;
  Map *m_map;
  Tile* m_tiles[CHUNK_HEIGHT][CHUNK_WIDTH];
  const size_t m_i;
  const size_t m_j;
};
  
#endif
