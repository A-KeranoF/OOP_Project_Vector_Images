#ifndef SHAPE_H
#define SHAPE_H
#include "attributes.h"

class Shape {
protected:
	//ShapeType type;
	Color outline;
	Color bgColor;

	unsigned int id;
	static int nextID;

	void setID(const int id_); //not sure if this is how to make a member mutable?

	void copyDef(const Shape& other);


public:
	Shape();
	virtual ~Shape();
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);

	virtual void printInfo() = 0;
	virtual void translateShape(const double v, const double h) = 0;
	virtual void scaleShape(double c1, double c2) = 0;
	virtual void rotateShape(const double degree) = 0;

	int getID() const;
	Color getOutline() const;
	Color getBG() const;

	void setOutline(const Color color);
	void setBGColor(const Color color);

	std::string colorToText(Color color);

	double angleToCenter(const Coordinates& center_, const Coordinates& point);

};

#endif
