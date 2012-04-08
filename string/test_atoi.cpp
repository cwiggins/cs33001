/*
 * =====================================================================================
 *
 *       Filename:  test_atoi.cpp
 *
 *    Description:  tests string class ascii to integer function.
 *
 *        Version:  1.0
 *        Created:  03/13/2012 07:55:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Curtiss J Wiggins
 *   Organization:  cs33001
 *
 * =====================================================================================
 */
#include <iostream>
#include <cassert>
#include "string.h"

int main()
{
	{
		string test("1");
		
		int result = test.atoi();
		
		assert(result==1);
	}
	
	{
		string test("12");
		
		int result = test.atoi();
		
		assert(result==12);
	}
	
	{
		string test("123");
		
		int result = test.atoi();
		
		assert(result==123);
	}
	
	{
		string test("1234");
		
		int result = test.atoi();
		
		assert( result==1234);
	}
	
}

