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
  public:
            Date() {};

  private:
    String  day, month;
    int     year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
            Time() {};

  private:
    int     hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {

  friend  std::ostream& operator<<(std::ostream&, const LogEntry);

  public:
            LogEntry() {};
            LogEntry(String);

  private:
    String  host;
    Date    date;
    Time    time;
    String  request;
    String  status;
    int     number_of_bytes;
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

