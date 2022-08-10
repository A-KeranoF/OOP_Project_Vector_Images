#ifndef POLYGON_H
#define POLYGON_H
#include "Shape.h"
#include <vector>

class Polygon : public Shape {
private:
	std::vector<Coordinates>vertexes{};

	void copyPolygon(const Polygon& other);

public:
	Polygon();
	~Polygon();
	Polygon(const Polygon& other);
	Polygon& operator=(const Polygon& other);

	virtual void printInfo() override;
	virtual void translateShape(double v, double h) override;
	virtual void scaleShape(double c1, double c2) override;
	virtual void rotateShape(double degree) override;

};

#endif