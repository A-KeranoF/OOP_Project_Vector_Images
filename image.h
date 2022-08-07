#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <vector>
#include "shape.h"
#include "line.h"
#include "rectangle.h"
#include "circle.h"
#include "polygon.h"

class Image {
private:
	std::vector<std::vector <Shape*>> layer;

public:
	Image();
	~Image();
	Image(const Image& other) = delete;
	Image& operator=(const Image& other) = delete;

	Shape* defaultCreate(const ShapeType type);

	void printImage();

	void group(double upX, double upY, double downX, double downY);
	void ungroup(const int id);
	void bringForward(const int id, const int layers);
	void sendBackward(const int id, const int layers);

	void translateShape(const int v, const int h);
	void translateShape(const int* id, const int v, const int h);

	void scale(const double c1, const double c2);
	void scale(const int* id, const double c1, const double c2);

	void rotate(const double degree);
	void rotate(const int* id, const double degree);

	void saveImage();
	void saveAs();
	//void help(); maybe it should be in other file with other functions and define it there

};

#endif