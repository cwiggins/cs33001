//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:                   
// Author:Curtiss J Wiggins
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
// PRE:valid string object  
// POST:parses the string and constructs the LogEntry object 
//
LogEntry::LogEntry(string s) {
    // ...
    std::vector<string> vec = s.split(' ');
	if(vec.size()<10)
	{   /*  used if the resulting vec from above is less than 10 in size. Sets the
	        LogEntry object to blanks and zeros for a blank entry.*/
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
	/*  Locates the date/time in the string and substrings it out for parsing to
	 *  construct the proper Date and Time Objects. The first block of code
	 *  constructs the Date Object. The second block of code constructs the Time
	 *  Object and the third constructs the LogEntry Object.*/
	int loc=vec[3].findstr(':', 0);
	tdate=vec[3].substr(1,loc-1);
	std::vector <string> tempdate =tdate.split('/');
    int tyear=tempdate[2].atoi();
		
	ttime=vec[3].substr(loc+1, 8);
	std::vector<string> temptime=ttime.split(':');
	int thr=temptime[0].atoi();
	int tmin=temptime[1].atoi();
	int tsec=temptime[2].atoi();
	
	host=vec[0];
	date=Date(tempdate[0], tempdate[1], tyear);
	time=Time(thr, tmin, tsec);
	request=vec[5] + " " + vec[6];
	status=vec[8];
	number_of_bytes=vec[9];
   }
}


////////////////////////////////////////////////////////// 
// PRE: valid input in file or keyboard 
// POST: return and vector of logentries.
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

//just a simply function to return the hostname in a logentry.
//ex) 132.345.657.11
string LogEntry::get_host()const
{
	return host;
}

//returns the date of a LogEntry object
//ex) 19 Sep 2004
Date LogEntry::get_date()const
{
	return date;
}

//returns the time in a LogEntry object.
//ex) 12:07:09
Time LogEntry::get_time()const
{
	return time;
}

//returns the request in a LogEntry object
//ex) "GET /~curtiss/home.jpg
string LogEntry::get_request()const
{
	return request;
}

//Returns the status in a LogEntry Object
//ex) 200 or 404 
string LogEntry::get_status()const
{
	return status;
}

//returns the byte count of whatever was accessed 
//ex) 234  bytes
int LogEntry::get_bytes()const
{
	return number_of_bytes.atoi();
}

//Pre valid logentry object 
//Post: outputs the contents of a logentry object.
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
// PRE:vaild logentry object and vector
// POST:just outputs the contents to the screen 
//
void output_all(std::ostream& out, const std::vector<LogEntry> & rhs) {
	int j=rhs.size();
	for(int i=0;i<j;++i)
		out<<rhs[i]; 
    
}

////////////////////////////////////////////////////////// 
// PRE:valid logentry object and vector  
// POST: outputs the hostname.
//
void by_host(std::ostream& out, const std::vector<LogEntry>& rhs) {
   
	int j=rhs.size();
	
	for(int i=0; i<j; ++i)
		out<<"Host: "<< rhs[i].get_host()<<std::endl;
	

}

////////////////////////////////////////////////////////// 
// PRE: valid logentry object and vector 
// POST: outputs the total bytes sent and recieved
//
int byte_count(const std::vector<LogEntry> &rhs) {
	
	int result=0;
	int j=rhs.size();
	for(int i=0;i<j; ++i)
		result=result + rhs[i].get_bytes();
    
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
