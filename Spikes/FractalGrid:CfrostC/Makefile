# begin makefile

CXX = g++

CXXFLAGS = -Wall -g

main: main.o FractalGrid.o
	$(CXX) $(CXXFLAGS) -o main main.o FractalGrid.o FractalGrid.h

main.o: main.cpp FractalGrid.h
	$(CXX) $(CXXFLAGS) -c main.cpp

FractalGrid.o: FractalGrid.h

cleanall:
	rm -f main
	rm -f main.o
	rm -f FractalGrid.o
	rm -f grid.txt