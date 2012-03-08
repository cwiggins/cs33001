/*--------------------------------------------------------------------------------------------
 * Curtiss J Wiggins
 * cs33001
 * test_relational_operators.cpp
 * tests the <,>,<=,>=,!= functions of my string class
 * --------------------------------------------------------------------------------------------*/
#include<iostream>
#include<cassert>
#include"string.h"
#ifndef CS33001_TEST_RELATIONAL_OPERATORS_CPP_
#define CS33001_TEST_RELATIONAL_OPERATORS_CPP_

int main()
{
	{
		string str("I love you."), str2("I love you more.");
		bool result;
		
		result = str < str2;
		
		assert(str=="I love you.");
		assert(str2=="I love you more.");
		assert(result==false);
	}
	{
		string str("ghtyqwerndgt"), str1("fdsreunsloqp");
		bool result;
		result = str > str1;
		//verify
		assert(str=="ghtyqwerndgt");
		assert(str1=="fdsreunsloqp");
		assert(result==true);
	}
	
	{
		string str1("AAA"), str2("AAB");
		bool result;
		
		result = str1 != str2;
		
		assert(str1=="AAA");
		assert(str2=="AAB");
		assert(result == true);
	}
}
#endif
