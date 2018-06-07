#include <ncurses.h>
#include <gtest/gtest.h>
#include <unistd.h>
#include "Screen.h"
#include "Vertex.h"
// #include "tests/test.h"

//DDA Algorithm to draw lines
void line(Vertex v1, Vertex v2, Screen& screen){
    // calculate dx & dy
    int dx = v2.get2D(screen).X - v1.get2D(screen).X;
    int dy = v2.get2D(screen).Y - v1.get2D(screen).Y;
 
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    // calculate increment in x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
 
    // Put pixel for each step
    float X = v1.get2D(screen).X;
    float Y = v1.get2D(screen).Y;
    for (int i = 0; i <= steps; i++)
    {
		screen.putch(Y, X, '.');// put pixel at (X,Y)
        X += Xinc;           // increment in x at each step
        Y += Yinc;           // increment in y at each step
                             // generation step by step
    }
}

void box(Screen &screen, Coordinate v1, Coordinate v2, Coordinate v3, Coordinate v4, int x, int y, int z){
	line(* new Vertex(v1.Y+y, v1.X+x, v1.Z+z),* new Vertex(v2.Y+y, v2.X+x, v2.Z+z), screen);
	line(* new Vertex(v1.Y+y, v1.X+x, v1.Z+z),* new Vertex(v3.Y+y, v3.X+x, v3.Z+z), screen);
	line(* new Vertex(v4.Y+y, v4.X+x, v4.Z+z),* new Vertex(v3.Y+y, v3.X+x, v3.Z+z), screen);
	line(* new Vertex(v4.Y+y, v4.X+x, v4.Z+z),* new Vertex(v2.Y+y, v2.X+x, v2.Z+z), screen);

	// for(int i=v1.X; i<v2.X; i++){
	// 	line(* new Vertex(v1.Y+y, i+x, v1.Z+z), * new Vertex(v3.Y+y, i+x, v3.Z+z), screen);
	// }
}

int main(int argc, char **argv){
    Screen screen;
	Vertex v1(1,1,1);
	Vertex v2(1,1,20);


	int z = 0, x=0, y=0; //Offest values
	char ch;
	while(ch != 'q' && ch != 'Q'){
		if(screen.kbhit()){
			ch = getch();
			switch(ch){
				case 'i':
				case 'I': if(z<=0) z=0; else z--; break;
				case 'o':
				case 'O': z++; break;
				case 'l': x+=40; break;
				case 'L': x+=80; break;
				case 'h': x-=40; break;
				case 'H': x-=80; break;
				case 'j': y+=40; break;
				case 'J': y+=80; break;
				case 'k': y-=40; break;
				case 'K': y-=80; break;
			}
			clear();
			if(z >= 120){
				z = 0;
			}
		}
		line(* new Vertex(0+y, 0+x, 2+z), * new Vertex(0+y, 0+x, 1+z), screen);
		line(* new Vertex(0+y, 400+x, 2+z), * new Vertex(0+y, 400+x, 1+z), screen);
		line(* new Vertex(150+y, 0+x, 2+z), * new Vertex(150+y, 0+x, 1+z), screen);
		line(* new Vertex(150+y, 400+x, 2+z), * new Vertex(150+y, 400+x, 1+z), screen);
		box(screen, * new Coordinate(0,0,1), * new Coordinate(0,400,1), * new Coordinate(150, 0,1), * new Coordinate(150, 400, 1),x,y,z);
		box(screen, * new Coordinate(0,0,2), * new Coordinate(0,400,2), * new Coordinate(150, 0,2), * new Coordinate(150, 400, 2),x,y,z);
	}
    return 0;
}