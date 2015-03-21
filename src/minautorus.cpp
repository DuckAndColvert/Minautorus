#include <iostream>
#include <SFML/Graphics.hpp>
#include <Core.hpp>
#include <Global.hpp>
using namespace std;
using namespace sf;


int main(int argc, char** argv)
{
  /* MINAUTORUS */
  cout<<"MINAUTORUS"<<endl;
  RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),"Minautorus");

  Core core(&window);
  core.render();
  
  
  return 0;
}
