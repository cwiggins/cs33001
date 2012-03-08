/*------------------------------------------------------------------------------------------
 * Curtiss J Wiggins
 * cs33001
 * test_substr.cpp
 * tests my string class substr function.
 * ------------------------------------------------------------------------------------------*/
#include<iostream>
#include<cassert>
#include"string.h"
#ifndef CS33001_TEST_SUBSTR_CPP_
#define CS33001_TEST_SUBSTR_CPP_

int main()
{
	{
		string str("Curtiss"), result;
		
		//setup fixture
		result=str.substr(1,4);
		assert(str=="Curtiss");
		assert(result=="urti");
	}
}
#endif

