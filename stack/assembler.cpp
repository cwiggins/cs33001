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
#include "postfixcon.h"
///////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
  
	//Error if less than 2 commandline arguments. Means user did not
	//specify input file.
	if(argc < 2)
		output_usage_and_exit(argv[0]);
	
	std::ifstream in(argv[1]);
	if(!in){
		std::cerr << "Couldn't open: " << argv[1] << std::endl;
		exit(2);
	}
	
	string temp, infix;
	
	if(argc==3){
		std::ofstream out(argv[2]);
		if(!out){
			std::cerr << "Couldn't open: " << argv[2] << std::endl;
			exit(2);
		}
		while(in>>temp){
			
			out << "Infix: " << temp << std::endl;

			infix = temp.substr(0, temp.length()-2);
			
			std::vector<string> vec = infix.split(' ');
			
			string postfix = infix2postfix(vec);
			
			out << "postfix: " << postfix << std::endl;
			std::vector<string> vec2 = postfix.split(' ');
			out << "Assembler:" << std::endl;
			Stack<string> assembler = postfix2assembler(vec2);
			outputassembler(out, assembler);
		}
	}else{
		
		while(in>>temp){
			
		std::cout << "Infix: " << temp << std::endl;
		
		infix = temp.substr(0, temp.length()-2);
		
		std::vector<string> vec = infix.split(' ');
		
		string postfix = infix2postfix(vec);
		
		std::cout << "Postfix: " << postfix << std::endl;
		
		std::vector<string> vec2 = postfix.split(' ');
		
		std::cout << "Assembler: " << std::endl;
		
		Stack<string> assembler = postfix2assembler(vec2);
		outputassembler(std::cout, assembler);
		}
	}
 return 0;		
}

