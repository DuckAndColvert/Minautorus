#ifndef TILE_HPP
#define TILE_HPP

#include<string>
#include<SFML/Graphics.hpp>
#include<Positionnable.hpp>

using namespace std;

class TextureLoader;


class Tile : public Positionnable
{
public:
  Tile(double x, double y,string id,TextureLoader* te);
  Tile(double x, double y, short id, TextureLoader* te);

  void display(sf::RenderWindow* w) const;
  virtual void update(double dt);

  // ==== GETTER ===
  string getID() const {return m_id;}

  virtual ~Tile();

protected:
  void initShape();

  string m_id;
  sf::Texture* m_currentTexture;
  sf::RectangleShape* m_shape;
};

#endif // TILE_HPP
