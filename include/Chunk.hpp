/* Chunk */
#ifndef CHUNK_HPP
#define CHUNK_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

class Chunk
{
public:
  Chunk(size_t x, size_t y, size_t w, size_t h);
  virtual ~Chunk();
  
protected:
  
private:
  Chunk( Chunk const& chunk ) = delete;
  Chunk& operator=( Chunk const& chunk ) = delete;
  
  sf::VertexArray *m_vertex_array;
  
  const size_t m_x;
  const size_t m_y;
  const size_t m_w;
  const size_t m_h;
};
  
#endif
