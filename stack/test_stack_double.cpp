/*
 * =====================================================================================
 *
 *       Filename:  test_stack_double.cpp
 *
 *    Description:  tests a stack of doubles
 *
 *        Version:  1.0
 *        Created:  03/12/2012 01:03:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Curtiss J Wiggins
 *   Organization:  cs33001
 *
 * =====================================================================================
 */
#include <cassert>
#include "stack.h"

int main()
{
	{
		Stack<double> test;
		double  i = 12.34, j;
		
		test.push(i);
		j=test.pop();
		assert(j==12.34);
	}
	
	{
		Stack<double> test;
		
		assert(test.IsEmpty());
	}
	
	{
		Stack<double> test;
		
		test.push(13.4);
		test.push(12.89);
		
		assert(test.pop()==12.89);
		assert(test.pop()==13.4);
	}
	
	{
		Stack<double> test;
		
		test.push(123.89);
		test.push(2345.609);
		test.push(1.9192987);
		
		assert(test.pop()==1.9192987);
		assert(test.pop()==2345.609);
		assert(test.pop()==123.89);
	}
}

