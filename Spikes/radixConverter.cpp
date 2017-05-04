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

// given an integer, convNum, convert the integer into a vector of each individual digits
void getDigits(int convNum, std::vector<int>& digits) {
  if (convNum > 9) { // check if the number has more than one digit
    getDigits((convNum / 10), digits); // recurse through the number if there are more digits to grab
  }
  digits.push_back(convNum % 10); // grab a digit and put it in the digit vector
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //error checking
    int errCode = 0;
    
    // error checking...
    std::string errString1  = "ERROR: too few arguments.";
    std::string usageString = "USAGE: ./radixConverter <base 0-n> <number to convert>";
    if(argc < 3) { // if too few args, we're done.
        errCode = 1; // errCode of 1 means too few args.
        goto errLabel;
    } else { // otherwise get the first argument as the radix
      int radixBase = std::atoi(argv[1]); // the radix
      int radixNum = std::atoi(argv[2]); // the number itself
        std::cout << radixBase << std::endl; // testing
	std::cout << radixNum << std::endl; // testing
        std::cout << errCode << std::endl; // testing
        if(radixBase > 16 || radixBase < 2) {
            errCode = 2; // errCode of 2 means the radix is out of bounds
            goto errLabel; // we're done with an error, so go to the end
        }
    }
    // pass arguments to conversion method
    
    return 0; // and we're done!
    
    // error checking
errLabel:
    if(errCode > 0) { // errCode of anything other than 0 means something went wrong
// TODO: add errCode functionality (i.e. 1 = too few args, 2 = radix oob, etc)
        // std::cout << errString1  << std::endl;
        std::cout << usageString << std::endl;
    }
    return 0;
}
