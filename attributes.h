#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

enum class ShapeType {
	UNKNOWN = -1,
	LINE,
	CIRCLE,
	RECTANGLE,
	POLYGON,
	TYPE_COUNT
};

enum class Color {
	UNKNOWN = -1,
	TRANSPARENT,
	BLACK,
	WHITE,
	PINK,
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	PURPLE,
	COLOR_COUNT
};


class Coordinates {
private:
	double x{};
	double y{};

public:
	void setX(const double x_) { x = x_; }
	void setY(const double y_) { y = y_; }
	double getX() const { return x; }
	double getY() const { return y; }
};

#endif
