#include "imageparser.h"

/* CONSTRUCTORS */
ImageParser::ImageParser()
{

}
/* END CONSTRUCTORS */

/* MEMBER FUNCTIONS */
Matrix ImageParser::parse_image(sf::Image input)
{
	uint32_t buffer_int;
	sf::Color buffer_color;
	sf::Vector2u size = input.getSize();
	int width = size.x;
	int height = size.y;
	
	Matrix result(width, height);
	result.init(0);
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			buffer_color = input.getPixel(x,y);
			buffer_int = buffer_color.toInteger();
			result.matrix[x][y] += buffer_int;
		}
	}
	
	return result;
}

Matrix ImageParser::parse_image_greyscale(sf::Image input)
{
	uint32_t buffer_int;
	sf::Color buffer_color;
	sf::Vector2u size = input.getSize();
	int width = size.x;
	int height = size.y;
	
	Matrix result(width, height);
	result.init(0);
	
	int gray_buffer;
	int color_settings[3];
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			buffer_color = input.getPixel(x,y);
			color_settings[0] = buffer_color.r;
			color_settings[1] = buffer_color.g;
			color_settings[2] = buffer_color.b;
			gray_buffer = color_settings[0] + color_settings[1] + color_settings[2];
			gray_buffer = gray_buffer / 3;
			buffer_color.r = gray_buffer;
			buffer_color.g = gray_buffer;
			buffer_color.b = gray_buffer;
			buffer_color.a = 255;
			buffer_int = buffer_color.toInteger();
			result.matrix[x][y] += buffer_int;
		}
	}
	
	return result;
}

void ImageParser::compile_image(Matrix &input)
{
	int width = input.width;
	int height = input.height;
	
	sf::Image result;
	result.create(width, height, sf::Color::Black);
	
	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			sf::Color buffer_color(input.matrix[x][y]);
			result.setPixel(x,y,buffer_color);
		}
	}
	
	if (!result.saveToFile("result.png"))
    	return;
}
