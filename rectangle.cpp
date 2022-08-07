#include "rectangle.h"
#include <cmath>

void Rectangle::copyRect(const Rectangle& other)
{
	this->copyDef(other);

	this->setCorner(other.getCorner());
	this->setLength(other.getLength());
	this->setWidth(other.getWidth());
}

Rectangle::Rectangle() : length(1), width(-2)
{
	corner.setX(0);
	corner.setY(0);

	std::cout << "Successfully created a rectangle. ID:" << getID() << std::endl;
}

Rectangle::Rectangle(double upX, double upY, double len_, double wid_, Color outline_, Color bgColor_)
{
	corner.setX(upX);
	corner.setY(upY);

	setLength(len_);
	setWidth(wid_);

	setBGColor(bgColor_);
	setOutline(outline_);

	//setID(++nextID);

	std::cout << "Successfully created a rectangle. ID:" << getID() << std::endl;
}

Rectangle::~Rectangle()
{
}

Rectangle::Rectangle(const Rectangle& other)
{
	copyRect(other);
}

Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if (this != &other)
	{
		copyRect(other);
	}
	return *this;
}

void Rectangle::printInfo()
{
	std::cout << "'\n'rectangle coordinates: "
		<< corner.getX() << " " << corner.getY() 
		<< " length " << getLength() << " width " << getWidth()
		<< " outline:" << colorToText(getOutline()) 
		<< " color:" << colorToText(getOutline()) << std::endl;
}

void Rectangle::translateShape(double v, double h)
{
	corner.setX(v + corner.getX());
	corner.setY(h + corner.getY());
}

void Rectangle::scaleShape(double c1, double c2)
{
	setLength(c1 * getLength());
	setWidth(c2 * getWidth());
}

void Rectangle::rotateShape(const double degree)
{
	Coordinates center{};
	center.setX((corner.getX() + getLength()) / 2);
	center.setY((corner.getY() + getWidth()) / 2);

	double radius = sqrt(
		(corner.getX() - center.getX()) * (corner.getX() - center.getX()) +
		(corner.getY() - center.getY()) * (corner.getY() - center.getY()));

	corner.setX(radius * cos(angleToCenter(center, getCorner()) + degree));
	corner.setY(radius * sin(angleToCenter(center, getCorner()) + degree));

	/*
	there is a problem - since with an interface like that, 
	after this "rotation", no one can tell this rectangle is rotated, 
	thus what it actually happens is that we just moved the point around, 
	but the length and width "vectors" remain their direction
	*/
}

Coordinates Rectangle::getCorner() const
{
	return this->corner;
}

double Rectangle::getLength() const
{
	return this->length;
}

double Rectangle::getWidth() const
{
	return this->width;
}

void Rectangle::setCorner(const Coordinates& point)
{
	corner.setX(point.getX());
	corner.setY(point.getY());
}

void Rectangle::setLength(const double len_)
{
	length = len_;
}

void Rectangle::setWidth(const double wid_)
{
	width = wid_;
}
