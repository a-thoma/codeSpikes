/*
 Radix Converter: given a radix-base number, convert to decimal
 
 Usage: "./radixConverter <base 2-16> <number to convert (within 8 digits)>"
 i.e.:  "./radixConverter 2 0101101" spits out "45"
 */

// TODO: finish error checking
// TODO: finish conversion.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdio.h>

/******************************************************
 * given base number and vector of digits, convert from
 * n-radix to decimal number and return it
 */
int radixConversion(int baseNum, std::vector<int>& digits) {
// TODO: finish radixConversion method
    // convert convNum from an integer to a vector
    // declare storage for each individual digit
    //  int vecSize = digits.size(); // vector size
    //   for (int i = 0; i < vecSize; i++) {
    // convert and store here
    //}
    return 0;
}

/***************************************************
 * get individual digits and place them into a vector
 */
void getDigits(int convNum, std::vector<int>& digits) {
  // check if there's still a number to grab
  if (convNum > 9) {
    
    // recurse through the number if there are no more digits to grab
    getDigits((convNum / 10), digits);  
  }

  // grab a digit and push it back into the digit vector
  digits.push_back(convNum % 10);
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
        short radixBase = std::atoi(argv[1]); // the radix
        int   radixNum  = std::atoi(argv[2]); // the number itself
        
        std::cout << radixBase << std::endl ; // Print the base
        std::cout << radixNum  << std::endl ; // Print the number
        
        /**********************
         * Check the Radix Base
         */
        
        if(radixBase > 16 || radixBase < 2) { std::cout << USE_ERROR << std::endl;}
        
    }
    
    
    return EXIT_SUCCESS; // Return EXIT_SUCCESS (0)

}
