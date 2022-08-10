#ifndef SHAPE_H
#define SHAPE_H
#include "Attributes.h"
#include <iostream>
#include <cmath>
#include <string>

class Shape {
protected:
	Color outline;
	Color bgColor;

	int id;
	static int nextID;

	void setID(const int id_); //not sure if this is how to make a member mutable?
	static unsigned int getNextID();

	void copyDef(const Shape& other);

public:
	Shape();
	virtual ~Shape();
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);

	virtual void printInfo() = 0;
	virtual void translateShape(double v, double h) = 0;
	virtual void scaleShape(double c1, double c2) = 0;
	virtual void rotateShape(double degree) = 0;

	int getID() const;
	Color getOutline() const;
	Color getBG() const;

	void setOutline(const Color color);
	void setBGColor(const Color color);

	std::string colorToText(Color color);

	double angleToPoint(const Coordinates& from, const Coordinates& to);
	double distanceBetweenPoints(const Coordinates& from, const Coordinates& to);

};

#endif