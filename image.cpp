#include "image.h"

Image::Image()
{
	std::cout << "Created an image." << std::endl;
}

Image::~Image()
{
}

Shape* Image::defaultCreate(const ShapeType type)
{
    switch (type)
    {
    case ShapeType::LINE:
        return new Line();
    case ShapeType::CIRCLE:
        return new Circle();
    case ShapeType::RECTANGLE:
        return new Rectangle();
    case ShapeType::POLYGON:
        return new Polygon();
    default:
        std::cout << "Invalid shape"; 
        break;
    }
}

void Image::printImage()
{
    for (int i = layer.size(); i > 0; --i) {
        std::cout << "layer " << i << ": " << std::endl; // perhaps this line is redundant

        for (int j = layer[i].size(); j > 0 ; --j) {
           layer[i][j]->printInfo();
           std::cout << std::endl;
        }

        std::cout << std::endl;
    }
}

void Image::translateShape(const int v, const int h)
{
    for (int i = 0; i < layer.size(); i++) {
        for (int j = 0; j < layer[i].size(); j++) {
            layer[i][j]->translateShape(v, h);
        }
    }
}

void Image::translateShape(const int* id, const int v, const int h)
{
    //sizeof(pointer)/sizeof(pointer[0]) throws a warning, i do not know how to fix
    for (int k = 0; k < (sizeof(id) / sizeof(id[0])); k++) {
        for (int i = 0; i < layer.size(); i++) {
            for (int j = 0; j < layer[i].size(); j++) {
                if (id[k] == layer[i][j]->getID()) {
                    layer[i][j]->translateShape(v, h);
                }
            }
        }
    }
}

void Image::scale(const double c1, const double c2)
{
    for (int i = 0; i < layer.size(); i++) {
        for (int j = 0; j < layer.size(); j++) {
            layer[i][j]->scaleShape(c1, c2);
        }
    }
}

void Image::scale(const int* id, const double c1, const double c2)
{
    for (int k = 0; k < (sizeof(id) / sizeof(id[0])); k++) {
        for (int i = 0; i < layer.size(); i++) {
            for (int j = 0; j < layer[i].size(); j++) {
                if (id[k] == layer[i][j]->getID()) {
                    layer[i][j]->scaleShape(c1, c2);
                }
            }
        }
    }
}

void Image::rotate(const double degree)
{
    for (int i = 0; i < layer.size(); i++) {
        for (int j = 0; j < layer[i].size(); j++) {
            layer[i][j]->rotateShape(degree);
        }
    }
}

void Image::rotate(const int* id, const double degree)
{
    for (int k = 0; k < (sizeof(id) / sizeof(id[0])); k++) {
        for (int i = 0; i < layer.size(); i++) {
            for (int j = 0; j < layer[i].size(); j++) {
                if (id[k] == layer[i][j]->getID()) {
                    layer[i][j]->rotateShape(degree);
                }
            }
        }
    }
}
