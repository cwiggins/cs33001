/* ------------------------------------------------------------------------------------ * Curtiss J Wiggins
 * cs33001
 * test_concatenation.cpp
 * tests the concatenation function of the string class.
 *-----------------------------------------------------------------------------------*/
#include<iostream>
#include"string.h"
#include<cassert>
#ifndef CS33001_TEST_CONCATENATION_CPP_
#define CS33001_TEST_CONCATENATION_CPP_

int main()
{
	{
		string str1("AAAA"), str2("BBBB");
		string result;
		
		//setup fixture
		result=str1 + str2;
		
		assert(str1=="AAAA");
		assert(str2== "BBBB");
		assert(result=="AAAABBBB");
	}
	
	{
		string str1("AAAA"), result;
		
		result=str1+"BBBB";
		
		assert(str1=="AAAA");
		assert(result=="AAAABBBB");
	}
	
	{
		string str1("AAAA"), result;
		
		result="BBBB"+str1;
		
		assert(str1=="AAAA");
		assert(result=="BBBBAAAA");
	}
	
	{
		string str1("AAAA"), result;
		char ch='B';
		
		result=str1+ch;
		
		assert(str1=="AAAA");
		assert(ch=='B');
		assert(result=="AAAAB");
	}
	
	{
		string str1("AAAA"),result;
		
		result='B'+str1;
		
		assert(str1=="AAAA");
		assert(result=="BAAAA");
	}
	
	{
		string str1("AAAA"), str3("CCCC"), result;
		char ch='B';
		
		result = str1 + ch + 'B' + 'B'+ 'B' + str3;
		
		assert(str1=="AAAA");
		assert(ch== 'B');
		assert(str3=="CCCC");
		assert(result=="AAAABBBBCCCC");
	}
	
	{
		string str1("ABC"), result;
		
		result=" " + str1;
		
		assert(str1=="ABC");
		assert(result==" ABC");
	}
	
	{
		string str1("ABC"), result;
		
		result = str1 + " ";
		
		assert(str1 == "ABC");
		assert(result == "ABC ");
	}
	
	{
		string str1(" "), str2(" "), result;
		
		result = str1 + str2;
		
		assert(str1 == " ");
		assert(str2 == " ");
		assert(result == "  ");
	}
	
	{
		string rhs("ABC"), result;
		
		result = 'A' + rhs;
		
		assert(rhs=="ABC");
		assert(result== "AABC");
	
	}
	
	{
		string lhs("ABC"), result;
		
		result = lhs + 'A';
		
		assert(lhs == "ABC");
		assert(result == "ABCA");
	}
	
	{
		string str1("Hello"), str2("Wiggins"), result;
		char ch1='C', ch2='t';
		
		result = str1 + ',' + " My name is " + ch1 + 'u' + 'r' + ch2 + "iss " + str2 + '.';
		
		assert(str1=="Hello");
		assert(str2=="Wiggins");
		assert(ch1=='C');
		assert(ch2=='t');
		assert(result=="Hello, My name is Curtiss Wiggins.");
	}
}
#endif
