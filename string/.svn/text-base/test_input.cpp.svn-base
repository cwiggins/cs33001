/*  ------------------------------------------------------------------------------------------
 *  Curtiss J Wiggins
 *  cs33001
 *  input.pp
 *  tests the overloaded >> operatro for my string class
 *  ------------------------------------------------------------------------------------------*/
#include<iostream>
#include<fstream>
#include<cstdlib>
#include"string.h"
#ifndef CS33001_INPUT_CPP_
#define CS33001_INPUT_CPP_

int main()
{
	std::cout<<"============================Test Input===================="<<std::endl;
	std::ifstream in("data1.txt");
	if(!in)
	{std::cerr<<"Could\'t open data1.txt";
		exit(1);}
	
	string left,right;
	while (in >> left && in>> right)
	{
		std::cout << "First String:  " << left <<std::endl;
		std::cout << "Second String: " << right <<std::endl;
		
		string result = left + " " + right;
		
		std::cout<<"Result:  " << result << std::endl;
	}
	
	in.close();
	
	std::cout<<"===========================Test Input======================"<<std::endl;
	return 0;
}
#endif
