// Thanks to my buddy Carlos for the help, these comments are his

#include <iostream>
#include "FractalGrid.h" // We need this here now

// Function Prototypes go here, This is so you can call them without having
// to define in order. C++ won't let you arbritrarily call functions like JAVA
// This is to fix that problem

void buildFractalGrid(int rows, int cols, FractalGrid* fg); // Also don't need scope resolution
void newFractalColumn(FractalGrid* fg);
void finalizeFractalGrid(int rows, int cols, FractalGrid* fg);

/*********************
* Main driver function
*/

int main(int argc, char const *argv[])
{

	/*****************************
	* Initialize a new fractalGrid
	*/

	/**********************
	* Build the fractalGrid
	*/

	/*************************
	* Finalize the fractalGrid
	*/

	/************************
	* Goodbye, fractalGrid...
	*/

	return EXIT_SUCCESS;
}