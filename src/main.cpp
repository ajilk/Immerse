#include <ncurses.h>
#include <gtest/gtest.h>
#include "Screen.h"
#include "Point.h"
#include "tests/main.h"

int add(int x, int y){
    return x+y;
}

int main(int argc, char **argv){
    Screen screen;
    screen.~Screen();
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}