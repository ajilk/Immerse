#ifndef POINT_H
#define POINT_H

#include "Screen.h"
#include <cmath>

struct Coordinate{ 
	int X, Y, Z;
	Coordinate() : Coordinate(0,0,0) {}
	Coordinate(int X, int Y, int Z) { this->X = X; this->Y = Y; this->Z = Z; }
	bool operator==(const Coordinate& p1){ 
		return (this->X == p1.X && this->Y == p1.Y && this->Z == Z);
	}
	// // Converts coordinates from 3D > 2D
	// void convert() {
	// 	return Coordinate(this->Y, this->X);
	// }
};

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
	Coordinate get2D() const { return c2D; }

	Vertex& operator=(const Vertex& otherVertex);
	bool operator==(const Vertex& otherVertex);

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