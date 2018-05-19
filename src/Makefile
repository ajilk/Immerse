TARGET 		= immerse
CXXFLAGS	= -std=c++11 -lncurses
CC			= g++

OBJFILES = main.o Screen.o Point.o Line.o

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJFILES)


main.o: main.cpp Screen.h
	$(CC) -c main.cpp
Screen.o: Screen.cpp Screen.h
	$(CC) -c Screen.cpp

clean:
	rm $(OBJ) $(OBJFILES)
run:
	./immerse