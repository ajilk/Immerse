#include <ncurses.h>
#include <gtest/gtest.h>
#include "Screen.h"
#include "Point.h"

int add(int x, int y){
    return x+y;
}

TEST(FirstTest, AdditionTest){
    ASSERT_EQ(10, add(5,5));
}
 
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}