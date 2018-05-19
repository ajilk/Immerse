#include <ncurses.h>
#include "Screen.h"
#include "Point.h"
#include "Line.h"

// void drawline(Screen &screen, int x0, int y0, int x1, int y1)
// {
//     int dx, dy, p, x, y;
 
//     dx=x1-x0;
//     dy=y1-y0;
 
//     x=x0;
//     y=y0;
 
//     p=2*dy-dx;
 
//     while(x<x1)
//     {
//         if(p>=0)
//         {
// 			screen.drawChar(y,x,'.');
//             y=y+1;
//             p=p+2*dy-2*dx;
//         }
//         else
//         {
//             screen.drawChar(y,x,'.');
//             p=p+2*dy;
//         }
//         x=x+1;
//     }
// }
 
int main()
{
	Screen screen;
    Point p1(1,2);
    Point p2(100,400);
    Line line(p1, p2);
    // printf("%f\n", line.getSlope(p1, p2));
    // printf("%f", line.getIntercept(line.getSlope(p1,p2), p1));
    // getch();
    line.draw(screen);
    return 0;
}

// int main(){
// 	Screen screen;
// 	Point p2(1,20);
// 	Point p1(10, 10);
// 	Line line(p1, p2);
// 	line.print(screen);
// 	return 0;
// }