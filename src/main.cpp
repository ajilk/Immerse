#include <ncurses.h>
#include <gtest/gtest.h>
#include <unistd.h>
#include "Screen.h"
#include "Vertex.h"
// #include "tests/test.h"
int abs (int n)
{
    return ( (n>0) ? n : ( n * (-1)));
}

//DDA
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
	line(* new Vertex(screen.getRows(), -screen.getColumns(), 1), * new Vertex(0,0,1), screen);
	line(* new Vertex(2*screen.getRows(), 2*screen.getColumns(), 1), * new Vertex(0,0,1), screen);
}

int main(int argc, char **argv){
    Screen screen;
	int z = 0, x=0, y=0; //Offest values
	Coordinate v1(-screen.getRows()/2,-screen.getColumns()/2,1);
	Coordinate v2(1500,-screen.getColumns()/2,1);
	Coordinate v3(-screen.getRows()/2,5000,1);
	Coordinate v4(1500,5000,1);
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
			box(screen, v1,v2,v3,v4,x,y,z);
		}

	}
	// line(v1, v2, screen);
	refresh();

    // // Vertex vertex[30];
    // // for(int i=-15; i<15; i++){
    // //     vertex[i+15] = *(new Vertex(i+15, i*i + 4*i + 2));
    // //     vertex[i+15].convert(screen);
    // //     vertex[i+15].print(vertex[i+15].getAbsolute().Y, vertex[i+15].getAbsolute().X, screen);
    // //     refresh();
    // // }

    // vertex[0].convert(screen);
    // for(int i=1; i<30; i++){
    //     vertex[i] = *(new Vertex(vertex[i-1].getCartesian().Y-1, vertex[i-1].getCartesian().X-10));
    //     vertex[i].convert(screen);
    // }
    // for(int i=0; i<30; i++){
    //     vertex[i].print(vertex[i].getAbsolute().Y, vertex[i].getAbsolute().X, screen);
    //     refresh();
    //     // usleep(200000);
    //     // clear();
    // }

    // Vertex vertex(10, 10);
    // vertex.convert(screen);
    // vertex.print(1,2, screen);

    // Call this only when dealing with tests
    // screen.~Screen();
    // testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();
    return 0;
}