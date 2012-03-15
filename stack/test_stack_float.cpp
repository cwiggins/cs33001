/*
 * =====================================================================================
 *
 *       Filename:  test_stack_float.cpp
 *
 *    Description:  tests a stack of float
 *
 *        Version:  1.0
 *        Created:  03/12/2012 01:14:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Curtiss J Wiggins 
 *   Organization:  cs33001
 *
 * =====================================================================================
 */
#include <cassert>
#include"stack.h"

int main()
{
	{
		Stack<float> st1;
		float i = 12.3476, result;
		
		st1.push(i);
		result=st1.pop();
		
		assert(result==static_cast<float>(12.3476));
	}
}

