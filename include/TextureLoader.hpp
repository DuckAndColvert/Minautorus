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
  Texture* get(string key); //should it be constant ?
  bool load();
  static unordered_map<short,string> TILES_IDENTIFIER; // Should it be constant ?

~TextureLoader();
  

private:
  bool loadTiles();
  bool loadPNG(string file, size_t nb_x=1, size_t nb_y=1, size_t tile_width=TILE_WIDTH, size_t tile_height=TILE_HEIGHT);
  void const display();

  unordered_map<string,Texture*> m_textures;
};

#endif // TEXTURELOADER_H
