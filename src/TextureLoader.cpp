#include<TextureLoader.hpp>

#include<assert.h>
#include<iostream>

unordered_map<short,string> TextureLoader::TILES_IDENTIFIER =
  {
    {0,"error"},
    {1,"ground"}
  };


TextureLoader::TextureLoader()
{
  m_textures.clear(); //empty
  assert(load());
}

const Texture* TextureLoader::get(string key) 
// Main method of a Loader, let us get the textures loaded in the load() method.
{
  Texture* t=m_textures[key];
  if(!t)
    {
      return m_textures["error"];
    }
  return t;
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
     !loadTiles()
     ){return false;}
  if(TEXTURE_DEBUG_DETAILS){cout << " ------ END  \n";}
  return true;
}

bool TextureLoader::loadTiles()
{
  for(size_t i(0);i<TILES_IDENTIFIER.size();++i)
    {
      if(!loadPNG(TILES_IDENTIFIER[i])){return false;} // /!\ Load only the first 32x32 tile of tile.png YANGN-more :p
    }
  return true;
}

bool TextureLoader::loadPNG(string file, size_t nb_x, size_t nb_y, size_t tile_width, size_t tile_height)
//   Load a file (basicly a PNG one). Requires the path to join the file, the number of tile to load horizontally, vertically and its size.
{
  Texture* t=new Texture();
  for(size_t i(0);i<nb_y;++i)
    {
      for(size_t j(0);j<nb_x;++j)
	{
	  string fullPath=TO_DATA+"img/"+file+".png";
	  if(!t->loadFromFile(fullPath.c_str(),IntRect(j*tile_width,i*tile_height,tile_width,tile_height)) && TEXTURE_DEBUG){cerr<<"[TextureLoader::loadPNG] There was a problem loading the : " << file << " texture. \n"; return false;}
	  else
	    {
	      string key=file;
	      //if the file contains more than one texture, they will be names with index j (sol, sol1, sol2)
	      if(j!=0){key+=to_string(j);} 
	      if(t!=nullptr)
		{
		  m_textures.insert(pair<string,Texture*>(key,t));
		  if(TEXTURE_DEBUG_DETAILS)
		    {
		      cout << " Added texture : " << key << " from : " << fullPath << endl;
		    }
		}
	    }
	}
    }
  return true; // We loaded the png file;
}

void const TextureLoader::display()
{
  cout << " ==== TextureLoader elements == nb_element:" << m_textures.size() << "===== " << endl;
  for(auto a:m_textures){cout << " Key : " << a.first << endl;}
}
  
TextureLoader::~TextureLoader()
{
  for(auto a: m_textures){delete a.second;}
}
