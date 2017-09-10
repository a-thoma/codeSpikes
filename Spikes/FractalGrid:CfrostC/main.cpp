#include <iostream>
#include "FractalGrid.h"

/********************************************
* Declare Prototypes from FractalGrid we need
*/

void initFractalGrid();
void buildFractalGrid   ();
void printFractalGrid   ();

/*********************
* Main driver function
*/

int main(int argc, char const *argv[]) {

	/*****************
	* Define constants
	*/

	const std::string argStr   = "Error: Too few/many arguments.";
	const std::string usageStr = "Usage: ""./CfrostC""\n"
							     "       ""./CfrostC <Row count> <Column count>""\n"
							     "       ""./CfrostC <Row count> <Column count> <Density>""\n"
							     "       ""./CfrostC <Row count> <Column count> <Density> <Seed>";

	std::cout << "argc: " << argc << std::endl; // Placeholder

	/*****************************
	* Initialize a new fractalGrid
	*/

	FractalGrid* mainGrid;

	// If we have arguments for dimensions, take them in

	if (argc < 6) {

		// If we're here, we've got a good amount of arguments.

		switch(argc) {

			case 1:

				// Create a generic-argument FractalGrid
				mainGrid = new FractalGrid();

				// std::cout << "None specified, generic" << std::endl; // Placeholder

				// We're done
				break;

			case 3:

				// Create a two-argument FractalGrid
				mainGrid = new FractalGrid(std::atoi(argv[1]),
										   std::atoi(argv[2]));

				std::cout << "Rows and Columns specified" << std::endl; // Placeholder

				// We're done
				break;


			case 4:

				// Create a three-argument FractalGrid
				mainGrid = new FractalGrid(std::atoi(argv[1]),
										   std::atoi(argv[2]),
										   std::atoi(argv[3]));

				std::cout << "Rows, Columns, and Density specified" << std::endl; // Placeholder

				// We're done
				break;

			case 5:

				// Create a four-argument FractalGrid
				mainGrid = new FractalGrid(std::atoi(argv[1]),
										   std::atoi(argv[2]),
										   std::atoi(argv[3]),
										   std::atoi(argv[4]));

				std::cout << "Rows, Columns, Density, and Seed specified" << std::endl; // Placeholder

				// We're done
				break;

		}

	} else {
		// Print the error
		std::cout << argStr    << std::endl;
		std::cout << usageStr  << std::endl;
	}

	/**
	* Initialize the fractalGrid
	*/

	mainGrid->initFractalGrid();

	/**********************
	* Build the fractalGrid
	*/

	mainGrid->buildFractalGrid();

	/**********************
	* Print the FractalGrid (should be to an outfile at some point)
	*/

	mainGrid->printFractalGrid();

	/************************
	* Goodbye, fractalGrid...
	*/

	// for (int i = 0; i < mainGrid->totalParticles; i++) {
	// 	delete[] mainGrid->gridArr[i];
	// }
	delete mainGrid;

	return EXIT_SUCCESS;
}