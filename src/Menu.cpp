#include <Menu.hpp>
#include <TextureManager.hpp>

Menu::Menu(Core* owner, sf::RenderWindow *win): Scene(owner, win)
{
  
}

void Menu::update(float dt)
{
}

void Menu::display()
{
  sf::RectangleShape rs;
  rs.setTexture(m_owner->getTextureManager()->get("error"));
  rs.setSize(sf::Vector2f(200,200));

  m_window->draw(rs);
  
}

Menu::~Menu()
{
}
