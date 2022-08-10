#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"

class Circle : public Shape {
private:
	Coordinates centerPoint;
	double radius;

	void copyCircle(const Circle& other);

public:
	Circle();
	Circle(double centerX, double centerY, double radius_, Color outline_, Color bgColor_);
	~Circle();
	Circle(const Circle& other);
	Circle& operator=(const Circle& other);

	virtual void printInfo() override;
	virtual void translateShape(const double v, const double h) override;
	virtual void scaleShape(double c1, double c2) override;
	virtual void rotateShape(double degree); // does nothing

	double getRadius() const;
	Coordinates getCenter() const;

	void setRadius(const double radius_);
	void setCenter(const Coordinates& point);

};

#endif