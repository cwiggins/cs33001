// bigint output demonstration
//
// Change the name of the output function if necessary.

#include "bigint.h"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    // Define, output default constructed value
    bigint bi_1;
    std::cout << "number 1: ";
	std::cout<<bi_1<<std::endl;
    std::cout << "\n";

    // Define, output 1 digit number
    bigint bi_2(1);
    std::cout << "number 2: ";
	std::cout<<bi_2<<std::endl;
    std::cout << "\n";

    // Define, output 3 digit number
    bigint bi_3(123);
    std::cout << "number 3: ";
	std::cout<<bi_3<<std::endl;
    std::cout << "\n";

    // Define, output 90 digit number
    bigint bi_4("123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");
    std::cout << "number 4: ";
	std::cout<<bi_4<<std::endl;
    std::cout << "\n";

}

