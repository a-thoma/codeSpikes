// Thanks to my buddy Carlos for the help, these comments are his

#include <iostream>
#include "FractalGrid.h"
/**
* We use the scope resolution operator to define the methods.
* Its important to know, that the header-definition pattern
* won't work unless you do this. You break the program if you
* don't put in the 'FractalGrid::'.
* Yes, even with constructors.
*/

// Generic FractalGrid constructor
FractalGrid::FractalGrid() {
	gridRows    = 256;
	gridCols    = 256;
	gridDensity = 50 ;
	gridArr     = new int[gridRows]; // Initialize our grid array
}

// Verbose FractalGrid constructor
FractalGrid::FractalGrid(int rows, int cols, int density) {
	gridRows    = rows             ;
	gridCols    = cols             ;
	gridDensity = density          ;
	gridArr     = new int[gridRows]; // Initialize our grid array
}

FractalGrid::~FractalGrid() {
	delete gridArr;
}

/**********************************************************************
* Builds the fractal within the grid itself. If an array element is not
* already a pointer to another array, calls newFractalColumn to create
* a "second-dimension" and then sets the element of that array.
*/
void FractalGrid::buildFractalGrid(int rows, int cols, FractalGrid* fg) {
	// To be implemented
}

/**********************************************************************
* Function to initialize a new array as an element of our initial array
*/
void FractalGrid::newFractalColumn(FractalGrid* fg) {
	// To be implemented
}

/*********************************************************************
* Function to finalize the grid array. This function checks for any
* uninitialized grid rows (i.e. rows that are not pointers to columns)
* and initializes them. Can be thought of as a sort of check to make
* sure we're not just printing a non-existent array element.
*/
void FractalGrid::finalizeFractalGrid(int rows, int cols, FractalGrid* fg) {
	// To be implemented
}
