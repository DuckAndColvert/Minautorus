#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include <iostream>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <Global.hpp>

/**
 * \class TextureManager
 *
 * \brief Texture loader
 *
 * Load and give an access to all the texture required by the other moduels of the game.
 *
 * \author bog
 **/
class TextureManager
{
public:
  TextureManager();
  ~TextureManager();
  
  sf::Texture* get(std::string name);

  /**
   * \fn void load()
   * \brief Load all the textures  required by the game
   * \author bog
   **/
  void load();
  
private:
  TextureManager& operator=(TextureManager const& tm) = delete;
  TextureManager(TextureManager const& tm) = delete;

  /**
   * \fn void load(std::string name, std::string path)
   * \brief load a texture and ad it in the map
   * 
   * \param path path to the texture
   * \param name given to the texture
   * Load a texture designed by its path, and add it in the map at the key given by
   * the name.
   **/
  void load(std::string name, std::string path);
  
  std::unordered_map<std::string,sf::Texture*> m_textures;
  
};

#endif
