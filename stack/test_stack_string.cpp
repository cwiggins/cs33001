/*
 * =====================================================================================
 *
 *       Filename:  test_stack_string.cpp
 *
 *    Description:  tests a stack of strings
 *
 *        Version:  1.0
 *        Created:  03/12/2012 01:09:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Curtiss J Wiggins
 *   Organization:  cs33001
 *
 * =====================================================================================
 */
#include <cassert>
#include"../string/string.h"
#include"stack.h"

int main()
{
	{
		Stack<string> test;
		
		assert(test.IsEmpty());
	}
	
	{
		Stack<string> st1;
		string test("A"), result;
		
		st1.push(test);
	
		assert(st1.pop()=="A");
	}

	{
		Stack<string> test;
		string str1(" ");
		
		test.push(str1);
		
		assert(test.pop()==" ");
	}
}
                                        
