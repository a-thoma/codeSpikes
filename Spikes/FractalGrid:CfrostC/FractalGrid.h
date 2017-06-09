// Thanks to my buddy Carlos for the help, these comments are his

/**
 * Fractal Grid class goes in its' own header
 * keep private on top, because it's generally neater to do so.
 * The Constructor and Deconstructor should also be declared in the cpp
 */

/**
 * We use these pre processor directives to make sure your class
 * name (and definition) doesn't clash with anothers in the same namespace
 * or even namespace std
 */

#ifndef FRACTAL_GRID_H
#define FRACTAL_GRID_H

class FractalGrid {

private:

	// This should have the pRNGs for the building step, added later...

public:

	/**********
	* Variables
	*/

	int  gridCols         ; // The number of columns in the grid array
	int  gridRows         ; // The number of rows in the grid array
	int  gridDensity      ; // The percentage of the grid to be filled
	int  totalParticles   ; // The total number of spaces to be filled
	int  maxSteps         ; // The maximum number of steps until filled
	int  gridSeed         ; // The seed for the grid's coordinate generator
	int* gridArr          ; // The pointer to the grid array

	/***********************
	* Constructor/Destructor
	*/

	// Define here, implement them in the other file
	FractalGrid (                               );
	FractalGrid (int rows, int cols             );
	FractalGrid (int rows, int cols, int density);
	~FractalGrid(                               );

	/**********
	* Functions
	*/

	/**
	* Same with these. You also don't need the scope accessor operator
	* e.g. FractalGrid::FractalGrid when defining a parameter of the same
	* type (this class)
	*/

	void buildFractalGrid   (                 );
	void newFractalColumn   (                 );
	void finalizeFractalGrid(                 );

};

#endif