#include "Circle.h"

void Circle::copyCircle(const Circle& other)
{
	this->copyDef(other);

	this->setRadius(other.getRadius());
	this->setCenter(other.getCenter());
}

Circle::Circle() : radius(1)
{
	centerPoint.setX(1);
	centerPoint.setY(1);

	std::cout << "Successfully created a circle. ID:" << getID() << std::endl;
}

Circle::Circle(double centerX, double centerY, double radius_, Color outline_, Color bgColor_)
{
	centerPoint.setX(centerX);
	centerPoint.setY(centerY);

	radius = radius_;

	bgColor = bgColor_;
	outline = outline_;

	std::cout << "Successfully created a circle. ID:" << getID() << std::endl;
}

Circle::~Circle()
{
}

Circle::Circle(const Circle& other)
{
	copyCircle(other);
}

Circle& Circle::operator=(const Circle& other)
{
	if (this != &other)
	{
		copyCircle(other);
	}
	return *this;
}

void Circle::printInfo()
{
	std::cout << "circle "
		<< centerPoint.getX() << " " << centerPoint.getY()
		<< " outline:" << colorToText(getOutline())
		<< " color:" << colorToText(getOutline()) << std::endl;
}

void Circle::translateShape(const double v, const double h)
{
	centerPoint.setX(v + centerPoint.getX());
	centerPoint.setY(h + centerPoint.getY());
}


void Circle::scaleShape(double c1, double c2)
{
	setRadius(c1 * getRadius());
}

void Circle::rotateShape(double degree)
{
	// does nothing, it's a plain circle, a simple round object
}

double Circle::getRadius() const {
	return this->radius;
}

Coordinates Circle::getCenter() const
{
	return this->centerPoint;
}

void Circle::setRadius(const double radius_) {
	radius = radius_;
}

void Circle::setCenter(const Coordinates& point)
{
	centerPoint.setX(point.getX());
	centerPoint.setY(point.getY());
}