//Curtiss Wiggins
//bigint.cpp
//cs33001           
#ifndef CS33001_BIGINT_CPP_
#define CS33001_BIGINT_CPP_                                            
#include<iostream>
#include"bigint.h"//class definition for bigint
#include<cstring>

bigint::bigint(int num)
//sets bigint equal to provided int.
{
	int i=0;
	
	for(int k=0;k<MAX_SIZE;++k)
    { digit[k] =0; }

	while(num!=0){
	digit[i]=num %10;
	num/=10;
	++i;
	}
}
bigint::bigint()
//sets bigint equal to 0. 
{
   for(int i = 0;i < MAX_SIZE;++i)
   digit[i] = 0;
}

bigint::bigint(char num[])
//set bigint equal to a char array and then converts it into an int.
{
	for(int k=0;k<MAX_SIZE;++k)
	digit[k]=0;
	
    int i = 0;
	int j = strlen(num);
    while(i<j)
    {    
	digit[(j-1)-i]= int(num[i]) - int('0');
	++i;
    }
	
}

bool bigint::operator==(bigint num)
//determines if two bigints are the equal. If equal returns true otherwise
//returns false.
{  
	int i = 0;
	bool equal=true;
    for(i=0;i<MAX_SIZE;++i)
	{
		if(!(equal=(digit[i]==num.digit[i])))
		return equal;
	}
	return equal;
}

bool bigint::operator == (int num)
//compares a bigint to a provide int.
{
	int i=0, array[MAX_SIZE];
	for(int k=0;k<MAX_SIZE;++k)
	array[k]=0;

	
	while(num!=0)
	{
	array[i]=num %10;
	num/=10;
	++i;
	}

    bool equal=true;
	for(i=0;i<MAX_SIZE;++i)
    {
	if(!(equal=(array[i]==digit[i])))
	return equal;
	}
	return equal;
}

void bigint::output(std::ostream& out)
//prints out bigint no more than 80 characters to a line.
{
	for(int i=0;i<MAX_SIZE;++i)
	out<<digit[i];
}
#endif              
