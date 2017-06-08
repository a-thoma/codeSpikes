// Thanks to my buddy Carlos for the help, these comments are his

#include <iostream>
#include "FractalGrid.h" // We need this here now

// Function Prototypes go here, This is so you can call them without having
// to define in order. C++ won't let you arbritrarily call functions like JAVA
// This is to fix that problem
// Also don't need scope resolution.

void buildFractalGrid   (FractalGrid* fg);
void newFractalColumn   (FractalGrid* fg);
void finalizeFractalGrid(FractalGrid* fg);

/*****************
* Define constants
*/

const std::string argStr   = "Error: Too few/many arguments.";
const std::string usageStr = "Usage: ""./CfrostC""\n"
						     "       ""./CfrostC <Row count> <Column count>""\n"
						     "       ""./CfrostC <Row count> <Column count> <Density>";

/*********************
* Main driver function
*/

int main(int argc, char const *argv[])
{

	/*****************************
	* Initialize a new fractalGrid
	*/

	// If we have arguments for dimensions, take them in
	if (argc == 1) {

		// Create a generic-argument FractalGrid
		FractalGrid* mainGrid = new FractalGrid();

		std::cout << "None specified, generic" << std::endl;
	} else if (argc == 3) {
		
		// Create a two-argument FractalGrid
		FractalGrid* mainGrid = new FractalGrid(std::atoi(argv[0]),
										        std::atoi(argv[1]));

		std::cout << "Rows and Columns specified" << std::endl;

	} else if (argc == 4) {

		// Create a three-argument FractalGrid
		FractalGrid* mainGrid = new FractalGrid(std::atoi(argv[0]),
											    std::atoi(argv[1]),
											    std::atoi(argv[2]));

		std::cout << "Rows, Columns, and Density specified" << std::endl;

	} else {
		// Print the error
		std::cout << argStr    << std::endl;
		std::cout << usageStr  << std::endl;
	}

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