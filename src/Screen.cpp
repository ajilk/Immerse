#include "Screen.h"

Screen::Screen(){
	initscr();
	getmaxyx(stdscr, rows, columns);
	curs_set(0);
	nodelay(stdscr, TRUE);
	cbreak();
	noecho();
	use_default_colors();
	border(ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, 
			ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);

	//Check if there is support for color
	if(!has_colors()){
		clear();
		mvprintw(0,0,"ERROR: TERMINAL DOES NOT SUPPORT COLOR");
		refresh();
		getch();
		endwin();
		exit (EXIT_FAILURE);
	}else if(!can_change_color()){
		clear();
		mvprintw(0,0,"ERROR: TERMINAL CAN NOT CHANGE COLOR");
		refresh();
		getch();
		endwin();
		exit (EXIT_FAILURE);	
	}else
		start_color();
}

int Screen::getRows(){
	return rows;
}

int Screen::getColumns(){
	return columns;
}

bool Screen::kbhit(){
	int ch=getch();
	if(ch != ERR){
		ungetch(ch);
		return true;
	}
	else
		return false;
}

void Screen::putch(int Y, int X, char ch){
	init_pair(1, COLOR_RED, COLOR_RED);
	attron(COLOR_PAIR(1));
	mvaddch(Y, X, ch); 
	attroff(COLOR_PAIR(1));
}

Screen::~Screen(){
	refresh();
	nodelay(stdscr, FALSE);
	// getch();
	endwin();
}
