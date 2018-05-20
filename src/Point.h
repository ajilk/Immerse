#ifndef POINT_H
#define POINT_H

#include "Screen.h"
#include <cmath>

struct Coordinate{ int X; int Y; };
enum Quadrant{ I, II, III, IV };

/*
	Function: Point class is used to represent different points in space
		- Knows which quadrant it is in
*/
class Point{
private:
	Coordinate cartesian;
	Coordinate absolute;
	Quadrant quadrant;
public:
	Point();
	Point(int Y, int X);
	Coordinate getAbsolute() { return absolute; }
	Coordinate getCartesian() { return cartesian; }
	void convert(Screen &screen);
	void print(int Y, int X, Screen &screen);
};

#endif