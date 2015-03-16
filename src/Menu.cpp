#include <Menu.hpp>
#include <TextureManager.hpp>

Menu::Menu(Core* owner): Scene(owner)
{
  
}

void Menu::update(float dt)
{
}

void Menu::display(sf::RenderWindow *win)
{
  sf::RectangleShape rs;
  rs.setTexture(m_owner->getTextureManager()->get("error"));
  rs.setSize(sf::Vector2f(200,200));

  win->draw(rs);
  
}

Menu::~Menu()
{
}
