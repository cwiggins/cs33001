/* -------------------------------------------------------------------------------------------
 * Curtiss J Wiggins
 * cs33001
 * test_findstr.cpp
 * tests the find str function of my string class
 * --------------------------------------------------------------------------------------------*/
#include<iostream>
#include<cassert>
#include"string.h"
#ifndef CS33001_TEST_FINDSTR_CPP_
#define CS33001_TEST_FINDSTR_CPP_

int main()
{
	{
		string str1("Make love not war"), result;
		
		//setup fixture
		int loc=str1.findstr("love", 0);
	
		result=str1.substr(loc,4);
		
		
		//verify
		assert(str1=="Make love not war");
		assert(result=="love");
	}
	
	{
		string str1("Make love not war"), result;
		
		int loc = str1.findstr("love", 3);
		
		result=str1.substr(loc,4); 
	
		
		assert(str1=="Make love not war");
		assert(result=="love");
	}
}

#endif
