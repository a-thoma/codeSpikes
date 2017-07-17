#include <iostream>
#include <fstream>
#include <random>
#include "FractalGrid.h"

// Generic FractalGrid constructor
FractalGrid::FractalGrid() {
	gridRows       = 256                                    ;
	gridCols       = 256                                    ;
	gridDensity    = 50                                     ;
	totalParticles = gridRows * gridCols / gridDensity      ;
	maxSteps       = (gridRows * gridCols) * 2              ;
	gridSeed       = 0                                      ;
	// gridArr        = new int*[gridRows]                     ; // Initialize our grid array
}

// Verbose FractalGrid constructor for two arguments
FractalGrid::FractalGrid(int rows, int cols) {
	gridRows       = rows                                   ;
	gridCols       = cols                                   ;
	gridDensity    = 50                                     ;
	totalParticles = gridRows * gridCols / gridDensity      ;
	maxSteps       = (gridRows * gridCols) * 2              ;
	gridSeed       = 0                                      ;
	// gridArr        = new int*[gridRows]                     ; // Initialize our grid array
}

// Verbose FractalGrid constructor for three arguments
FractalGrid::FractalGrid(int rows, int cols, int density) {
	gridRows       = rows                                   ;
	gridCols       = cols                                   ;
	gridDensity    = density                                ;
	totalParticles = gridRows * gridCols / gridDensity      ;
	maxSteps       = (gridRows * gridCols) * 2              ;
	gridSeed       = 0                                      ;
	// gridArr        = new int*[gridRows]                     ; // Initialize our grid array
}

// Verbose FractalGrid constructor for four arguments
FractalGrid::FractalGrid(int rows, int cols, int density, int seed) {
	gridRows       = rows                                   ;
	gridCols       = cols                                   ;
	gridDensity    = density                                ;
	totalParticles = gridRows * gridCols / gridDensity      ;
	maxSteps       = (gridRows * gridCols) * 2              ;
	gridSeed       = seed                                   ;
	// gridArr        = new int*[gridRows]                     ; // Initialize our grid array
}

// What am I doing with this? Should I leave this or do I call delete gridArr in main?
FractalGrid::~FractalGrid() {
	delete gridArr;
}

/********************************************************************
* Function that uilds the fractal within the grid itself. If an array
* element is not already a pointer to another array, calls
* newFractalColumn to create a "second-dimension" and then sets the
* element of that array.
*/
void FractalGrid::buildFractalGrid() {
	std::cout << "buildFractalGrid called" << std::endl; // placeholder

	/***************************************
	* Initialize the array of the grid here?
	*/

	this->gridArr = new int*[this->gridRows];

	/*****************************
*	* Get next position in the grid
	*/

	// Test print some values first

	std::cout << "Rows: "            << this->gridRows       << std::endl;
	std::cout << "Columns: "         << this->gridCols       << std::endl;
	std::cout << "Density: "         << this->gridDensity    << std::endl;
	std::cout << "Seed: "            << this->gridSeed       << std::endl;
	std::cout << "Total particles: " << this->totalParticles << std::endl;
	std::cout << "Maximum steps: "   << this->maxSteps       << std::endl;

	/****************
	* Set up the pRNG
	*/

	// Mersenne Twister engine with seed
	std::mt19937 gridEngine(this->gridSeed);

	// Number Distribution for gridRows, from 0 to gridRows as a max
	std::uniform_real_distribution<float> rowDist(0.0, (float)this->gridRows);
	// Number Distribution for gridCols, from 0 to gridCols as a max
	std::uniform_real_distribution<float> colDist(0.0, (float)this->gridCols);

	// We need two generated coordinates, but left uninitialized... or do we?
	int randRow;
	int randCol;

	/**
	* Is a for-loop really necessary? Could something be better?
	*/

	
	for (int i = this->totalParticles; i > 0; i--) {

		// Set our new grid coordinates
		randRow = rowDist(gridEngine);
		randCol = colDist(gridEngine);
			
		// std::cout << "randRow:" << randRow << std::endl; // Placeholder
		// std::cout << "randCol:" << randCol << std::endl; // Placeholder

		// Set the coordinate
		this->setGridValue(randRow, randCol);

	}

	// Finalize the grid, to make sure we didn't miss any columns
	this-> finalizeFractalGrid();

	// We're done

}

/******************************************************************
* Function to set the specified grid value. If the grid value is 0,
* it is set to 1. If it's already 1, it will check the grid values
* to the left, right, top, and bottom, and set one of them instead.
*/
void FractalGrid::setGridValue(int row, int col) {

	// Check if the element exists

	if (this->gridArr[row]) {
		//{ If we're here, here's already a grid column

		// Check if the element is zero
		if(this->gridArr[row][col] != 1) {

			// If it's not a 1, set it
			this->gridArr[row][col] = 1;
			// std::cout << this->gridArr[row][col] << std::endl; // Placeholder
		} else {
			/****************************************************************
			* There's already a 1, so check it's four neighbors (top, bottom,
			* left, right).
			*
			* POSSIBLE FIX: Modular Arithmetic to wrap the array indices?
			*/


				
			
				// Fix this. Need to check bounds of the array before anything.
				// this->setGridValue(row, col);     // Right
				// this->setGridValue(row, col);     // Left
				// this->setGridValue(row, col + 1); // Top
				// this->setGridValue(row, col - 1); // Bottom
			}

			// We're done checking the neighbors
		} else {
			// Otherwise, we need a new grid column
			this->newFractalColumn(row);
			
			// Call again
			this->setGridValue(row, col);
	}
}


/*************************************************************
* Function to return the value of a grid array element, either
* 0 or 1.
*/
int FractalGrid::getGridValue(int row, int col) {
	return this->gridArr[row][col];
}

/***********************************************************************
* Function to initialize a new array as an element of our initial array.
*/
void FractalGrid::newFractalColumn(int row) {
	this->gridArr[row] = new int[this->gridCols];
}

/**************************************************
* Function to print the entire grid in 2 dimensions (will be an outfile)
*/
void FractalGrid::printFractalGrid() {
	// To be implemented
	std::cout << "printFractalGrid Called" << std::endl;

	// Create an outfile
	std::ofstream myFile;
	// Try to open it, create it if not
	myFile.open("grid.txt"); 

	// Write the grid
	for (int i = 0; i < gridRows; i++) {       // Each row
		for (int j = 0; j < gridCols-1; j++) { // Each col
			myFile << this->gridArr[i][j];     // write the element at i,j
		}
		myFile << "\n";                        // end the row, start a new one
	}

	// Close the file
	myFile.close();
}

/*********************************************************************
* Function to finalize the grid array. This function checks for any
* uninitialized grid rows (i.e. rows that are not pointers to columns)
* and initializes them. Can be thought of as a sort of check to make
* sure we're not just printing a non-existent array element.
*/
void FractalGrid::finalizeFractalGrid() {

	// Loop through all the elements of the grid array
	for (int i = 0; i < gridRows; i++) {

		// Check if each element exists
		if (!this->gridArr[i]) {

			// If not, make a new column
			this->newFractalColumn(i);
			std::cout << "Didn't exist at row: " << i << std::endl;
		}
	}
}
