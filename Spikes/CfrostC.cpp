#include <iostream>

class fractalGrid {
public:

	/****************
	* Width functions
	*/
	void setWidth(int w);  // Set grid width
	int  getWidth(     );  // Return grid width

	/*****************
	* Height functions
	*/
	void setHeight(int h); // Set grid height
	int  getHeight(     ); // Return grid height

	/*****************************
	* Constructors and Destructors
	*/
	 fractalGrid(int gW, int gH);         // Class constructor
	~fractalGrid(              );         // Class destructor

private:

	int gridW     ; // The grid width
	int gridH     ; // The grid height
	int grid[][]; // the grid, a 2-dimensional integer array

};

/****************************
* Setter and Getter functions
*/
void fractalGrid::setWidth(int w) {
	this->gridW = w;
}

int fractalGrid::getWidth() {
	return this->gridW;
}

void fractalGrid::setHeight(int h) {
	this->gridH = h;
}

int fractalGrid::getHeight() {
	return this->gridH;
}

int main(int argc, char const *argv[])
{
	/**
	* Create a new fractalGrid
	*/





	/* code */
	return EXIT_SUCCESS;
}