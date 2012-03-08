/*
 * =====================================================================================
 *
 *       Filename:  test_copy_ctor.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/29/2012 03:23:42 PM
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
#ifndef CS33001_TEST_COPY_CTOR_CPP_
#define CS33001_TEsT_COPY_CTOR_CPP_

int main()
{
	{
		string str1("AAAA");
		string copy(str1);
		
		assert(str1=="AAAA");
		assert(copy=="AAAA");
		
		
	}
	
	{
		string str1("AAAA BBBB");
		string copy(str1);
		
		assert(str1=="AAAA BBBB");
		assert(copy=="AAAA BBBB");
	}
	
	{
		string str1("AAAA BBBB CCCC");
		string copy(str1);
		
		assert(str1=="AAAA BBBB CCCC");
		assert(copy=="AAAA BBBB CCCC");
	}
	
	{
		string str1("AAAA BBBB CCCC DDDD");
		string copy(str1);
		
		assert(str1=="AAAA BBBB CCCC DDDD");
		assert(copy=="AAAA BBBB CCCC DDDD");
	}
	
    {
		string str1("AAAA BBBB CCCC DDDD EEEEE");
		string copy(str1);
		
		assert(str1=="AAAA BBBB CCCC DDDD EEEEE");
		assert(copy=="AAAA BBBB CCCC DDDD EEEEE");
	}
}

#endif

