// bigint input from file, add
//
//==============================================================================
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.h"

//==============================================================================
int main()
{
    // Define object for input, exit if open fails
    std::ifstream in("data1-1.txt");
    if(!in)
        { std::cerr << "Couldn\'t open data1-1.txt, exiting.\n"; exit(1); }

    // Input, add, output
    bigint left, right;
	while(in >> left && in >> right) 
	{
    
        // Output operands
        std::cout << "left:   " <<  left << std::endl;
        std::cout << "right:  " << right << std::endl;

        // Add
        bigint result = left + right;

        // Output result
        std::cout << "result: " << result << std::endl;
	}
    
    // Close file
    in.close();

    return 0;
}

