/*
 * =====================================================================================
 *
 *       Filename:  postfixcon.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/30/2012 10:27:50 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Curtiss J Wiggins
 *   Organization:  cs33001
 *
 * =====================================================================================
 */
#include "postfixcon.h"
#include "stack.h"
#include <vector>
#include <cstdlib>
#include "../string/string.h"

string infix2postfix(std::vector<string>& infix){
	Stack<string> s;
	int i = 0;
	int j = infix.size();
    string rhs, lhs, op;

	while(i<j){
		if(infix[i]!='('){
			if(infix[i]==')'){
				rhs = s.pop();
				op  = s.pop();
				lhs = s.pop();

				s.push(lhs+"  "+rhs+"  "+op);
			}else{
				s.push(infix[i]);
			}
		}
		++i;
	}
	return s.pop();
}


Stack<string> postfix2assembler(std::vector<string>& p){
	Stack<string> s, a;

	int i = 0, j = p.size();
	string rhs, lhs, op, LD("LD"), SW("SW");

	while(i<j){
		if(p[i]!='*' || p[i]!='+' || p[i]!= '-' || p[i]!= '/'){
			s.push(p[i]);
		}else{
			rhs = s.pop();
			lhs = s.pop();
			if(p[i]=='*')
				op = "ML";
			if(p[i]=='/')
				op = "DV";
			if(p[i]=='+')
				op = "AD";
			if(p[i]=='-')
				op = "SB";

			}
		++i;
	}
	return a;
}

void outputassembler(std::ostream& out, Stack<string>& assembler){
	
}


void output_usage_and_exit(char cmd[]){
	std::cerr << "Usage: " << std::endl;
	std::cerr << cmd << " input_file  " << "[output_file]" <<std::endl;

	exit (1);
}

