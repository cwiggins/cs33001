//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:                   
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>


#include "string.h" 
#include "logentry.h"

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
LogEntry::LogEntry(string s) {
    // ...
    std::vector<string> vec = s.split(' ');
	if(vec.size()<10)
	{
		string tdate(" "), tmonth(" ");
		host=string(" ");
		date=Date(tdate, tmonth, 0);
		time=Time(0, 0, 0);
		request=string(" ");
		status=string(" ");
		number_of_bytes=string(" ");
		
	}
    else
	{
	string tdate, ttime;
	
	int loc=vec[3].findstr(':', 0);
	tdate=vec[3].substr(1,loc-1);
	std::vector <string> tempdate =tdate.split('/');
    int tyear=tempdate[2].atoint();
		
	ttime=vec[3].substr(loc+1, 8);
	std::vector<string> temptime=ttime.split(':');
	int thr=temptime[0].atoint();
	int tmin=temptime[1].atoint();
	int tsec=temptime[2].atoint();
	
	host=vec[0];
	date=Date(tempdate[0], tempdate[1], tyear);
	time=Time(thr, tmin, tsec);
	request=vec[5] + " " + vec[6];
	status=vec[8];
	number_of_bytes=vec[9];
   /* std::cout<<host<<std::endl;
	std::cout<< date << std::endl;
	std::cout<< time << std::endl;
	std::cout<< request << std::endl;
	std::cout<< status << std::endl;
	std::cout<< number_of_bytes<<std::endl; */
   }
}

string LogEntry::operator[](const int value)const
{
	if(value==0)
		return host;
	
	if(value==9)
		return number_of_bytes; 
	
	return request;
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
std::vector<LogEntry> parse(std::istream& in) {
    string temp, temp2;
	
	std::vector<LogEntry> result;
	
    while(in>>temp)
	{
	LogEntry t(temp);
	result.push_back(t);
	}
	
    return result;
}


std::ostream& operator<<(std::ostream& out, const LogEntry rhs)
{   
	out<<rhs.host<<" || ";
	out<<rhs.date<<" || ";
	out<<rhs.time<<" || ";
	out<<rhs.request<<" || ";
	out<<rhs.status<<" || ";
	out<<rhs.number_of_bytes<<std::endl;
	return out;
}
////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
void output_all(std::ostream& out, const std::vector<LogEntry> & rhs) {
	int j=rhs.size();
	for(int i=0;i<j;++i)
		out<<rhs[i]; 
    
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& rhs) {
   
	int j=rhs.size();
	
	for(int i=0; i<j; ++i)
		out<<"Host: "<< rhs[i][0]<<std::endl;
	
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
int byte_count(const std::vector<LogEntry> &rhs) {
	
	int result=0;
	int j=rhs.size();
	
	for(int i=0;i<j; ++i)
		result=result + rhs[i][9].atoint();
    
	return result;
}   

Date::Date(string nday, string nmonth, int nyear)
{
    day=nday;
	month=nmonth;
	year=nyear;

}

Date Date::operator=(Date rhs)
{
	string tday=day;
	day=rhs.day;
	rhs.day=tday;
	
	string tmonth=month;
	month=rhs.month;
	rhs.month=month;
	
	int  tyear=year;
	year=rhs.year;
	rhs.year=tyear;
	
	return *this;
}

Time::Time(int nhr, int min, int nsec)
{
	hour=nhr;
	minute=min;
	second=nsec;
}

Time Time::operator=(Time rhs)
{
  int thr=hour;
  hour=rhs.hour;
  rhs.hour=thr;
  
  int tmin=minute;
  minute=rhs.minute;
  rhs.minute=tmin;
  
  int tsec=second;
  second=rhs.second;
  rhs.second=tsec;
  
  return *this;
}	

std::ostream& operator<<(std::ostream& out, const Date rhs)
{
	out<<rhs.day<<" ";
	
	out<<rhs.month<<" ";
	
	out<<rhs.year;
	
	return out;
}    

std::ostream& operator<<(std::ostream& out, const Time rhs)
{
	out<<rhs.hour<<":";
	
	out<<rhs.minute<<":";
	
	out<<rhs.second;
	
	return out;
}
