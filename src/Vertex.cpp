#include "Vertex.h"

// /*
// 	Function:	converts cartesian coordinates to absolute coordinates
// 	@param:		screen, used to obtain screen size
// 	@return:	void
// */
// void Vertex::convert(Screen &screen){
// 	absolute.Y = abs(cartesian.Y);
// 	absolute.X = abs(cartesian.X);
// 	switch(quadrant){
// 		case I:	
// 			absolute.X = screen.getColumns()/2 + absolute.X;
// 			absolute.Y = screen.getRows()/2 - absolute.Y;
// 			break;
// 		case II:
// 			// All done
// 			break;
// 		case III:
// 			absolute.Y = absolute.Y + screen.getRows()/2;
// 			absolute.X = screen.getColumns()/2 - absolute.X;
// 			break;
// 		case IV:
// 			absolute.X = absolute.X + screen.getColumns()/2;
// 			absolute.Y = absolute.Y + screen.getRows()/2;
// 			break;
// 		default: 
// 			break;
// 	}			

// }

// /*
// 	Function:	Print coordinate
// 	@param:		screen it is being printed on
// 	@return:	void
// */
// void Vertex::print(int Y, int X, Screen &screen){
// 	// mvprintw(Y, X, "ABS: ( %4d, %4d )", absolute.Y, absolute.X);
// 	// mvprintw(Y, X, "REL: ( %4d, %4d )", cartesian.Y, cartesian.X);
// 	screen.putch(Y, X, '*');
// }

/*
	Function:	move vertex by the specified offset values
	@param:		offset values
	@result:	void
*/
void Vertex::translate(int X,  int Y){
	c3D.X+=X;
	c3D.Y+=Y;
}

/*
	Function:	Copy cartesian and absolute coordinate to this vertex
	@param:		Another vertex
	@return:	this
*/
Vertex& Vertex::operator=(const Vertex& otherVertex){
	if(*this == otherVertex) return *this;
	this->c3D = otherVertex.get3D();
	return *this;
}

/*
	Function:	compare 2 vertexs if they are the same
	@param:		2 Vertexs
	@return:	true if 2 vertexs are exactly the same
*/
bool Vertex::operator==(const Vertex& v1){
	if(this->c3D == v1.get3D()) return true;
	return false;
}