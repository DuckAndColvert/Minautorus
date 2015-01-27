#include <Core.hpp>
#include <Scene.hpp>
#include <InGame.hpp>

Core::Core(RenderWindow *w): m_window(w)
{
  m_current_scene = new InGame(this);
}

void Core::update(int dt)
{
  if(m_current_scene)
    {
      m_current_scene->update(dt);
    }
}

void Core::display()
{
  if(m_current_scene)
    {
      m_current_scene->display(m_window);
    }
}


void Core::run()
{
  Event event;

  while(m_window->isOpen())
    {
      while(m_window->pollEvent(event))
	{
	  switch(event.type)
	    {
	    case Event::Closed:
	      m_window->close();
	      break;

	    case Event::KeyPressed:
	      switch(event.key.code)
		{
		case Keyboard::Escape:
		  m_window->close();
		  break;

		default:
		  break;
		}
	      break;

	    default:
	      break;

	    }
	}
      m_window->clear(Color(4,139,154));
      update(0);
      display();
      m_window->display();

    }
  
}

Core::~Core()
{
  delete m_current_scene;
}
