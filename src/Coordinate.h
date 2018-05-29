#ifndef COORDINATE_H
#define COORDINATE_H

struct Coordinate{ 
	int X, Y, Z;
	Coordinate() : Coordinate(0,0,0) {}
	Coordinate(int X, int Y, int Z) : X(X), Y(Y), Z(Z) {};
	bool operator==(const Coordinate& p1){ 
		return (this->X == p1.X && this->Y == p1.Y && this->Z == Z);
	}
	// // Converts coordinates from 3D > 2D
	// void convert() {
	// 	return Coordinate(this->Y, this->X);
	// }
};

#endif