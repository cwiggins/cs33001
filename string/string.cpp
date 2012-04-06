/* ------------------------------------------
 * Curtiss J Wiggins
 * string.cpp
 * cs33001
 * -------------------------------------------*/
#include<iostream>
#include"string.h"
#include<vector>

#ifndef CS33001_STRING_CPP_
#define CS33001_STRING_CPP_ 

string::string()
{
	len=0;
	cap=256;
	ptr=new char[cap];
	ptr[0]='\0';	
}  

string::string(const char test[])
{	
	cap=256;
    ptr=new char[cap];
	
	int i=0;
	while(test[i]!='\0')  //loop fills ptr with elements from the c-string
	{
    ptr[i]=test[i];
	++i;
	}
		

	ptr[i]='\0';
	len=i;
} 	

int string::length()const
{
	
	return len;
}

string::string(char test)
{
	cap=256;
	ptr=new char[cap];
	ptr[0]=test;
	ptr[1]='\0';
	len=1;
}

string::~string()
{
   delete []ptr;
} 

string::string(int n)
{
	ptr = new char[cap];
	cap=n;
	
	ptr[0]='\0';
}

string::string(const string& actual)
{
    cap=actual.cap;
	len=actual.len;
	
	ptr=new char[cap];
	
	for(int i=0;i<len;++i)  //loops actuals elements over to a new string.
		ptr[i]=actual.ptr[i];
	
	ptr[len]='\0';
}

void string::swap(string& rhs)
{
	char *temp =ptr;
	ptr=rhs.ptr;
	rhs.ptr=temp;
	  
	int tcap=cap;
	cap = rhs.cap;
	rhs.cap=tcap;
	
	int tlen=len;
	len=rhs.len;
	rhs.len=tlen;
}

void string::reallocate(int n_size)
{
	string temp(n_size);
	
	 if(cap==n_size) return;
	
	 if(cap>n_size)
	{
		int i=0;
		while(i<n_size)
		{
			temp.ptr[i]=ptr[i];
			 ++i;
		}
				
		temp.ptr[i]='\0';
		
		if(len==0)
			temp.len=0;
		else
			temp.len=len;
	}
	else
	{
		int i=0;
		while(i<cap)
		{
			temp.ptr[i]=ptr[i];
			++i;
		}
		
		temp.ptr[i]='\0';
		
		if(len==0)
			temp.len=0;
		else
			temp.len=len;
	}
	 swap(temp);
}

string& string::operator=(string rhs)
{
    swap(rhs);
	return *this;
}

bool string::operator==(const string& rhs) const
{

	int i=0;
	while(ptr[i]!=0)          //loop is used to see if elements in two
	{                         //strings are equal. only goes until ptr hits the
		if(ptr[i]!=rhs.ptr[i]) //null terminator. 
			return false;
		++i;
	}

	if(rhs.ptr[i]==0)  //used after loop exit to see if rhs in 
		return true;   //same position as ptr is equal to null 
	else               //terminator. if it is then returns true.
		return false;  //else returns false.

}

bool string::operator==(const char test[])const{
	string str(test);
	return(*this==str);
}


bool string::operator!=(const string& rhs)const 
{
   return !(*this==rhs);
}

bool string::operator!=(const char rhs[])const
{
	string tmp(rhs);
	return !(*this==tmp);
}

bool string::operator<(const string& rhs) const
{
	if(*this==rhs)
		return false; 
	
    bool lt=true;

	int i =0;
	while(ptr[i]!=0 && rhs.ptr[i]!=0)
	{
		if(ptr[i]>rhs.ptr[i])
			return false;
		else
			lt=true;
		
		++i;
	}
	
	if( lt && (ptr[i]==0) && (rhs.ptr[i]==0))
		return true;
	
	if(lt && (rhs.ptr[i]==0))
		return true;
	
	if(!lt && (rhs.ptr[i]==0) && (ptr[i]==0))
		return false;
	
	if(ptr[i]==0)
		return true;
	
	return false;
} 

bool string::operator<(const char test[]) const
{
	string tmp(test);
	return (*this<tmp);
}


bool string::operator>(const string& rhs)const
{
	if(*this==rhs)
		return false;
	
	return !(*this<rhs);
}

bool string::operator>(const char test[])const
{
	string tmp(test);
	return(*this>tmp);
}

bool string::operator<=(const string& rhs)const
{
	return(*this<rhs || *this==rhs);
}

bool string::operator<=(const char rhs[])const
{
	string tmp(rhs);
	return(*this<tmp || *this==tmp);
}

bool string::operator>=(const string& rhs)const
{
	return (*this>rhs || *this==rhs);
}

bool string::operator>=(const char rhs[])const
{
	string tmp(rhs);
	return (*this>rhs || *this==rhs) ;
}

char string::operator[](int i)const
{
	return ptr[i];
}

char& string::operator[](int i)
{
	return ptr[i];
}   

string string::operator+(const string& rhs) const
{
	string result=*this;
	int i=len, k=0;
	
	while(rhs.ptr[k]!=0){
		result.ptr[i]=rhs.ptr[k];
        ++i;
		++k;
	}

	result.len=len+rhs.len;
	result[i]=0;
	return result;
}

string string::operator+(const char test[])const{
	string tmp(test);
	
	return (*this+tmp);
}

string operator+(const char lhs[], const string& rhs) 
{
	string tmp(lhs);
    return(tmp+rhs);
}

string string::operator+(const char ch)const
{
	string tmp(ch);
	return(*this+tmp);
}

string operator+(const char rhs, const string& lhs)
{
	string tmp(rhs);
	return(tmp+lhs);
}

string string::substr(const int start, const int leng)const
{
	string tmp, result;
	tmp=*this;
	int i = start, j=0;
	while(j<leng){
		result.ptr[j]=tmp.ptr[i];
		++i;
		++j;
	}

	result.ptr[j]=0;
	result.len=leng;	
	return result;
}

int string::findstr(const string& test, int pos)const
{
	char ch = ' ';
	int same = 0;
	int location = -1;
	int counter = pos;

	while(counter >= 0 && (counter < len) && same != test.len){
	ch = ptr[counter];
	if(test.ptr[0] == ch)
	{
		location=counter;
		for(int i=0;i<test.len;++i)
		{
			if(test.ptr[i]==ch && (i + location < len))
				++same;
			else
			{
				same = 0;
				location = -1;
			}
			ch = ptr[(i+1)+location];
		}
	}
	++counter;
	}
	return location;
} 

int string::findstr(const char test[], int pos)const
{
	string str(test);
	int result;
	result=findstr(str, pos);
	return result;
}

int string::findchar(char a, int n)const
{
	string str(a);
	int nt = findstr(str, n);
   return nt;
}

int string::findchar(const char test[], int pos) const
{
	string str(test);
	
	int result = findstr(str, pos);
	
	return result;
}

int string::findchar(const string& test, int pos)const
{
	int result = findstr(test, pos);
	return result;
}

std::istream& operator>>(std::istream& ins, string& rhs)
{
	char tmp[200];
	ins.getline(tmp, 200);
	rhs=string(tmp);		
	return ins;
}

std::ostream& operator<<(std::ostream& outs, const string& rhs)
{
	int i=0;                                                
	while(rhs.ptr[i]!=0)
	{
		outs<<rhs.ptr[i];
		++i;
	}
	
	
	
	return outs;
}

std::vector<string> string::split(const char n) const
{
	
	std::vector<string> vec;
	string result;
			
	int i =0;
	int j=0;	
	while(ptr[j]!='\0')
	{
		if(ptr[j]==n)
		{
			result.ptr[i]='\0';
			result.len=i;
			vec.push_back(result);
			i=0;
			++j;
			result.ptr[i]=ptr[j];
			++j;
			++i;
		}
		else
		{
			
			result.ptr[i]=ptr[j];
			++j;
			++i;
		}
	}
	result.ptr[i]='\0';
	result.len=i;
	vec.push_back(result);
	

	
	return vec;
}

int string::atoi()const
{
	int i = 0;
	int value = 0;
	while(isdigit(ptr[i])){
		value *=10;
		value += (int) (ptr[i]-'0');
		++i;
	}
	return value;
}


string  string::getline(std::istream& in, const char delim)
{
	char next;
	int i = 0;
	in.get(next);
	while(next!=delim && !in.eof()){
		ptr[i]=next;
		in.get(next);
		++i;
	}
	len=i;
	ptr[len]='\0'; 
	
	return *this;
	
}

#endif 
