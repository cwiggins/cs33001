/*--------------------------------------
 * Curtiss J Wiggins
 * string.h
 * cs33001
 * ------------------------------------*/
#include<iostream>
#include<vector>
#ifndef CS33001_STRING_H_
#define CS33001_STRING_H_

class string{
public:
	string(); //default constructor
	string(const char *); //c-string constructor
	string(char); //char constructor 
	string(int);
    ~string();
	string(const string&);
	bool operator==(const string&)const; //compares to see if two strings are equal
	bool operator==(const char*)const;   //compares to if a string and a c-string are equal
	bool operator<(const string&)const;  //sees if this is less than a provided string
	bool operator<(const char*)const;    //sees if a string is less than a provided c-string
	bool operator>(const string&)const;  //compares if this is greater than a provided string
	bool operator>(const char*)const;    //compares if a string is greater than a provided c-string
	bool operator<=(const string&)const; 
	bool operator<=(const char*)const;
	bool operator>=(const string&)const;
	bool operator>=(const char*)const;
	bool operator!=(const string&)const;
	bool operator!=(const char*)const;
	
	//concatenation operators
	string operator+(const char*)const;  //is used when it is string + c-string
	string operator+(const string&)const; //concatenates two strings
	string operator+(const char)const;     //is used when it is string + char
	friend string operator+(const char, const string&); //is used when it s c-string + string
	friend string operator+(const char*, const string&); //is used when it is char + string
	

	int length()const; //returns the value of len if found. only applies to string class 
	
	//accessor & modifier operators
	char operator[](int)const;//returns the value of string at given value 
    char& operator[](int);
	

	string substr(const int, const int)const; //the first valye provided is the starting location and the second value is the length. creates a new string from the string this is called on.
	int findstr(const string&, int)const; //provide a pattern to found and it will try find it and if found reports the location
	int findstr(const char*, int)const;
	int findchar(const char, int)const;
	int findchar(const char*, int)const;
	int findchar(const string&, int)const;
	
	//input & output operators
	friend std::istream& operator>>(std::istream&, string&);
	friend std::ostream& operator<<(std::ostream&, const string&);
	
	void swap(string&);
	void reallocate(int);
	
	string& operator=(const string&);
	
   std::vector<string> split(const char)const;
	
private:
	char *ptr;
	int len;
	int cap;
};
#endif
