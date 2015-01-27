#include <InGame.hpp>

InGame::InGame(Core *c): Scene(c)
{
  m_rs = new RectangleShape(Vector2f(100,100));
  m_rs->setFillColor(Color::Black);
}

void InGame::update(int dt)
{
}

void InGame::display(RenderWindow *w)
{
  w->draw(*m_rs);
}

InGame::~InGame()
{
  delete m_rs;
}
