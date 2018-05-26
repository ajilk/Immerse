TARGET 		= immerse
CXXFLAGS	= -std=c++11 
LDFLAGS		= -lncurses -lgtest -lpthread
CC			= g++

OBJFILES = main.o Screen.o Vertex.o

$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(OBJFILES) $(LDFLAGS) $(CXXFLAGS) 


main.o: main.cpp Screen.h
	$(CC) -c main.cpp $(CXXFLAGS)
Screen.o: Screen.cpp Screen.h
	$(CC) -c Screen.cpp $(CXXFLAGS)
Vertex.o: Vertex.cpp Vertex.h
	$(CC) -c Vertex.cpp $(CXXFLAGS)

clean:
	rm $(TARGET) $(OBJFILES)
run:
	./immerse
