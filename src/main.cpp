#include <ncurses.h>
#include <gtest/gtest.h>
#include <unistd.h>
#include "Screen.h"
#include "Vertex.h"
// #include "tests/test.h"

int main(int argc, char **argv){
    Screen screen;
    Vertex vertex[30];
    // for(int i=-15; i<15; i++){
    //     vertex[i+15] = *(new Vertex(i+15, i*i + 4*i + 2));
    //     vertex[i+15].convert(screen);
    //     vertex[i+15].print(vertex[i+15].getAbsolute().Y, vertex[i+15].getAbsolute().X, screen);
    //     refresh();
    // }

    vertex[0].convert(screen);
    for(int i=1; i<30; i++){
        vertex[i] = *(new Vertex(vertex[i-1].getCartesian().Y-1, vertex[i-1].getCartesian().X-10));
        vertex[i].convert(screen);
    }
    for(int i=0; i<30; i++){
        vertex[i].print(vertex[i].getAbsolute().Y, vertex[i].getAbsolute().X, screen);
        refresh();
        // usleep(200000);
        // clear();
    }

    // Vertex vertex(10, 10);
    // vertex.convert(screen);
    // vertex.print(1,2, screen);

    // Call this only when dealing with tests
    // screen.~Screen();
    // testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();
    return 0;
}