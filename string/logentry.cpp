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
LogEntry::LogEntry(String s) {
    // ...
    std::vector<String> vec = s.split(' ');
    
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;

    return result;
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
void output_all(std::ostream& out, const std::vector<LogEntry> &) {
    
}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>&) {

}

////////////////////////////////////////////////////////// 
// PRE:  
// POST: 
//
int byte_count(const std::vector<LogEntry> &) {
    
    return 0;
}

