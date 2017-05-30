/*****************************************************************************
 * Radix Converter: given a radix-base number, convert to decimal
 *
 * Usage: "./radixConverter <base 2-16> <number to convert (within 8 digits)>"
 * i.e.:  "./radixConverter 2 0101101" spits out "45"
 */

// TODO: finish recursive conversion (no for loop).
// TODO: expand upper bounds of the number to convert. (Just label it?)

#include <iostream>
#include <vector>

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
 * Takes a string, converts each individual character
 * into an integer value, (i.e. A = 10, B = 11, etc.)
 * and pushes it into the digit vector.
 */

void getChars(std::string convStr, std::vector<int>* digits) {

    /**********************
     * Loop through convStr
     */
    
     for( int i = 0; i < convStr.length(); i++) {

    /***********************************
     * Convert char -> int and push back
     */

     if(convStr.at(i) <= '9') {

        digits->push_back(convStr.at(i) - '0');     // Put it in the vector
        } else if(convStr.at(i) <= 'F') {

            digits->push_back(convStr.at(i) - '7'); // Uppercase ASCII values
            } else {

            digits->push_back(convStr.at(i) - 'W'); // Lowercase ASCII values
        }
    }
}

/************************
 * Main of radixConverter
 */

int main(int argc, const char* argv[]) {
    
    /************************
     * Error Message Constant
     */
    
    const std::string ARG_ERROR = "ERROR: too few arguments.";
    const std::string USE_ERROR = "USAGE: ./radixConverter <base 2-16> <number to convert (up to 8 digits)>";
    
    /**************************
     * Check the Argument Count
     */
    
    if(argc != 3) {
        
        // Arguments are less than three, Print the Message
        std::cout << ARG_ERROR << std::endl;
        
    } else {
        
        // We got the right amount of arguments
        int radixBase         = std::atoi(argv[1]); // the radix
        std::string radixStr  = argv[2];            // the number

        /**********************
         * Check the Radix Base
         */
        
        if(radixBase > 16 || radixBase < 2) { std::cout << USE_ERROR << std::endl;} else {

             /************************************
              * Create a vector and call getDigits
              */

            std::vector<int>* numVec = new std::vector<int>(0);
            getChars(radixStr, numVec);

            /************************************************
             * Print details, print radixConversion, and exit
             */

            std::cout << "Base:       " << radixBase << std::endl ; // Print the base
            std::cout << "Number:     " << radixStr  << std::endl ; // Print the number
            std::cout << "In base 10: " << radixConversion(radixBase, numVec) << std::endl; // radixConversion function call, and printing the result
        }

    }

    return EXIT_SUCCESS; // Return EXIT_SUCCESS (0)
}
