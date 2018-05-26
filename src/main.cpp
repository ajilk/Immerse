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
// void line(Vertex v1, Vertex v2, Screen& screen){
//     // calculate dx & dy
//     int dx = v2.getCartesian().X - v1.getCartesian().X;
//     int dy = v2.getCartesian().Y - v1.getCartesian().Y;
 
//     // calculate steps required for generating pixels
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
//     // calculate increment in x & y for each steps
//     float Xinc = dx / (float) steps;
//     float Yinc = dy / (float) steps;
 
//     // Put pixel for each step
//     float X = v1.getCartesian().X;
//     float Y = v1.getCartesian().Y;
//     for (int i = 0; i <= steps; i++)
//     {
// 		screen.putch(Y, X, '.');// put pixel at (X,Y)
//         X += Xinc;           // increment in x at each step
//         Y += Yinc;           // increment in y at each step
//                              // generation step by step
//     }
// }

int main(int argc, char **argv){
    Screen screen;
	Vertex v1(10, 1, 0);
	Vertex v2(1, 10, 0);
	// line(v1, v2, screen);
	// refresh();

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