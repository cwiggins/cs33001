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

				s.push(lhs+" "+rhs+" "+op);
			}else{
				s.push(infix[i]);
			}
		}
		++i;
	}
	return s.pop();
}


Stack<string> postfix2assembler(std::vector<string>& p){
	Stack<string> s, a, as;

	int i = 0, j = p.size();
	string rhs, lhs, op;
    char tmp;
	int var = 1;
	while(i<j){
		if((p[i]=='*') || (p[i]=='+') || (p[i]== '-') || (p[i]== '/')){
	   
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
			tmp = var + '0';
		     string tmp_var(tmp); 
           if(lhs[0]!='T' && lhs[1]!='M' && lhs[2]!='P'){
		
			as.push("LD");
			as.push(lhs);
			as.push(op);
			as.push(rhs);
			as.push("ST");
			as.push("TMP"+tmp_var);
			s.push("TMP"+tmp_var);
			
		   }else{
			   as.push("LD");
			   as.push(rhs);
			   as.push(op);
			   as.push(lhs);
			   as.push("ST");
			   as.push("TMP"+tmp_var);
			   s.push("TMP"+tmp_var);
		   }
		   ++var; 
		}else{
		    s.push(p[i]);
			}
		++i;

	}
	
	while(!as.IsEmpty()){
		string operand, op2;
		operand = as.pop();
		op2 = as.pop();
		a.push(op2);
		a.push(operand);
	}
	return a;
}

void outputassembler(std::ostream& out, Stack<string>& assembler){
	
	   while(!assembler.IsEmpty()){
		out <<"    " << assembler.pop() << "    " << assembler.pop() << std::endl; 
	}
}


void output_usage_and_exit(char cmd[]){
	std::cerr << "Usage: " << std::endl;
	std::cerr << cmd << " input_file  " << "[output_file]" <<std::endl;

	exit (1);
}

