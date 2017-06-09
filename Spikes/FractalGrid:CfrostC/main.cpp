// Thanks to my buddy Carlos for the help, these comments are his

#include <iostream>
#include <sstream>
#include "FractalGrid.h" // We need this here now

// Function Prototypes go here, This is so you can call them without having
// to define in order. C++ won't let you arbritrarily call functions like JAVA
// This is to fix that problem
// Also don't need scope resolution.

void buildFractalGrid   ();
void newFractalColumn   ();
void finalizeFractalGrid();

/*********************
* Main driver function
*/

int main(int argc, char const *argv[]){
	
	/*****************
	* Define constants
	*/
	
	std::stringstream ss;

	const std::string argStr   = "Error: Too few/many arguments.";
	const std::string usageStr = "Usage: ""./CfrostC\n\t./CfrostC <Row count> <Column count>\n\t./CfrostC <Row count> <Column count> <Density>";
	
	// Check to see if there is an invalid number of arguments
	if(argc > 4){
		
		// There isn't
		// Declare the pointer within the scope of the if statement
		FractalGrid* mainGrid;
		
		// Check the argument count
		switch(argc){
			
			// One argument
			case 1: 

				// Print out the string
				std::cout << "None specified, generic" << std::endl; 
				// Instantiate the grid
				mainGrid = new FractalGrid();
				// Leave
				break;
			
			// Two arguments
			case 2: 

				// Print out the string
				std::cout << "Rows and Columns specified" << std::endl; 
				// Instantiate the grid
				mainGrid = new FractalGrid(std::atoi(argv[0]),
						           std::atoi(argv[1]));
				// Leave
				break;

			// Three Arguments
			case 3: 

				// Print out the string
				std::cout << "Rows, Columns, and Density specified" << std::endl; 
				// Instantiate the grid
				mainGrid = new FractalGrid(std::atoi(argv[0]),
						           std::atoi(argv[1]),
						           std::atoi(argv[2]));
				// Leave
				break;

			// If something goes wrong
			default:
			
				// We default to the main constructor
				mainGrid = new FractalGrid();
				
		}
		
		
		/**********************
		* Build the fractalGrid
		*/

		mainGrid->buildFractalGrid();


		/*************************
		* Finalize the fractalGrid
		*/
		
		// After we play, we clean up our toys
		delete mainGrid;

	} else {
		
		// Invalid number of arguments
		// Print the error
		std::cout << argStr    << std::endl;
		std::cout << usageStr  << std::endl;
		
	}
	
	// No return code
	return EXIT_SUCCESS;

}
