#include "polygon.h"

void Polygon::copyPolygon(const Polygon& other)
{
	this->vertexes = other.vertexes;
}

Polygon::Polygon()
{
	std::cout << "Successfully created a polygon. ID:" << getID() << std::endl;
}

Polygon::~Polygon()
{
}

Polygon::Polygon(const Polygon& other)
{
	copyPolygon(other);
}

Polygon& Polygon::operator=(const Polygon& other)
{
	if (this != &other)
	{
		copyPolygon(other);
	}
	return *this;
}

void Polygon::printInfo()
{
	std::cout << "polygon ";
	for (int i = 0; i < vertexes.size(); i++)
	{
		std::cout << vertexes[i].getX() << " " << vertexes[i].getY() << " ";
	}
	std::cout << " outline:" << colorToText(getOutline())
		<< " color:" << colorToText(getBG()) << std::endl;
}

void Polygon::translateShape(double v, double h)
{
	for (int i = 0; i < vertexes.size(); i++)
	{
		vertexes[i].setX(v + vertexes[i].getX());
		vertexes[i].setY(h + vertexes[i].getY());
	}
}

void Polygon::scaleShape(double c1, double c2)
{
	double fstX = INT_MAX;
	double fstY = INT_MAX;
	double sndX = INT_MIN;
	double sndY = INT_MIN;

	for (int i = 0; i < vertexes.size(); i++)
	{
		if (vertexes[i].getX() < fstX)
			fstX = vertexes[i].getX();

		if (vertexes[i].getY() < fstY)
			fstY = vertexes[i].getY();

		if (vertexes[i].getX() > sndX)
			sndX = vertexes[i].getX();

		if (vertexes[i].getY() > sndY)
			sndY = vertexes[i].getY();
	}

	double rectLength = abs(fstX - sndX);
	double rectWidth = abs(fstY - sndY);

	double ratioLength = (rectLength * c1) / rectLength;
	double ratioWidth = (rectWidth * c2) / rectWidth;

	for (int i = 0; i < vertexes.size(); i++)
	{
		vertexes[i].setX(ratioLength * vertexes[i].getX());
		vertexes[i].setY(ratioWidth * vertexes[i].getY());
	}

}

void Polygon::rotateShape(double degree)
{
	double fstX = INT_MAX;
	double fstY = INT_MAX;
	double sndX = INT_MIN;
	double sndY = INT_MIN;

	for (int i = 0; i < vertexes.size(); i++)
	{
		if (vertexes[i].getX() < fstX)
			fstX = vertexes[i].getX();

		if (vertexes[i].getY() < fstY)
			fstY = vertexes[i].getY();

		if (vertexes[i].getX() > sndX)
			sndX = vertexes[i].getX();

		if (vertexes[i].getY() > sndY)
			sndY = vertexes[i].getY();
	}

	Coordinates centerRect{};

	centerRect.setX((fstX + sndX) / 2);
	centerRect.setY((fstY + sndY) / 2);

	double* radiuses = new double[vertexes.size() + 1]{}; // this initialization might not be correct
	for (int i = 0; i < vertexes.size(); ++i)
	{
		radiuses[i] = distanceBetweenPoints(vertexes[i], centerRect);
	}

	for (int i = 0; i < vertexes.size(); i++)
	{
		vertexes[i].setX(radiuses[i] * cos(angleToPoint(centerRect, vertexes[i]) + degree));
		vertexes[i].setY(radiuses[i] * sin(angleToPoint(centerRect, vertexes[i]) + degree));
	}

	delete[] radiuses;
}
