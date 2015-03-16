#include <iostream>
#include <Core.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;
  srand(time(NULL));
  RenderWindow window(VideoMode(800,600),"MINAUTORUS");

  Core core(&window);
  core.run();

  return 0;
}
