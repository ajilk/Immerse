#include "Vertex.h"

Vertex::Vertex(){
	cartesian.X = 0;
	cartesian.Y = 0;
}

Vertex::Vertex(int Y, int X){
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
void Vertex::convert(Screen &screen){
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
void Vertex::print(int Y, int X, Screen &screen){
	// mvprintw(Y, X, "ABS: ( %4d, %4d )", absolute.Y, absolute.X);
	// mvprintw(Y, X, "REL: ( %4d, %4d )", cartesian.Y, cartesian.X);
	screen.putch(Y, X, '*');
}

/*
	Function:	Copy cartesian and absolute coordinate to this vertex
	@param:		Another vertex
	@return:	this
*/
Vertex& Vertex::operator=(const Vertex& otherVertex){
	if(*this == otherVertex)
		return *this;
	this->absolute = otherVertex.absolute;
	this->cartesian = otherVertex.cartesian;
	this->quadrant = otherVertex.quadrant;
	return *this;
}

/*
	Function:	compare 2 vertexs if they are the same
	@param:		2 Vertexs
	@return:	true if 2 vertexs are exactly the same
*/
bool Vertex::operator==(const Vertex& p1){
	if(this->cartesian == p1.cartesian && this->absolute == p1.absolute)
		return true;
	else
		return false;
}
