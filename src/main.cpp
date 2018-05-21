#include <ncurses.h>
#include <gtest/gtest.h>
#include <unistd.h>
#include "Screen.h"
#include "Point.h"
// #include "tests/test.h"

int main(int argc, char **argv){
    Screen screen;
    Point point[30];
    // for(int i=-15; i<15; i++){
    //     point[i+15] = *(new Point(i+15, i*i + 4*i + 2));
    //     point[i+15].convert(screen);
    //     point[i+15].print(point[i+15].getAbsolute().Y, point[i+15].getAbsolute().X, screen);
    //     refresh();
    // }

    point[0].convert(screen);
    for(int i=1; i<30; i++){
        point[i] = *(new Point(point[i-1].getCartesian().Y-1, point[i-1].getCartesian().X-10));
        point[i].convert(screen);
    }
    for(int i=0; i<30; i++){
        point[i].print(point[i].getAbsolute().Y, point[i].getAbsolute().X, screen);
        refresh();
        // usleep(200000);
        // clear();
    }

    // Point point(10, 10);
    // point.convert(screen);
    // point.print(1,2, screen);

    // Call this only when dealing with tests
    // screen.~Screen();
    // testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();
    return 0;
}