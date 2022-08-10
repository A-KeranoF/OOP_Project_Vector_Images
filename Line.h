#ifndef LINE_H
#define LINE_H
#include "Shape.h"

class Line : public Shape {
private:
	Color bgColor = Color::TRANSPARENT;
	Coordinates beginPoint, endPoint;

	void copyLine(const Line& other);

public:
	Line();
	Line(double beginX, double beginY, double endX, double endY, Color outline_);
	~Line();
	Line(const Line& other);
	Line& operator=(const Line& other);

	virtual void printInfo() override;
	virtual void translateShape(double v, double h) override;
	virtual void scaleShape(double c1, double c2) override;
	virtual void rotateShape(double degree) override;

	Coordinates getBegin() const;
	Coordinates getEnd() const;

	void setBegin(const Coordinates& begin_);
	void setEnd(const Coordinates& end_);

};

#endif