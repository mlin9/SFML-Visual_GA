#include "environment.h"

//Constructor
Environment::Environment(sf::RenderWindow *window)
{
	screen = window;
}

//Primer
void Environment::start()
{
	mainLoop();
}

//Main Function Loop
void Environment::mainLoop()
{
	GeneticImage genetic_image(screen, true, "spoiler.png");
	GeneticImage genetic_image2(screen, true, "spoilertiny.png");
	
	genetic_image2.set_position(0,6);
	
	sf::View view(sf::Vector2f(5.5, 5.5), sf::Vector2f(300, 300));
	view.zoom(0.04);
	
	sf::Image image_input;
	sf::Texture image_texture;
	sf::Sprite image_sprite;
	image_input.loadFromFile("spoiler.png");
	image_texture.loadFromImage(image_input);
	image_sprite.setTexture(image_texture);
	image_sprite.setPosition(6, 0);
	
	sf::Image image_input2;
	sf::Texture image_texture2;
	sf::Sprite image_sprite2;
	image_input2.loadFromFile("spoilertiny.png");
	image_texture2.loadFromImage(image_input2);
	image_sprite2.setTexture(image_texture2);
	image_sprite2.setPosition(6, 6);
	
	
	screen->setView(view);
	
	while(screen->isOpen())
	{
		//Refresh Rendering Window
		init();
	
		//Handle Events
		sf::Event event;
		while(screen -> pollEvent(event))
		{
			switch(event.type)
			{
				case sf::Event::Closed:
					screen->close();
					break;
					
				//Handle Keys (Pressed)
				case sf::Event::KeyPressed:
					
					switch(event.key.code)
					{	
						case sf::Keyboard::Escape:
							screen->close();
							break;
						case sf::Keyboard::Space:
							break;
						default:
							break;
					}
					break;
					
				default:
					break;
				
				//Handle Keys (Released)
				case sf::Event::KeyReleased:
					
					switch(event.key.code)
					{
						default:
							break;
					}
					break;
			}
		}
		
		//Render Objects
		genetic_image.update();
		genetic_image.draw();
		genetic_image2.update();
		genetic_image2.draw();
		screen->draw(image_sprite);
		screen->draw(image_sprite2);
		screen->display();
		screen->setFramerateLimit(60);
	}
}

//Clear Rendering
void Environment::init()
{
	screen->clear();
}
