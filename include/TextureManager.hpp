#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
  TextureManager();
  ~TextureManager();
  
private:
  TextureManager& operator=(TextureManager const& tm) = delete;
  TextureManager(TextureManager const& tm) = delete;

  //load a texture into the m_textures map
  sf::Texture* get(std::string name);
  void load(std::string name, std::string path);
  
  std::unordered_map<std::string,sf::Texture*> m_textures;
  
};

#endif
