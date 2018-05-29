#ifndef POINT_H
#define POINT_H

#include "Screen.h"
#include "Coordinate.h"
#include <cmath>


/* 
	Refers to different vertexs/coordinates in space
*/
class Vertex{
private:
	Coordinate c3D;
	Coordinate c2D;
public:
	Vertex() : Vertex(0,0,0) {};
	Vertex(int Y, int X, int Z) { c3D.Y = Y; c3D.X = X; c3D.Z = Z; };

	Coordinate get3D() const { return c3D; }
	Coordinate get2D() { 
		c2D.X = c3D.X/c3D.Z+1900/2;
		c2D.Y = c3D.Y/c3D.Z+358/2;
		return c2D; 
	}

	Vertex& operator=(const Vertex& otherVertex);
	bool operator==(const Vertex& otherVertex);

	// Transformations
	void translate(int Y, int X);
	/*
void dilate(float factor);

	void rotateX(float angle)
	void rotateY(float angle)
	reflect();		// Not necessary
	*/
};

#endif