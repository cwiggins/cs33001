/*
 * =====================================================================================
 *
 *       Filename:  profile.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/16/2012 11:51:05 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <string>
#include <map>
#include "profile.hpp"
#include <sstream>


void profile::count(const std::string& key) {

	//looks for the provided key in the table. If the key does not exist it
	//makes an entry in the table with the key and a value afterwards it just
	//icrements the value the key is paired with.
	std::map<std::string, long>::iterator it; 
	it = table.find(key);

	if(it == table.end())
		table.insert(std::make_pair(key, 1L));
	else{
	    long temp = it->second;
		++temp;
		it->second =temp;
	}
}

std::ostream& operator<<(std::ostream& out, const profile& outme) {

	//just outputs the values in the table. Nothing very special here.
	for(std::map<std::string, long>::const_iterator it = outme.table.begin(); it != outme.table.end(); ++it) {
		out << (*it).first << ": " << (*it).second << std::endl;
	}
	return out;
}                                                                                   

void profile::count(const int key) {

	//because the key is at first in integer form it has to be converted into
	//a string. So the integer value is passed into a stringstream and presto it
	//is now a string and then is passed to the count function that uses
	//a string as a parameter. 
	   std::string s;
	   std::stringstream temp;  
	  
	   temp << key;  
	   
	   s = temp.str();  
	   
	   count(s);
}
