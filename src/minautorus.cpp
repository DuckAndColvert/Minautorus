#include <iostream>
#include <SFML/Graphics.hpp>
#include <Core.hpp>
using namespace std;
using namespace sf;


int main(int argc, char** argv)
{
  /* MINAUTORUS */
  cout<<"MINAUTORUS"<<endl;

  RenderWindow window(VideoMode(640,480),"Minautorus");

  Core core(&window);
  core.render();
  
  
  return 0;
}
