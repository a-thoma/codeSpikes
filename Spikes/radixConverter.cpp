/*****************************************************************************
 * Radix Converter: given a radix-base number, convert to decimal
 *
 * Usage: "./radixConverter <base 2-16> <number to convert (within 8 digits)>"
 * i.e.:  "./radixConverter 2 0101101" spits out "45"
 */
// TODO: fix getDigits to work for base 11 and up (alphanumeric).
// TODO: finish recursive conversion (no for loop).

#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdio.h>

/******************************************************
 * Given base number and vector of digits, convert from
 * n-radix to decimal number and return it.
 */
int radixConversion(int baseNum, std::vector<int>* digits) {
    // Declare variables
    int result  = 0; // Result variable, initially zero
    int current = 0; // Current variable, initially zero
    int mult    = 1; // Multiplier variable, initially one

    /**
     * Recurse through the vector,
     * add to total, and return.
     */

    for (int i = digits->size() - 1; i >= 0; i--) { // starting from MSB and moving down

        current = digits->at(i);  // Grab next digit
        result += current * mult; // Add converted digit to our result
        mult   *= baseNum;        // Increment our multiplier
    }

    // We're done, return what we have
    return result;
}

/***************************************************
 * Recursive form of radixConversion method, for fun
 */

int radixConvRecursion(short baseNum, std::vector<int>* digits) {

    return 0;
}

/****************************************************
 * get individual digits and place them into a vector
 */
void getDigits(int convNum, std::vector<int>* digits) {
  // check if there's still a number to grab
  if (convNum > 9) {
    
    // recurse through the number if there are no more digits to grab
    getDigits((convNum / 10), digits);  
  }

  // grab a digit and push it back into the digit vector
  digits->push_back(convNum % 10);
}

/************************
 * Main of radixConverter
 */

int main(int argc, const char* argv[]) {
    
    /************************
     * Error Message Constant
     */
    
    const std::string ARG_ERROR = "ERROR: too few arguments.";
    const std::string USE_ERROR = "USAGE: ./radixConverter <base 0-n> <number to convert>";
    
    /**************************
     * Check the Argument Count
     */
    
    if(argc != 3) {
        
        // Arguments are less than three, Print the Message
        std::cout << ARG_ERROR << std::endl;
        
    } else {
        
        // We got the right amount of arguments
        int radixBase = std::atoi(argv[1]); // the radix
        int radixNum  = std::atoi(argv[2]); // the number itself

        /**********************
         * Check the Radix Base
         */
        
        if(radixBase > 16 || radixBase < 2) { std::cout << USE_ERROR << std::endl;}

         /************************************
          * Create a vector and call getDigits
          */

        std::vector<int>* numVec = new std::vector<int>(0); // Declare our vector and initialize it as empty
        getDigits(radixNum, numVec);                        // getDigits function call

        /************************************************
         * Print details, print radixConversion, and exit
         */

        std::cout << "Base:       " << radixBase << std::endl ; // Print the base
        std::cout << "Number:     " << radixNum  << std::endl ; // Print the number
        std::cout << "In base 10: " << radixConversion(radixBase, numVec) << std::endl; // radixConversion function call, and printing the result

    
    }

    return EXIT_SUCCESS; // Return EXIT_SUCCESS (0)

}
