#include <iostream>
#include <Core.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;
using namespace std;

int main(int argc, char *argv[])
{
  srand(time(NULL));
  RenderWindow window(VideoMode(800,600),"MINAUTORUS");

  Core core(&window);
  core.run();
  return 0;
}
