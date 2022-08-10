#include "Rectangle.h"

void Rectangle::copyRect(const Rectangle& other)
{
	this->copyDef(other);

	this->setCorner(other.getCorner());
	this->setLength(other.getLength());
	this->setWidth(other.getWidth());
}

Rectangle::Rectangle() : length(1), width(-2), angle(0)
{
	corner.setX(0);
	corner.setY(0);

	std::cout << "Successfully created a rectangle. ID:" << getID() << std::endl;
}

Rectangle::Rectangle(double upX, double upY, double len_, double wid_, Color outline_, Color bgColor_) :
	length(len_),
	width(wid_),
	angle(0)
{
	corner.setX(upX);
	corner.setY(upY);

	bgColor = bgColor_;
	outline = outline_;

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
	std::cout << "rectangle "
		<< corner.getX() << " " << corner.getY()
		<< " length " << getLength() << " width " << getWidth()
		<< " angle " << getAngle() << " degrees"
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

void Rectangle::rotateShape(double degree)
{
	Coordinates center{};
	center.setX((corner.getX() + cos(angle) * length) / 2);
	center.setY((corner.getY() + sin(angle) * width) / 2);

	double radius = distanceBetweenPoints(corner, center);

	corner.setX(radius * cos(angleToPoint(center, getCorner()) + degree));
	corner.setY(radius * sin(angleToPoint(center, getCorner()) + degree));

	setAngle(degree + getAngle());
	
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

double Rectangle::getAngle() const
{
	return this->angle;
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

void Rectangle::setAngle(const double angle_)
{
	angle = angle_;
	while (angle >= 360)
	{
		angle -= 360;
	}
	while (angle <= -360)
	{
		angle += 360;
	}
}
