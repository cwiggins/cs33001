/*
 * =====================================================================================
 *
 *       Filename:  test_swap.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/29/2012 03:32:42 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cassert>
#include "string.h"
#ifndef CS33001_TEST_SWAP_CPP_
#define CS33001_TEST_SWAP_CPP_

int main()
{
	{
		string str1("AAAA"), str2("BBBB");
		
		str1.swap(str2);
		
		assert(str1=="BBBB");
		assert(str2=="AAAA");
	}
}
#endif

