#ifndef POINT_H
#define POINT_H

#include "Screen.h"
#include <cmath>

struct Coordinate{ 
	int X, Y;
	bool operator==(const Coordinate& p1){ 
		return (this->X == p1.X && this->Y == p1.Y);
	}
};
enum Quadrant{ I, II, III, IV };

/* 
	Refers to different points/coordinates in space
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
	Point& operator=(const Point& otherPoint);
	bool operator==(const Point& otherPoint);

	// Transformations
	/*
	void translate(int Y, int X);
	void dialte(float factor);

	void rotateX(float angle)
	void rotateY(float angle)
	reflect();		// Not necessary
	*/
};

#endif