#include "shapes.h"

Color::Color(int red, int green, int blue)
{
	r = red;
	g = green;
	b = blue;
	a = 255;
}

Color::Color(int red, int green, int blue, int alpha)
{
	r = red;
	g = green;
	b = blue;
	a = alpha;
}

Color::Color() {}

Circle::Circle() {}

Circle::Circle(double x_, double y_, double r_, Color color_) 
	: x(x_), y(y_), r(r_), color(color_), outline_r(0)
{}

Circle::Circle(double x_, double y_, double r_, Color color_, double outline_r_, Color outline_color_) 
	: x(x_), y(y_), r(r_), color(color_), outline_r(outline_r_), outline_color(outline_color_)
{}

Rectangle::Rectangle() {}

Rectangle::Rectangle(double x1_, double y1_, double x2_, double y2_, Color color_) 
	: x1(x1_), y1(y1_), x2(x2_), y2(y2_), color(color_) {}


sf::Color Color::ToSf() const {
	return sf::Color(r, g, b, a);
}