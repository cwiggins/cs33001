/*
 * =====================================================================================
 *
 *       Filename:  profile.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/16/2012 11:19:53 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Curtiss J Wiggins 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef CS33001_PROFILE_HPP_
#define CS33001_PROFILE_HPP_
#include <map>
#include <cassert>
#include <string>

//just a simple adt for profiling a programs. all it does it count the number
//the times and function or declaration was made. Uses an std::map<std::string,
//long> to keep track of times these events happened. 
class profile{
	//overloaded output <<.
	friend std::ostream& operator<<(std::ostream&,const profile&);
public:
	//default constructor does nothing because std::map manages itself.
	profile(){};
	//used to count the actual function calls and declarations
	void count(const std::string&);
	void count(const int);
	
private:
	std::map<std::string, long> table;
};

#endif
