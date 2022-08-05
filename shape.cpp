#include "shape.h"
#include <cstring>
#include <cmath>

void Shape::setID(const int id_) {
	id = id_;
}

void Shape::copyDef(const Shape& other)
{
	this->setBGColor(other.getBG());
	this->setOutline(other.getOutline());
}

Shape::Shape() : 
	bgColor(Color::TRANSPARENT), 
	outline(Color::BLACK)
{
	// dont know how to increment the id when first made the object
	setID(++nextID); 
}

Shape::~Shape()
{
}

Shape::Shape(const Shape& other)
{
	copyDef(other);
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		copyDef(other);
	}
	return *this;
}

int Shape::getID() const {
	return this->id;
}

Color Shape::getOutline() const {
	return this->outline;
}

Color Shape::getBG() const {
	return this->bgColor;
}

void Shape::setOutline(const Color color) {
	outline = color;
}

void Shape::setBGColor(const Color color) {
	bgColor = color;
}

std::string Shape::colorToText(Color color)
{
	switch (color)
	{
	case Color::TRANSPARENT:
		return "transparent";
	case Color::BLACK:
		return "black";
	case Color::WHITE:
		return "white";
	case Color::PINK:
		return "pink";
	case Color::RED:
		return "red";
	case Color::ORANGE:
		return "orange";
	case Color::YELLOW:
		return "yellow";
	case Color::GREEN:
		return "green";
	case Color::BLUE:
		return "blue";
	case Color::PURPLE:
		return "purple";
	default:
		throw "Unknown color, cannot cast to text!";
		break;
	}
}

double Shape::angleToCenter(const Coordinates& center, const Coordinates& point)
{
	return atan2((point.getY() - center.getY()), (point.getX() - center.getX())) * 180 / 3.14159265;
}