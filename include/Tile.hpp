#ifndef TILE_HPP
#define TILE_HPP

#include<string>

using namespace std;

class Tile
{
public:
  Tile(string id="error");
  Tile(short id=-1);
  // ==== GETTER ===
  string getID() const {return m_id;}

  virtual ~Tile();

protected:
  string m_id;
  
};

#endif // TILE_HPP
