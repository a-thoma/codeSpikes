#ifndef FRACTAL_GRID_H
#define FRACTAL_GRID_H

class FractalGrid {

private:

	// Nothing here!

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

	FractalGrid (                                         );
	FractalGrid (int rows, int cols                       );
	FractalGrid (int rows, int cols, int density          );
	FractalGrid (int rows, int cols, int density, int seed);
	~FractalGrid(                                         );

	/**********
	* Functions
	*/

	void buildFractalGrid   (                 );
	void newFractalColumn   (                 );
	void finalizeFractalGrid(                 );

};

#endif