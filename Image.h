#ifndef IMAGE_H
#define IMAGE_H
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Polygon.h"

class Image {
private:
	std::vector<std::vector <Shape*>> layer;

public:
	Image();
	~Image();
	Image(const Image& other) = delete;
	Image& operator=(const Image& other) = delete;

	void addShape(Shape*& obj);
	void removeShape(const int id); // !

	void printImage();

	void group(double upX, double upY, double downX, double downY);
	void ungroup(const int id);
	void bringForward(const int id, const int layers);
	void sendBackward(const int id, const int layers);

	void translate(int v, int h);
	void translate(const int* id, int v, int h);

	void scale(double c1, double c2);
	void scale(const int* id, double c1, double c2);

	void rotate(double degree);
	void rotate(const int* id, double degree);

	void saveImage();
	void saveAs();

};

#endif