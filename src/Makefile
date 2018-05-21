TARGET 		= immerse
CXXFLAGS	= -std=c++11 -lncurses
FLAGS		= -lgtest -lpthread
CC			= g++

OBJFILES = main.o Screen.o Point.o

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJFILES) $(FLAGS)


main.o: main.cpp Screen.h
	$(CC) -c main.cpp
Screen.o: Screen.cpp Screen.h
	$(CC) -c Screen.cpp
Point.o: Point.cpp Point.h
	$(CC) -c Point.cpp

clean:
	rm $(TARGET) $(OBJFILES)
run:
	./immerse
