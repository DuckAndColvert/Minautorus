#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Global.hpp>

enum TileType
  {
    NONE,
    GROUND,
    WALL_UP,
    WALL_DOWN,
    WALL_LEFT,
    WALL_RIGHT,
  };

struct Tile
{
  size_t i;
  size_t j;
  
  TileType type;
  bool obstacle;
};

/**
 * \class Map
 * \brief Map generation and displaying
 * \author bog
 **/
class Map
{
  
public:
  Map();
  ~Map();

  /**
   * \fn void Map::display(sf::RenderWindow *win)
   * \brief Display the map on a RenderWindow 
   * \author bog
   **/
  void display(sf::RenderWindow *win);
  void update(sf::View const& view);
  
  private:
  Tile* m_tiles[NB_TILE_HEIGHT][NB_TILE_WIDTH];
  sf::VertexArray m_vertex_array;
  sf::VertexArray m_visible_vertex_array;

  /**
   * \fn void Map::initTiles()
   * \brief Initialize the tiles of the map
   * \author bog
   **/
  void initTiles();
  
  /**
   * \fn void Map::createVertexTile(sf::VertexArray &va,size_t i, size_t j,size_t w,size_t h, sf::Color color)
   * \brief Create a vertex in the  vertex array
   *
   * \param va VertexArray in which tile is created
   * \param i the coordinate of the vertex to create (line)
   * \param j the coordinate of the vertex to create (column)
   * \param w the width  of the vertex to create
   * \param h the height of the vertex to create
   * \param color color of the vertex to create
   *
   * \author bog
   **/
  void createVertexTile(sf::VertexArray &va, size_t i, size_t j,size_t w,size_t h, sf::Color color);

  /**
   * \fn   void Map::createVertexTile(sf::VertexArray &va, Tile *tile);
   * \brief Create a vertex related with a tile
   * \param va VertexArray in which tile is created
   * \param tile 
   * \author bog
   **/
  void createVertexTile(sf::VertexArray &va, Tile *tile);

  /**
   * \fn void Map::putBloc(size_t I, size_t J, size_t W, size_t H)
   * \brief put a W*H at the position I J
   * \param I i coordinate of the bloc
   * \param J j coordinate of the bloc
   * \param W width of the bloc
   * \param H width of the bloc
   * \param border array containing the state of the borders
   * \author bog
   **/
  void putBloc(size_t I, size_t J, size_t W, size_t H, bool border[4]);

  /**
   * \fn void Map::placeMaze(size_t I, size_t J, size_t W, size_t H)
   * \brief Set a maze at the coordinate (I, J)
   * \param I i coordinate of the maze
   * \param J j coordinate of the maze
   * \param W width of the maze
   * \param H width of the maze
   * \author bog
   **/
  void placeMaze(size_t I, size_t J, size_t W, size_t H);

  /**
   * \fn   bool Map::isAWall(size_t i, size_t j)
   * \brief True if the tile at (i,j) is a wall
   * \param i i coordinate of the tile
   * \param j j coordinate of the tile
   * \return true if the tile (i,j) type is WALL_XXX
   * \author bog
   **/
  bool isAWall(size_t i, size_t j);

  /**
   * \fn   bool Map::isInTheScreen(Tile const& t)
   * \brief Look at a Tile and say if it is int the visible area of the map
   * \param t the tile to look at
   * \return True if the tile is on the visible area of the map
   * \author bog
   **/
  bool isInTheScreen(Tile const* t);

};

#endif
