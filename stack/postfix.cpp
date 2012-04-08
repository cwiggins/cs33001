/*
 * =====================================================================================
 *
 *       Filename:  postfix.cpp
 *
 *    Description:  Converts a fully paranthesized infix expression like
 *    ((2+(8*9))-(8/7)) to (2 8 9 * + 8 7 / -)
 *        Version:  1.0
 *        Created:  03/12/2012 03:30:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <fstream>
#include "../string/string.h"
#include "stack.h"
#include "postfixcon.h"
#include <cstdlib>
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
	//Error if there are not at least two commandline arguments
	if(argc < 2)
		output_usage_and_exit(argv[0]);
	

	//Open specified file, quit if cannot open
	std::ifstream in(argv[1]);
	if(!in){
		std::cerr << "Couldn't open " << argv[1] << std::endl;
		exit (2);

	}

	
	//convert the infix expressions to postfix
	string infix;
	Stack<string> postfix; 
	while(in>>infix){

		//substrings out the infix expression minus the line return and
		//semi-colon.
		string temp = infix.substr(0,infix.length()-2);

		//splits the infix expression on spaces for easier processing. Stores in
		//it in vector.
		std::vector<string> vec = temp.split(' ');

		//function for converting infix expressions to postfix format.
		string result = infix2postfix(vec);

		//places the resulting string from the the conversion on the stack.
	    postfix.push(result);
	}	
	
	//done using the input file
	in.close();
	
	//handles if an output file was specified on commandline
	if(argc==3){
		std::ofstream out(argv[2]);
		if(!out){
			std::cerr << "Couldn't open " << argv[2] <<std::endl;
		}
		while(!postfix.IsEmpty()){
		out<< postfix.pop() << std::endl;}
	}else{
		while(!postfix.IsEmpty()){
        std::cout << postfix.pop() << std::endl;}
		}
	
	//successful
	return 0;
}

      
