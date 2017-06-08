#include <iostream>

class fractalGrid {
public:

	/**********
	* Variables
	*/

	static int  gridCols         ; // The number of columns in the grid array
	static int  gridRows         ; // The number of rows in the grid array
	static int  gridDensity      ; // The percentage of the grid to be filled
	       int* gridArr          ; // The pointer to the grid array

	/***********************
	* Constructor/Destructor
	*/

	fractalGrid(int rows, int cols, int density) {
		gridRows    = rows             ;
		gridCols    = cols             ;
		gridDensity = density          ;
		gridArr     = new int[gridRows]; // Initialize our grid array
	}

	~fractalGrid() {
		delete gridArr;
	}

	/**********
	* Functions
	*/

	void buildFractalGrid   (int rows, int cols, fractalGrid::fractalGrid* fg);
	void newFractalColumn   (fractalGrid::fractalGrid* fg                    );
	void finalizeFractalGrid(int rows, int cols, fractalGrid::fractalGrid* fg);

private:

	// This should have the pRNGs for the building step, added later...

};

/**********************************************************************
* Builds the fractal within the grid itself. If an array element is not
* already a pointer to another array, calls newFractalColumn to create
* a "second-dimension" and then sets the element of that array.
*/
void buildFractalGrid(int rows, int cols, fractalGrid::fractalGrid* fg) {

}

/**********************************************************************
* Function to initialize a new array as an element of our initial array
*/
void newFractalColumn(fractalGrid::fractalGrid* fg) {

}

/*********************************************************************
* Function to finalize the grid array. This function checks for any
* uninitialized grid rows (i.e. rows that are not pointers to columns)
* and initializes them. Can be thought of as a sort of check to make
* sure we're not just printing a non-existent array element.
*/
void finalizeFractalGrid(int rows, int cols, fractalGrid::fractalGrid* fg) {

}
/*********************
* Main driver function
*/

int main(int argc, char const *argv[])
{

	/************************
	* Build a new fractalGrid
	*/

	/**
	*
	*/









	return EXIT_SUCCESS;
}