#include <Core.hpp>


using namespace std;

Core::Core(RenderWindow *w): m_window(w)
{
  // Avoiding dt=0;
  m_dt=1;
  m_clock.restart();
}

void Core::update(int dt)
{
 
}

void Core::display()
{
  cout << m_dt << endl;
}


void Core::run()
{
  Event event;

  while(m_window->isOpen())
    {
      // Dt
       m_clock.restart();

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
      update(m_dt);
      display();
      m_window->display();

      // dt
      m_dt=m_clock.restart().asMilliseconds();

    }
  
}

Core::~Core()
{
}
