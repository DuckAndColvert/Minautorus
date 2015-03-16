#include <TextureManager.hpp>

TextureManager::TextureManager()
{
}


sf::Texture* TextureManager::get(std::string name)
{
  return m_textures[name];
}

void TextureManager::load(std::string name, std::string path)
{
  sf::Texture *new_texture = new sf::Texture;
  new_texture->loadFromFile(path);

  m_textures[name] = new_texture;
}

TextureManager::~TextureManager()
{
  m_textures.clear();
}
