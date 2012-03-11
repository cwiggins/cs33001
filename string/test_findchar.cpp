/* ----------------------------------------------------------------------------
 * Curtiss Wiggins
 * cs33001
 * test_findchar.cpp
 * tests the find char function of my string class
 * --------------------------------------------------------------------------*/
#include <iostream>
#include"string.h"
#include<cassert>
#ifndef CS33001_TEST_FINDCHAR_CPP_
#define CS33001_TEST_FINDCHAR_CPP_

int main() 
{
	{
		string str1("ABCDEFGHIJK");
		
		int position=str1.findchar('F', 0);
		
		
		assert(str1=="ABCDEFGHIJK");
		assert(position==5);
	}
	
	{
		string str1("ABCDEFGHIJK");
		
		int position = str1.findchar('F', 4);
		
		assert(str1=="ABCDEFGHIJK");
		assert(position==5);
	}
}
#endif
