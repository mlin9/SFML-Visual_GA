#include <iostream>
#include "environment.h"

using namespace std;

//#include "environment.h"



int main()
{
	sf::RenderWindow window( sf::VideoMode( 500, 500 ), "Genetic Algorithm");
	Environment environment(&window);
	environment.start();
}
