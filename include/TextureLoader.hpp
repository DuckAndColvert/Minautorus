#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include<unordered_map>
#include<string> 
#include<SFML/Graphics.hpp> // textures
#include<Global.hpp> //  basic constant

using namespace std;
using namespace sf;

class TextureLoader
/**
   Loader assuming the loading of game's textures.
 **/
{
public:
  TextureLoader();
  const Texture* get(string key);
  bool load();
  ~TextureLoader();
  

private:
  bool loadPNG(string file, size_t nb_x, size_t nb_y, size_t tile_width=TILE_WIDTH, size_t tile_height=TILE_HEIGHT);
  void const display();

  unordered_map<string,Texture*> m_textures;
};

#endif // TEXTURELOADER_H
