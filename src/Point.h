#ifndef POINT_H
#define POINT_H

class Point{
private:
	int X;
	int Y;
public:
	Point() : Y(0), X(0) {}
	Point(int Y, int X) : Y(Y), X(X) {}
	int getX() { return X; }
	int getY() { return Y; }
};

#endif