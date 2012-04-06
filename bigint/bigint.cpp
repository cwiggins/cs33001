//Curtiss Wiggins
//bigint.cpp
//cs33001           
#ifndef CS33001_BIGINT_CPP_
#define CS33001_BIGINT_CPP_                                            
#include<iostream>
#include"bigint.h"//class definition for bigint


bigint::bigint(int num)
//sets bigint equal to provided int.
{   
	for(int i = 0; i<MAX_SIZE; ++i)
		digit[i]=0;

	int i = 0;
	while(num!=0){
		digit[i]=num %10;
		num/=10;
		++i;
	}
	
	if(i == 0)
		used_space = 1;
	else
		used_space = i;
}
bigint::bigint()
//sets bigint equal to 0. 
{
	for(int i = 0;i < MAX_SIZE;++i)
	digit[i] = 0;
	used_space=1;
}

bigint::bigint(const char num[])
//set bigint equal to a char array and then converts it into an int.
{
	
	for(int k=0;k<MAX_SIZE;++k)
	digit[k]=0;
	
    int i = 0;
	int j=0;
	while(num[j]!=0)
		++j;

    while(i<j)
    {    
	digit[(j-1)-i]= int(num[i]) - int('0');
	++i;
    }
	used_space=j;
	
}

bool bigint::operator==(const bigint& num) const
//determines if two bigints are the equal. If equal returns true otherwise
//returns false.
{  
   // if(used_space != num.used_space)
	   // return false;

	int i = 0;
	bool equal=true;
    for(i=0;i<used_space;++i)
	{
		if(!(equal=(digit[i]==num.digit[i])))
		return equal;
	}
	return equal;
}

bool bigint::operator == (const int num) const
//compares a bigint to a provide int.
{
	bigint test(num);
	return (*this == test);
}

bool bigint::operator== (const char test[]) const
{
	bigint temp(test);
	return(*this == temp);
}	

std::ostream& operator<<(std::ostream& out, const bigint& rhs)
//prints out bigint no more than 80 characters to a line.
{
	for(int i=MAX_SIZE-1, j=0;i>=0;--i,++j)
	{
		if(j<80)
			out<< rhs.digit[i];
		else
		{
			out<<std::endl<< rhs.digit[i];
			j=0;
		}
	}
	return out;
}

std::istream& operator>>(std::istream& ins, bigint& x)
{  
	int i=0;                         
	char next,temp[MAX_SIZE];

    ins>>next;
	while(next!=';' && !ins.eof())
	{
		temp[i]=next;
		ins>>next;
			++i;
	}
 
	temp[i]=0;
	x=bigint(temp);

 return ins;        
}   

int bigint::operator[](int x)const
{
	return digit[x];
}

int& bigint::operator[](int spot)
{
	return digit[spot];
}

bigint bigint::operator+(const bigint& x) const
{
	int i=0, temp=0, position;
    bigint result;

	if(used_space < x.used_space)
		position = x.used_space;
	else
		position = used_space;

	while(i<position)
	{
		temp=x.digit[i]+digit[i]+temp;
		result.digit[i]=temp %10;
		temp/=10;
		++i;
	}
	
	if(temp > 0)
		result.digit[i++] = 1;

	result.used_space = i;

	return result;
}

bigint bigint::operator*(int num)const
{
	int product=0, i=0;
	bigint result;

	if(num == 0 || *this == 0)
		return result;

	if(num < 0 || num>9)
	{	std::cout<<"Invalid Operation for this Program.";
		return 1;
	}
	else
	{
		while(i<used_space+1)
		{
            product = digit[i]*num+product;
			result.digit[i]=product%10;
			product/=10;
			++i;
		}
	}
	result.used_space=i;
	
return result;
}

bigint bigint::operator*(const bigint& rhs)const
{  	
	bigint product, sum, tmp;

	for(int i=0;i<MAX_SIZE;++i)
    {
		product=rhs*digit[i];
		tmp = product.times_10(i);
		sum = sum + tmp;
	}
 

	return sum;
}   

bigint bigint::times_10(const int num) const
{
	bigint result;

	result = *this;

	int j=0;
	while(j<used_space)
	{	
		result.digit[j+num]=digit[j];
		++j;
	}	

	result.used_space = used_space + num;

	j=0;
	while(j<num)
		result.digit[j++] = 0;

	return result;
}


#endif     

//end
