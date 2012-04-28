/*
 *  ASTree.cpp
 *  Abstract Syntax Tree
 *
 *  Created by Jonathan Maletic on 11/8/11.
 *  Copyright 2012 Kent State University. All rights reserved.
 *
 *  Modified by:
 *
 */

#include "ASTree.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
//
// Reads a srcML file into an internal data structure.
// Then prints out the data structure.
//
char* convertStringtoCstring(std::string&);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Input file name required." << std::endl;
        return(1);
    }

	//handles converting the file name into something usable as an object name. 
	int i = 0, j = 1;
	std::vector<std::string> flist, objlist;
	while(i < argc-1)
	{
		std::string files = argv[j];
		flist.push_back(files);
		size_t found      = files.std::string::find(".");
		std::string obj   = files.std::string::replace(found, 1, "_");
		found			  = obj.std::string::find(".xml");
		obj				  = obj.std::string::erase(found);
		objlist.push_back(obj);
		++i;
		++j;	
	}
	std::vector<std::string> outfiles;
	i = 0, j = 1;
	while(i < argc-1) {
		std::string files = argv[j];
		size_t found = files.find(".");
		files = files.replace(found, 1, ".cpp.xml.cpp");
		std::string out = "p-"+files;
		found = out.find("pcpp.xml");
		out = out.erase(found+1);
		outfiles.push_back(out);
		++i;
		++j;
	}

	i = 0, j = 1;
	int currentfile = 0;
	
	while(i < argc-1){
	std::ifstream xmlFile(argv[j]);
	char *out;
	out = convertStringtoCstring(outfiles[i]);
	std::ofstream cppfile(out);
	srcML program;
	xmlFile >> program;
	program.profilesrcml(objlist, currentfile);
	xmlFile.close();
	cppfile << program << std::endl;
    cppfile.close();
	++i;
	++j;
	++currentfile;
	}
    
        

	return 0;
}
char* convertStringtoCstring(std::string& ConvertMe) {
	size_t len = ConvertMe.length();
    int i = 0;
	char *converted = new char [100];
	while(i < len) {
    converted[i] = ConvertMe[i];
	++i;
	}
	converted[i]=0;
	return converted;
}                                 
