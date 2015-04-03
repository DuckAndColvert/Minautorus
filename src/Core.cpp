#include <Core.hpp>
#include <Scene.hpp>
#include <Menu.hpp>
#include <InGame.hpp>
#include <TextureManager.hpp>

Core::Core(sf::RenderWindow *win): m_window(win), m_dt(1.)
{
  m_texture_manager = new TextureManager;
  m_texture_manager->load();
  
  m_currentScene = new InGame(this, m_window);
}

TextureManager* Core::getTextureManager()
{
  return m_texture_manager;
}

void Core::update(float dt)
{
  if( m_currentScene )
    {
      m_currentScene->update(dt);
    }
}

void Core::display()
{
  if( m_currentScene )
    {
      m_currentScene->display();
    }
}


void Core::render()
{
  sf::Event event;

  while( m_window->isOpen() )
    {
      //get the current time_point
      m_loopTimer = std::chrono::steady_clock::now();

      while( m_window->pollEvent(event) )
	{
	  switch(event.type)
	    {
	    case sf::Event::Closed:
	      m_window->close();
	      break;

	    case sf::Event::KeyPressed:
	      switch( event.key.code )
		{
		case sf::Keyboard::Escape:
		  m_window->close();
		  break;
		default:break;
		}
	      break;
	      
	    default:break;
	    }
	}
      
      update(m_dt);
      m_window->clear(sf::Color(4,139,154));
      display();
      m_window->display();

      //convert elapsed time in microseconds
      m_dt = std::chrono::duration_cast<std::chrono::microseconds>
	(std::chrono::steady_clock::now() - m_loopTimer).count();
      
    }
  
}

Core::~Core()
{
  if(m_currentScene)
    {
      delete m_currentScene;
    }
    delete m_texture_manager;
}
