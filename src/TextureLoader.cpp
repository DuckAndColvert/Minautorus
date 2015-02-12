#include<TextureLoader.hpp>

#include<assert.h>
#include<iostream>

TextureLoader::TextureLoader()
{
  m_textures.clear(); //empty
assert(load());
}

const Texture* TextureLoader::get(string key) 
// Main method of a Loader, let us get the textures loaded in the load() method.
{
  return m_textures[key];
}

bool TextureLoader::load()
// We write here the textures we want to load, and it loads it with the loadPNG() method.
{
// First we empty the textures (in case of double load)
for(auto t: m_textures){delete t.second;}
m_textures.clear();
if(TEXTURE_DEBUG_DETAILS){cout << " ======== TEXTURE_LOADING ======  \n";}
  // Insert the textures to load
 if(
// || loadPNG(file,nb,nb) // cette forme là.
    !loadPNG(TO_DATA+"img/sol.png",1,1)
|| false
){return false;}
if(TEXTURE_DEBUG_DETAILS){cout << " ------ END  \n";}
return true;
}

bool TextureLoader::loadPNG(string path, size_t nb_x, size_t nb_y, size_t tile_width, size_t tile_height)
//   Load a file (basicly a PNG one). Requires the path to join the file, the number of tile to load horizontally, vertically and its size.
{
  Texture* t=new Texture();
  for(size_t i(0);i<nb_y;++i)
    {
      for(size_t j(0);j<nb_x;++j)
	{
if(!t->loadFromFile(path.c_str(),IntRect(j*tile_width,i*tile_height,tile_width,tile_height)) && TEXTURE_DEBUG){cerr<<"[TextureLoader::loadPNG] There was a problem loading the : " << path << " texture. \n"; return false;}
	  string key=path+to_string(j);
	  if(TEXTURE_DEBUG_DETAILS){cout << " Added texture from : " ;}
	  m_textures.insert(pair<string,Texture*>(key,t));
	}
    }
return true; // We load the png file;
}
  
