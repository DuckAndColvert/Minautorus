#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Global.hpp>

enum TileType
  {
    NONE=0,
    GROUND=1,
    WALL = 2
  };

struct Tile
{
  size_t i;
  size_t j;
  
  TileType type;
  bool obstacle;
};

class Chunk;
class Core;

/**
 * \class Map
 * \brief Map generation and displaying
 * \author bog
 **/
class Map
{
  
public:
  Map(Core* owner);
  ~Map();

  /**
   * \fn void Map::display(sf::RenderWindow *win)
   * \brief Display the map on a RenderWindow 
   * \author bog
   **/
  void display(sf::RenderWindow *win);

  Tile* get(size_t i, size_t j);
  Core* getOwner();
  
  private:
  Core* m_owner;
  Tile* m_tiles[NB_TILE_HEIGHT][NB_TILE_WIDTH];
  std::vector<Chunk*> m_chunks;


  /**
   * \fn void Map::initTiles()
   * \brief Initialize the tiles of the map
   * \author bog
   **/
  void initTiles();

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
