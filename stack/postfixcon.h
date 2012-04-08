/*
 * =====================================================================================
 *
 *       Filename:  postfix.h
 *
 *    Description:  Just the free functions for use in converting an infix
 *    expression into a postfix one then finally into rudimentary assembly.
 *
 *        Version:  1.0
 *        Created:  03/30/2012 09:55:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Curtiss J Wiggins 
 *   Organization:  cs33001
 *
 * =====================================================================================
 */
#ifndef POSTFIX_H_
#define POSTFIX_H_
#include <iostream>
#include <vector>
#include"stack.h"
#include "../string/string.h"
#include<cstdlib>

string infix2postfix(std::vector<string>& infix);

void output_usage_and_exit(char cmd[]);

string infix_to_postfix(std::vector<string>& infix);

Stack<string> postfix2assembler(std::vector<string>& p);

void outputassembler(std::ostream& out, Stack<string>& assembler);

#endif
