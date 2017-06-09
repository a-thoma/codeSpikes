#include <iostream>
#include <random>
#include "FractalGrid.h"

// Generic FractalGrid constructor
FractalGrid::FractalGrid() {
	gridRows       = 256                                    ;
	gridCols       = 256                                    ;
	gridDensity    = 50                                     ;
	totalParticles = ((float)gridRows    * (float)gridCols) *
	                 ((float)gridDensity / 100            ) ;
	maxSteps       = (gridRows * gridCols) * 2              ;
	gridSeed       = 0                                      ;
	gridArr        = new int[gridRows]                      ; // Initialize our grid array
}

// Verbose FractalGrid constructor for two arguments
FractalGrid::FractalGrid(int rows, int cols) {
	gridRows       = rows                                   ;
	gridCols       = cols                                   ;
	gridDensity    = 50                                     ;
	totalParticles = ((float)gridRows    * (float)gridCols) *
	                 ((float)gridDensity / 100            ) ;
	maxSteps       = (gridRows * gridCols) * 2              ;
	gridSeed       = 0                                      ;
	gridArr        = new int[gridRows]                      ; // Initialize our grid array
}

// Verbose FractalGrid constructor for three arguments
FractalGrid::FractalGrid(int rows, int cols, int density) {
	gridRows       = rows                                   ;
	gridCols       = cols                                   ;
	gridDensity    = density                                ;
	totalParticles = ((float)gridRows    * (float)gridCols) *
	                 ((float)gridDensity / 100            ) ;
	maxSteps       = (gridRows * gridCols) * 2              ;
	gridSeed       = 0                                      ;
	gridArr        = new int[gridRows]                      ; // Initialize our grid array
}

// Verbose FractalGrid constructor for four arguments
FractalGrid::FractalGrid(int rows, int cols, int density, int seed) {
	gridRows       = rows                                   ;
	gridCols       = cols                                   ;
	gridDensity    = density                                ;
	totalParticles = ((float)gridRows    * (float)gridCols) *
	                 ((float)gridDensity / 100            ) ;
	maxSteps       = (gridRows * gridCols) * 2              ;
	gridSeed       = seed                                   ;
	gridArr        = new int[gridRows]                      ; // Initialize our grid array
}

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

	/******************************
	* Get next position in the grid
	*/

	// Test print some values first

	std::cout << "Rows: "            << this->gridRows       << std::endl;
	std::cout << "Columns: "         << this->gridCols       << std::endl;
	std::cout << "Density: "         << this->gridDensity    << std::endl;
	std::cout << "Seed: "            << this->gridSeed       << std::endl;
	std::cout << "Total particles: " << this->totalParticles << std::endl;
	std::cout << "Maximum steps: "   << this->maxSteps       << std::endl;

	/**
	* Will either pass two random number generators to this function for
	* recursion purposes, or run a loop in this function.
	*/

	/****************
	* Set up the pRNG
	*/

	// Mersenne Twister engine with seed
	std::mt19937 gridEngine(this->gridSeed);

	// Number Distribution, from 0 to maxSteps
	std::uniform_real_distribution<float> gridDist(0.0, (float)this->maxSteps);

	/**
	* Is a for-loop really necessary? Could something be better?
	*/
	for (int i = 0; i < this->totalParticles; i++) {
		/*************************************
		* Check if the particle is already set
		*/


	}


}

/***********************************************************************
* Function to initialize a new array as an element of our initial array.
*/
void FractalGrid::newFractalColumn() {
	// To be implemented
}

/*********************************************************************
* Function to finalize the grid array. This function checks for any
* uninitialized grid rows (i.e. rows that are not pointers to columns)
* and initializes them. Can be thought of as a sort of check to make
* sure we're not just printing a non-existent array element.
*/
void FractalGrid::finalizeFractalGrid() {
	// To be implemented
}
