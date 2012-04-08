/*
 * =====================================================================================
 *
 *       Filename:  test_getline.cpp
 *
 *    Description:  tests string getline function.
 *
 *        Version:  1.0
 *        Created:  03/13/2012 03:08:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cuurtiss 
 *   Organization:  cs33001
 *
 * =====================================================================================
 */
#include <iostream>
#include <cassert>
#include "string.h"
#include <fstream>
#include <cstdlib>

int main()
{
	{
		string test;
		
		std::ifstream in("data1.txt");
		if(!in){
			std::cerr << "Couldn't open file." << std::endl;
			exit (2);
		}
		
	   test = test.getline(in, '\n');
		in.close();
	}
	
	{
		string test;
		
		std::ifstream in("data1.txt");
		if(!in){
			std::cerr << "Couldn't open file." << std::endl;
			exit (2);
		}
		while(!in.eof()){
		   test = test.getline(in, '\n');
		}
		in.close();
	}
	
	{
		string test;
		
		std::ifstream in("data1.txt");
		if(!in){
			std::cerr << "Couldn't open file." << std::endl;
			exit (2);
		}
		
		while(!in.eof()){
			test = test.getline(in, 'i'); 
			std::cout << test << std::endl;
		}
		in.close();
	}
	
	{
		string test;
		
		test = test.getline(std::cin, '\n');
		
		std::cout << test << std::endl;
	}
}
