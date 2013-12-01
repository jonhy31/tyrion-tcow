CXX = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

all: tyrion_tcow

tyrion_tcow: main.o HexGrid.o	
	$(CXX) -o main main.o HexGrid.o $(LIBS)

main.o: main.cpp
	$(CXX) -c main.cpp

HexGrid.o: HexGrid.cpp
	$(CXX) -c HexGrid.cpp

clean:
	rm -r *.o 