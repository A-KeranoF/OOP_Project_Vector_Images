#include "image.h"

Image::Image()
{
    std::cout << "Created an image." << std::endl;
}

Image::~Image()
{
}

void Image::addShape(Shape*& obj)
{
    layer[layer.size()].push_back(obj);
}

void Image::removeShape(const int id)
{
    for (int i = 0; i < layer.size(); i++)
    {
        for (int j = 0; j < layer[i].size(); j++)
        {
            if (id == layer[i][j]->getID())
            {
                Shape** pointer = &layer[i][j];
                layer[i].erase(layer[i].begin() + j);
                delete pointer;
            }
        }
    }
}

void Image::printImage()
{
    for (unsigned int i = layer.size(); i > 0; --i) {
        std::cout << "layer " << i << ": " << std::endl; // perhaps this line is redundant

        for (unsigned int j = layer[i].size(); j > 0; --j) {
            std::cout << "  ";
            layer[i][j]->printInfo();
        }
    }
}

void Image::bringForward(const int id, const int layers)
{
    for (int i = 0; i < layer.size(); i++)
    {
        for (int j = 0; i < layer[i].size(); j++)
        {
            if (i + layers < layer.size())
            {
                Shape** pointer = &layer[i][j];
                layer[i].erase(layer[i].begin() + j);
                layer[i + layers].push_back(*pointer);
                // i do not know if i need to delete the pointer itself and how
            }
            else 
            {
                Shape** pointer = &layer[i][j];
                layer[i].erase(layer[i].begin() + j);
                layer[layer.size()].push_back(*pointer);
            }
        }
    }
}

void Image::sendBackward(const int id, const int layers)
{
    for (int i = 0; i < layer.size(); i++)
    {
        for (int j = 0; j < layer[i].size(); j++)
        {
            if (i - layers > 0)
            {
                Shape** pointer = &layer[i][j];
                layer[i].erase(layer[i].begin() + j);
                layer[i - layers].insert(layer[i].begin() + j, *pointer);
            }
            else
            {
                Shape** pointer = &layer[i][j];
                layer[i].erase(layer[i].begin() + j);
                layer[0].insert(layer[i].begin() + j, *pointer);
            }
        }
    }
}

void Image::translate(int v, int h)
{
    for (int i = 0; i < layer.size(); i++) {
        for (int j = 0; j < layer[i].size(); j++) {
            layer[i][j]->translateShape(v, h);
        }
    }
}

void Image::translate(const int* id, int v, int h)
{
    int size = *(&id + 1) - id;
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < layer.size(); i++) {
            for (int j = 0; j < layer[i].size(); j++) {
                if (id[k] == layer[i][j]->getID()) {
                    layer[i][j]->translateShape(v, h);
                }
            }
        }
    }
}

void Image::scale(double c1, double c2)
{
    for (int i = 0; i < layer.size(); i++) {
        for (int j = 0; j < layer[i].size(); j++) {
            layer[i][j]->scaleShape(c1, c2);
        }
    }
}

void Image::scale(const int* id, double c1, double c2)
{
    int size = *(&id + 1) - id;
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < layer.size(); i++) {
            for (int j = 0; j < layer[i].size(); j++) {
                if (id[k] == layer[i][j]->getID()) {
                    layer[i][j]->scaleShape(c1, c2);
                }
            }
        }
    }
}

void Image::rotate(double degree)
{
    for (int i = 0; i < layer.size(); i++) {
        for (int j = 0; j < layer[i].size(); j++) {
            layer[i][j]->rotateShape(degree);
        }
    }
}

void Image::rotate(const int* id, double degree)
{
    int size = *(&id + 1) - id;
    for (int k = 0; k < size; k++) {
        for (int i = 0; i < layer.size(); i++) {
            for (int j = 0; j < layer[i].size(); j++) {
                if (id[k] == layer[i][j]->getID()) {
                    layer[i][j]->rotateShape(degree);
                }
            }
        }
    }
}
