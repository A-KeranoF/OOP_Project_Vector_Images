#include "line.h"
#include <cmath>

void Line::copyLine(const Line& other)
{
	this->copyDef(other);

	this->setBegin(other.getBegin());
	this->setEnd(other.getEnd());
}

Line::Line()
{
	beginPoint.setX(0);
	beginPoint.setY(0);
	
	endPoint.setX(2);
	endPoint.setY(1);

	setBGColor(Color::TRANSPARENT);
	std::cout << "Successfully created a line. ID:" << getID() << std::endl;
}

Line::Line(double beginX, double beginY, double endX, double endY, Color outline_)
{
	beginPoint.setX(beginX);
	beginPoint.setY(beginY);

	endPoint.setX(endX);
	endPoint.setY(endY);

	setBGColor(Color::TRANSPARENT);
	setOutline(outline_);

	//setID(++nextID);

	std::cout << "Successfully created a line. ID:" << getID() << std::endl;
}

Line::~Line()
{
}

Line::Line(const Line& other)
{
	copyLine(other);
}

Line& Line::operator=(const Line& other)
{
	if (this != &other)
	{
		copyLine(other);
	}
	return *this;
}

void Line::printInfo()
{
	std::cout << "'\n'line "
		<< beginPoint.getX() << " " << beginPoint.getY() << " "
		<< endPoint.getX() << " " << endPoint.getY() << " "	
		<< colorToText(getOutline()) << std::endl;
}

void Line::translateShape(double v, double h)
{
	beginPoint.setX(v + beginPoint.getX());
	beginPoint.setY(h + beginPoint.getY());

	endPoint.setX(v + endPoint.getX());
	endPoint.setY(h + endPoint.getY());
}

void Line::scaleShape(double c1, double c2) {
	beginPoint.setX(c1 * beginPoint.getX());
	beginPoint.setY(c2 * beginPoint.getY());

	endPoint.setX(c1 * endPoint.getX());
	endPoint.setY(c2 * endPoint.getY());
}

void Line::rotateShape(const double degree)
{
	Coordinates center{};
	center.setX((beginPoint.getX() + endPoint.getX()) / 2);
	center.setY((beginPoint.getY() + endPoint.getY()) / 2);

	double radius = sqrt(
		(beginPoint.getX() - center.getX()) * (beginPoint.getX() - center.getX()) +
		(beginPoint.getY() - center.getY()) * (beginPoint.getY() - center.getY()));

	beginPoint.setX(radius * cos(angleToCenter(center, getBegin()) + degree));
	beginPoint.setY(radius * sin(angleToCenter(center, getBegin()) + degree));

	endPoint.setX(radius * cos(angleToCenter(center, getEnd()) + degree));
	endPoint.setY(radius * sin(angleToCenter(center, getEnd()) + degree));
}

Coordinates Line::getBegin() const
{
	return this->beginPoint;
}

Coordinates Line::getEnd() const
{
	return this->endPoint;
}

void Line::setBegin(const Coordinates& begin_)
{
	beginPoint.setX(begin_.getX());
	beginPoint.setY(begin_.getY());
}

void Line::setEnd(const Coordinates& end_)
{
	endPoint.setX(end_.getX());
	endPoint.setY(end_.getY());
}
