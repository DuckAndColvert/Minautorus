#include <TextureManager.hpp>
#include <cassert>

TextureManager::TextureManager()
{

}


sf::Texture* TextureManager::get(std::string name)
{
  return m_textures[name];
}


void TextureManager::load()
{
  std::string data_path = DATA_PATH;
  std::string img_path = data_path + IMG_PATH;

  /* textures loading */
  load("error",img_path + "error.png");
  load("ground", img_path + "ground.png");
  load("tileset", img_path + "tileset.png");
  /**********************************/
}


void TextureManager::load(std::string name, std::string path)
{
  sf::Texture *new_texture = new sf::Texture;
  new_texture->loadFromFile(path);

  m_textures[name] = new_texture;
}

TextureManager::~TextureManager()
{
  std::unordered_map<std::string, sf::Texture*>::iterator it;
  for( it = m_textures.begin(); it != m_textures.end(); it++ )
    {
      delete (*it).second;
      m_textures.erase(it);
    }
  m_textures.clear();
    
}
