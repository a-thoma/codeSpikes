//
//  main.cpp
//  radixConverter
//
/*
 Radix Converter: given a radix-base number, convert to decimal
 
 Usage: "./radixConverter <base 2-16> <number to convert (within 8 digits)>"
 i.e.:  "./radixConverter 2 0101101" spits out "45"
 */
// TODO: finish error checking
// TODO: finish conversion.

#include <iostream>

int radixConversion(int baseNum, int convNum) {
// TODO: finish radixConversion method
    // convert convNum from an integer to an array of integers
    
    return 0;
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
        int radixBase = atoi(argv[1]);
        std::cout << radixBase << std::endl;
        std::cout << errCode << std::endl;
        if(radixBase > 16 || radixBase < 2) {
            errCode = 2; // errCode of 2 means the radix is out of bounds
            goto errLabel;
        }
    }
    // pass arguments to conversion method
    
    return 0;
    
    // error checking
errLabel:
    if(errCode > 0) { // errCode of anything other than 0 means something went wrong
// TODO: add errCode functionality (i.e. 1 = too few args, 2 = radix oob, etc)
        // std::cout << errString1  << std::endl;
        std::cout << usageString << std::endl;
    }
    return 0;
}
