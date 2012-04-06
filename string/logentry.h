#ifndef _LOGENTRY_H_
#define _LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.h  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.h" 

////////////////////////////////////////////////////////////
class Date {
	friend std::ostream& operator<<(std::ostream&, const Date);
  public:
            Date() {};
			Date(string, string, int);
			Date operator=(Date);
  private:
    string  day, month;
    int    year;
};

////////////////////////////////////////////////////////////
class Time {
	
	friend std::ostream& operator<<(std::ostream&, const Time);

  public:
            Time() {};
			Time(int, int, int);
			Time operator=(Time);

  private:
    int    hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {

  friend  std::ostream& operator<<(std::ostream&, const LogEntry);
  
  public:
            LogEntry() {};
			LogEntry(string);
			string get_host()const;
			Date get_date()const;
			Time get_time()const;
			string get_request()const;
			string get_status()const;
			int get_bytes()const;
			
				
				
  private:
    string  host;
    Date    date;
    Time    time;
    string  request;
    string  status;
    string number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry>   parse       (std::istream&);
void                    output_all  (std::ostream&, const std::vector<LogEntry> &);
void                    by_host     (std::ostream&, const std::vector<LogEntry> &);
int                     byte_count  (const std::vector<LogEntry>&);

#endif
                                              
