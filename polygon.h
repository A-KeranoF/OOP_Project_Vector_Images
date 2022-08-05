#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
#include <vector>

class Polygon : public Shape {
private:
	//ShapeType type = ShapeType::POLYGON
	std::vector<Coordinates>vertexes{};

	void copyPolygon(const Polygon& other);

public:
	Polygon();
	~Polygon();
	Polygon(const Polygon& other);
	Polygon& operator=(const Polygon& other);

	virtual void printInfo() override;
	virtual void translateShape(const double v, const double h) override;
	virtual void scaleShape(double c1, double c2) override; // unfinished
	virtual void rotateShape(const double degree) override;

};
#endif
