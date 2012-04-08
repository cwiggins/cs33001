/*
 * =====================================================================================
 *
 *       Filename:  assembler.cpp
 *
 *    Description:  Converting an infix expression to postifx then into
 *    rudimentary assembly. Allows for outputting to a file if specified on
 *    the commandline otherwise outputs to screen.
 *
 *        Version:  1.0
 *        Created:  03/30/2012 09:11:30 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Curtiss J Wiggins 
 *   Organization:  cs33001
 *
 * =====================================================================================
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "../string/string.h"
#include "stack.h"

///////////////////////////////////////////////////////////////////////////////
string

int main(int argc, char **argv){
  
	//Error if less than 2 commandline arguments. Means user did not
	//specify input file.
	if(argc < 2)
		output_usage_and_exit(argv[0]);
}
