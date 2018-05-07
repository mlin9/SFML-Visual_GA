#include <SFML/Graphics.hpp>
#include <cstdint>
#include <cmath>
#include "matrix.h"

#ifndef IMG_PARSER_H
#define IMG_PARSER_H

class ImageParser
{
	public:
	ImageParser();
	Matrix parse_image(sf::Image input);
	Matrix parse_image_greyscale(sf::Image input);
	void compile_image(Matrix &input);
};

#endif
