//Curtiss Wiggins
//bigint.h
//cs33001
#ifndef CS33001_BIGINT_H_
#define CS33001_BIGINT_H_
#include<iostream>
	const int MAX_SIZE = 300;

class bigint
{
public:
    bigint();//used to initialize bigint to 0.
    bigint(const char num[]);//used to initiailize bigint to a provide char
    bigint(int);//initialize bigint to an int provide
    bool operator ==(const bigint&) const;//checks to see if two bigints are the same.
    bool operator==(const int) const;//checks to see of bigint equals a provide int.
    bool operator==(const char[]) const;//checks to see of bigint equals a provide int.
    friend std::ostream& operator<<(std::ostream& out, bigint);//overloaded output operator for printing bigints
    friend std::istream& operator>>(std::istream& in, bigint&);//overloaded input operator for inputting bigints
    int operator[](int i);
    //preconditon: give some integer i
    //postcondition: will return the ith digit in the bigint.
    bigint operator+(const bigint&) const;//adds to bigints together
    bigint operator*(int);
	//precondition: give an int between 0-9
	//postcondition: will return the result of a bigint * an int.
    bigint operator*(bigint);
	//Postcondition: returns the result of a bigint * a bigint. 
    bigint times_10(const int) const;
	//Postcondition: returns a shifted bigint
	
private:                       

    int digit[MAX_SIZE];
	int used_space;
};
#endif
