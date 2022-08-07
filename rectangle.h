#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape {
private:
	//ShapeType type = ShapeType::RECTANGLE;
	Coordinates corner;
	//upper left corner
	double length, width;
	//length = x, width = y

	// double angle{}; // perhaps needed to fix the problems with the rotation

	void copyRect(const Rectangle& other);

public:
	Rectangle();
	Rectangle(double upX, double upY, double len_, double wid_, Color outline_, Color bgColor_);
	~Rectangle();
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);

	virtual void printInfo() override;
	virtual void translateShape(double v, double h) override;
	virtual void scaleShape(double c1, double c2) override;
	virtual void rotateShape(const double degree) override;

	Coordinates getCorner() const;
	double getLength() const;
	double getWidth() const;

	void setCorner(const Coordinates& point);
	void setLength(const double len_);
	void setWidth(const double wid_);

};
#endif	
