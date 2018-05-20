#include <ncurses.h>
#include <gtest/gtest.h>
#include "Screen.h"
#include "Point.h"
// #include "tests/test.h"

int main(int argc, char **argv){
    Screen screen;
    Point point(10, 10);
    point.convert(screen);
    point.print(1,2, screen);

    // Call this only when dealing with tests
    // screen.~Screen();
    // testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();
    return 0;
}