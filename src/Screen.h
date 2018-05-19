#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <stdlib.h>	//exit()

class Screen{
private:
	int rows;
	int columns;
public:
	Screen();
	int getRows();
	int getColumns();
	bool kbhit();
	void putch(int Y, int X, char ch);
	~Screen();
};

#endif
