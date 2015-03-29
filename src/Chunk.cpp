#include <Chunk.hpp>

Chunk::Chunk(size_t x, size_t y, size_t w, size_t h): m_x(x), m_y(y),
						      m_w(w), m_h(h)
{
  m_vertex_array = new sf::VertexArray();
}



Chunk::~Chunk()
{
  delete m_vertex_array;
}
