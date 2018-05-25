TARGET 		= immerse
CXXFLAGS	= -std=c++11 -lncurses
FLAGS		= -lgtest -lpthread
CC			= g++

OBJFILES = main.o Screen.o Vertex.o

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(CXXFLAGS) $(OBJFILES) $(FLAGS)


main.o: main.cpp Screen.h
	$(CC) -c main.cpp
Screen.o: Screen.cpp Screen.h
	$(CC) -c Screen.cpp
Vertex.o: Vertex.cpp Vertex.h
	$(CC) -c Vertex.cpp

clean:
	rm $(TARGET) $(OBJFILES)
run:
	./immerse
