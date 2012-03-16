/*
 * =====================================================================================
 *
 *       Filename:  test_split.cpp
 *
 *    Description:  tests split function of string class
 *
 *        Version:  1.0
 *        Created:  02/27/12 12:52:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Curtiss J Wiggins 
 *   Organization:  cs33001
 *
 * =====================================================================================
 */
#include<iostream>
#include<cassert>
#include<vector>
#include"string.h"
#ifndef CS33001_TEST_SPLIT_CPP_
#define CS33001_TEST_SPLIT_CPP_

int main()
{
	{
		string str1("AAAA BBBB CCCC EEEE FFFF");
		
		std::vector<string> vec = str1.split(' ');
		
		
		assert(str1=="AAAA BBBB CCCC EEEE FFFF");
		assert(vec.size() == 5);
		assert(vec[0]=="AAAA"); 
		assert(vec[1]=="BBBB");
		assert(vec[2]=="CCCC");
		assert(vec[3]=="EEEE");
		assert(vec[4]=="FFFF");
		
	}
}
#endif
