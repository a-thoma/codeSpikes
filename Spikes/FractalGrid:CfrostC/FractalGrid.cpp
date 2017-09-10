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
	// delete gridArr;
}

/**
* Function that initilalizes all of the grid elements.
*/
void FractalGrid::initFractalGrid() {

	std::cout << "initFractalGrid called" << std::endl; // placeholder

	/***************************************
	* Initialize the array of the grid here?
	*/

	this->gridArr = new int*[this->gridRows];

	for (int i = 0; i < this->gridRows - 1; i++) {

		this->gridArr[i] = new int[this->gridCols];

		for (int j = 0; j < this->gridCols - 1; j++) {

			this->gridArr[i][j] = 0;
		}
	}

}

/********************************************************************
* Function that uilds the fractal within the grid itself. If an array
* element is not already a pointer to another array, calls
* newFractalColumn to create a "second-dimension" and then sets the
* element of that array.
*/
void FractalGrid::buildFractalGrid() {
	std::cout << "buildFractalGrid called" << std::endl; // placeholder

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
			
		std::cout << "randRow:" << randRow << std::endl; // Placeholder
		std::cout << "randCol:" << randCol << std::endl; // Placeholder

		std::cout << "i = " << i << std::endl;

		// Set the coordinate and get the remaining repititions
		int rep = this->setGridValue(randRow, randCol, i, false);

		// Update our iter just in case it changed
		if(rep < i) {

			// Update our i
			i = rep;
		}
	}

	// We're done
}

/******************************************************************
* Function to set the specified grid value. If the grid value is 0,
* it is set to 1. If it's already 1, it will check the grid values
* to the left, right, top, and bottom, and set one of them instead.
*/
// TODO: Rework this without it being a jagged array.
int FractalGrid::setGridValue(int row, int col, int rep, bool rec) {

	// Check if the element is zero
	if(this->gridArr[row][col] != 1) {

		// If it's not a 1, set it
		this->gridArr[row][col] = 1;

		// std::cout << this->gridArr[row][col] << std::endl; // Placeholder
	} 

	/****************************************************************
	* There's already a 1, so check it's four neighbors (top, bottom,
	* left, right) and set them to 1.
	*/

	if(rec == false) {

		// We've already recursed once, so set N/E/S/W nodes to 1.
		
		// Wraparound
		if((row - (gridRows - 1)) > 0) row = row - gridRows; // Row wrap
		if((col - (gridCols - 1)) > 0) col = col - gridCols; // Col wrap

		// Right
		this->setGridValue(row + 1, col, rep, true);
		rep--;
		// std::cout << "Set right of " << row << ", " << col << std::endl;

		// Left
		this->setGridValue(row - 1, col, rep, true);
		rep--;
		// std::cout << "Set left of " << row << ", " << col << std::endl;

		// Top
		this->setGridValue(row, col + 1, rep, true);
		rep--;
		// std::cout << "Set top of " << row << ", " << col << std::endl;

		// Bottom
		this->setGridValue(row, col - 1, rep, true);
		rep--;
		// std::cout << "Set bottom of " << row << ", " << col << std::endl;
	}

	return rep;
}


/*************************************************************
* Function to return the value of a grid array element, either
* 0 or 1.
*/
int FractalGrid::getGridValue(int row, int col) {
	return this->gridArr[row][col];
}

/**************************************************
* Function to print the entire grid in 2 dimensions (will be an outfile)
*/
void FractalGrid::printFractalGrid() {

	//TODO: I want this as a PPM file, preferably. Or something else bitmap-related.

	std::cout << "printFractalGrid Called" << std::endl;

	// Create an outfile
	std::ofstream myFile;

	// Try to open it, create it if not
	myFile.open("grid.txt"); 

	// Write the grid.
	for (int i = 0; i < gridRows; i++) {
		for (int j = 0; j < gridCols-1; j++) {

			// print out the element at i,j
			myFile << this->gridArr[i][j];
		}

		// End the row, make a new one
		myFile << "\n";
	}

	// Close the file
	myFile.close();
}