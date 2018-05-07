#include "geneticimage.h"

/* CONSTRUCTORS */
GeneticImage::GeneticImage(sf::RenderWindow *input_window, bool input_greyscale)
{
	screen = input_window;
	greyscale = input_greyscale;
	init();
}

GeneticImage::GeneticImage(sf::RenderWindow *input_window, bool input_greyscale, string filename)
{
	screen = input_window;
	assert(image.loadFromFile(filename));
	dimensions = image.getSize();
	greyscale = input_greyscale;
	init();
}
/* END CONSTRUCTORS */

/* PUBLIC FUNCTIONS */
void GeneticImage::set_image(string filename)
{
	assert(image.loadFromFile(filename));
	dimensions = image.getSize();
}

void GeneticImage::set_position(float x, float y)
{
	image_sprite.setPosition(x,y);
}

void GeneticImage::draw()
{
	image_texture.loadFromImage(image);
	image_sprite.setTexture(image_texture);
	screen->draw(image_sprite);
}

void GeneticImage::init()
{
	generation = 0;
	
	if(greyscale)
		nominal = parser.parse_image_greyscale(image);
	else
		nominal = parser.parse_image(image);
	/*
	current.init(STRING_ARRAY_SIZE, SHAPE_ARRAY_SIZE);
	buffer.init(STRING_ARRAY_SIZE, SHAPE_ARRAY_SIZE);
	*/
	current.init(dimensions.x, dimensions.y);
	buffer.init(dimensions.x, dimensions.y);
	
	if(greyscale)
		current.randomize_greyscale();
	else
		current.randomize();
}

void GeneticImage::update()
{
	generation++;
	
	buffer = current;
	
	if(greyscale)
		buffer.mutate_greyscale();
	else
		buffer.mutate();
		
	eval();
	
	for(int x = 0; x < dimensions.x; x++)
	{
		for(int y = 0; y < dimensions.y; y++)
		{
			sf::Color buffer_color(current.matrix[x][y]);
			image.setPixel(x,y,buffer_color);
		}
	}
}

/* END PUBLIC FUNCTIONS */

void GeneticImage::eval()
{
	Matrix current_eval = nominal - current;
	Matrix buffer_eval = nominal - buffer;
	
	double current_value = frobenius(current_eval);
	double buffer_value = frobenius(buffer_eval);
	
	
	if(buffer_value < current_value)
	{
		current = buffer;
	}
}

/*
void GeneticImage::initial_gene()
{
	std::random_device rand_dev_int;
	std::mt19937 int_generator(rand_dev_int());
	
	for(int y = 0; y < SHAPE_ARRAY_SIZE; y++)
	{
		for(int x = 0; x < STRING_ARRAY_SIZE; x++)
		{
			switch(x)
			{
				case SHAPE_POINTS:
					std::uniform_int_distribution<int> distr(0, 7);
					current[x][y] = distr(int_generator);
				break;
				case SHAPE_LENGTH:
					std::uniform_int_distribution<int> distr(0, 200);
					current[x][y] = distr(int_generator);
				break;
				case SHAPE_COLOR_R:
					std::uniform_int_distribution<int> distr(0, 255);
					current[x][y] = distr(int_generator);
				break;
				case SHAPE_COLOR_G:
					std::uniform_int_distribution<int> distr(0, 255);
					current[x][y] = distr(int_generator);
				break;
				case SHAPE_COLOR_B:
					std::uniform_int_distribution<int> distr(0, 255);
					current[x][y] = distr(int_generator);
				break;
				case SHAPE_COLOR_A:
					std::uniform_int_distribution<int> distr(0, 255);
					current[x][y] = distr(int_generator);
				break;
				case SHAPE_POS_X:
					std::uniform_int_distribution<int> distr(0, dimensions.x);
					current[x][y] = distr(int_generator);
				break;
				case SHAPE_POS_Y:
					std::uniform_int_distribution<int> distr(0, dimensions.y);
					current[x][y] = distr(int_generator);
				break;
				default:
				break;
			}
		}
	}
	
	
}

void GeneticImage::mutate_gene()
{
	std::random_device rand_dev_double;
	std::mt19937 double_generator(rand_dev_double());
	std::uniform_real_distribution<double> unif(1.0,0.0);
	
	std::random_device rand_dev_int;
	std::mt19937 int_generator(rand_dev_int());
	
	for(int y = 0; y < SHAPE_ARRAY_SIZE; y++)
	{
		for(int x = 0; x < STRING_ARRAY_SIZE; x++)
		{
			if(unif(double_generator) > 0.75)
			{
				switch(x)
				{
					case SHAPE_POINTS:
						std::uniform_int_distribution<int> distr(0, 7);
						current[x][y] = distr(int_generator);
					break;
					case SHAPE_LENGTH:
						std::uniform_int_distribution<int> distr(0, 200);
						current[x][y] = distr(int_generator);
					break;
					case SHAPE_COLOR_R:
						std::uniform_int_distribution<int> distr(0, 255);
						current[x][y] = distr(int_generator);
					break;
					case SHAPE_COLOR_G:
						std::uniform_int_distribution<int> distr(0, 255);
						current[x][y] = distr(int_generator);
					break;
					case SHAPE_COLOR_B:
						std::uniform_int_distribution<int> distr(0, 255);
						current[x][y] = distr(int_generator);
					break;
					case SHAPE_COLOR_A:
						std::uniform_int_distribution<int> distr(0, 255);
						current[x][y] = distr(int_generator);
					break;
					case SHAPE_POS_X:
						std::uniform_int_distribution<int> distr(0, dimensions.x);
						current[x][y] = distr(int_generator);
					break;
					case SHAPE_POS_Y:
						std::uniform_int_distribution<int> distr(0, dimensions.y);
						current[x][y] = distr(int_generator);
					break;
					default:
					break;
				}
			}
		}
	}
}
*/
