#include <SFML/Graphics.hpp>
#include <cmath>
#include "imageparser.h"
#include "matrix.h"

#ifndef IMG_GENE_RATOR_H
#define IMG_GENE_RATOR_H

#define SHAPE_POINTS 0
#define SHAPE_LENGTH 1
#define SHAPE_COLOR_R 2
#define SHAPE_COLOR_G 3
#define SHAPE_COLOR_B 4
#define SHAPE_COLOR_A 5
#define SHAPE_POS_X 6
#define SHAPE_POS_Y 7

#define STRING_ARRAY_SIZE 8
#define SHAPE_ARRAY_SIZE 50
#define MAX_SHAPE_SIZE 200

class GeneticImage
{
	public:
	//Constructors
	GeneticImage(sf::RenderWindow *input_window, bool input_greyscale);
	GeneticImage(sf::RenderWindow *input_window, bool input_greyscale, string filename);
	//Public Member Functions
	void set_image(string filename);
	void set_position(float x, float y);
	void draw();
	void init();
	void update();
	//Public Member Variables
	int generation;
	private:
	//Private Member Functions
	bool greyscale;
	void eval();
	void initial_gene();
	void mutate_gene();
	//Private Member Variables
	sf::ConvexShape shapes[SHAPE_ARRAY_SIZE];
	sf::RenderWindow *screen;
	sf::Image image;
	sf::Texture image_texture;
	sf::Sprite image_sprite;
	sf::Vector2u dimensions;
	ImageParser parser;
	Matrix nominal;
	Matrix current;
	Matrix buffer;
};

#endif
