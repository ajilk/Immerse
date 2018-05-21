#include "Point.h"

Point::Point(){
	cartesian.X = 0;
	cartesian.Y = 0;
}

Point::Point(int Y, int X){
	cartesian.Y = Y;
	cartesian.X = X;
	// (Y, X)
	// (1, 1) Quadrant I
	if( Y > 0 && X > 0) 		quadrant = I;
	// (1, -1) Quadrant II
	else if( Y > 0 && X < 0)	quadrant = II;
	// (-1, -1) Quadrant III
	else if( Y < 0 && X < 0)	quadrant = III;
	// (-1, 1) Quadrant IV
	else if( Y < 0 && X > 0)	quadrant = IV;
	// (0, 0)
	else						quadrant = IV;
}

/*
	Function:	converts cartesian coordinates to absolute coordinates
	@param:		screen, used to obtain screen size
	@return:	void
*/
void Point::convert(Screen &screen){
	absolute.Y = abs(cartesian.Y);
	absolute.X = abs(cartesian.X);
	switch(quadrant){
		case I:	
			absolute.X = screen.getColumns()/2 + absolute.X;
			absolute.Y = screen.getRows()/2 - absolute.Y;
			break;
		case II:
			// All done
			break;
		case III:
			absolute.Y = absolute.Y + screen.getRows()/2;
			absolute.X = screen.getColumns()/2 - absolute.X;
			break;
		case IV:
			absolute.X = absolute.X + screen.getColumns()/2;
			absolute.Y = absolute.Y + screen.getRows()/2;
			break;
		default: 
			break;
	}			

}

/*
	Function:	Print coordinate
	@param:		screen it is being printed on
	@return:	void
*/
void Point::print(int Y, int X, Screen &screen){
	// mvprintw(Y, X, "ABS: ( %4d, %4d )", absolute.Y, absolute.X);
	// mvprintw(Y, X, "REL: ( %4d, %4d )", cartesian.Y, cartesian.X);
	screen.putch(Y, X, '*');
}

/*
	Function:	Copy cartesian and absolute coordinate to this point
	@param:		Another point
	@return:	this
*/
Point& Point::operator=(const Point& otherPoint){
	if(*this == otherPoint)
		return *this;
	this->absolute = otherPoint.absolute;
	this->cartesian = otherPoint.cartesian;
	this->quadrant = otherPoint.quadrant;
	return *this;
}

/*
	Function:	compare 2 points if they are the same
	@param:		2 Points
	@return:	true if 2 points are exactly the same
*/
bool Point::operator==(const Point& p1){
	if(this->cartesian == p1.cartesian && this->absolute == p1.absolute)
		return true;
	else
		return false;
}
