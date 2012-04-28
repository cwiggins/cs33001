/*
 *  ASTree.cpp
 *  Abstract Syntax Tree
 *
 *  Created by Jonathan Maletic on 11/8/11.
 *  Copyright 2012 Kent State University. All rights reserved.
 *
 *
 *  Modified by: Curtiss J Wiggins
 *
 */

#include "ASTree.hpp"
#include <string>


///////////////////////////////////////////////////////////////////////////////
//Used to start the profiling of a srcml object. This calls
//profileHeaders(std::string, int), profileoutputs(std::string) which carry out
//most of heavy lifting in creating a new ASTree node for insertion into the
//proper spot in the tree. The int parameter is used to determine which file the
//program is currently in so that way the ASTree node is created correctly. 
void srcML::profilesrcml(std::vector<std::string>& files, int cfile){
   

	std::vector<std::string>::const_iterator it = files.begin();
	for(int idx = 0; idx < cfile; ++idx) ++it;

	std::string fptr = *it;
	//does the proper function calling depending on the value of cfile which
	//represents the current file the program is working on profiling.
	if(cfile == 0){
	tree -> profileHeaders(files, cfile);

    //creates the std::string to used in the profileoutputs funtion so that way
	//when it recurses through the program is not recreating the ASTree node
	//over and over. Create the correct string once and pass it to the function. 
	int i = 0, j = files.size();
	std::string temp, outs;
	while(i < j){
		temp = "std::cout << ";
		temp += files[i] + " << std::endl;\n";
		outs += temp;
		++i;
	}
    std::string final = "\nstd::cout << functions << std::endl;\n" + outs +"\n";

    tree -> profileoutputs(final);

	tree->profiledeclarations(fptr);
	tree->profileFunctions(fptr);

	}
	else{
		tree -> profileHeaders(files, cfile);
		tree -> profiledeclarations(fptr);
		tree -> profileFunctions(fptr);
		
	}


}
/////////////////////////////////////////////////////////////////////
// Destructor for srcML
//
srcML::~srcML() {
   
	//determines if an ASTree object actually exists. If it does it proceeds to
	//delete the tree by calling ASTree's destructor. If no tree exists it exits
	//the function.
   if(tree){ 
	delete tree;
   }
    
}


/////////////////////////////////////////////////////////////////////
// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    
    header = actual.header;
	tree = actual.tree -> copyASTree();
    
}

/////////////////////////////////////////////////////////////////////
// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    
    std::string Theader = header;
	header = b.header;
	b.header = Theader;

	ASTree *Ttree = tree;
	tree = b.tree;
	b.tree = Ttree;
}

/////////////////////////////////////////////////////////////////////
// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    //just swaps the pointers and returns *this which now has rhs' value.
	swap(rhs);
    
    return *this;
}

/////////////////////////////////////////////////////////////////////
// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    src.tree = new ASTree(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}


/////////////////////////////////////////////////////////////////////
// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    if (TAGS) out << "<" << src.header << ">" << std::endl;
    src.tree->print(out, 0);
    return out;
}

void ASTree::profiledeclarations(std::string& file) {

	std::vector<ASTree*>::iterator it = child.begin();
	for(; it != child.end(); ++it){
		if((*it)->nodeType == category) {
			if((*it)->tag == "expr_stmt") {
				ASTree *ntoken = new ASTree(token);
				std::string tmp = "  " + file + ".count(__LINE__);\n";
				ntoken -> text = tmp;

				++it;
				it = child.insert(it, ntoken);
			}
			else
				(*it) -> profiledeclarations(file);
		}
	}
}

void ASTree::profileFunctions(std::string& file) {

	std::vector<ASTree*>::iterator it = child.begin();
	for(; it != child.end(); ++it) {
		if((*it)->nodeType == category) {
			if((*it)->tag == "function" || (*it)->tag == "constructor") {
				std::vector<ASTree*>::iterator fitr = (*it)->child.begin();

				while((*fitr)->tag != "name") ++fitr;

				ASTree *ntoken = new ASTree(token);
				ntoken->text= "\nfunctions.count(\"" + getName(fitr) + "\");";

				while((*fitr)->tag != "block") ++fitr;

				std::vector<ASTree*>::iterator bitr = (*fitr)->child.begin();
				++bitr;
				(*fitr)->child.insert(bitr, ntoken);
			}
			else
				(*it)->profileFunctions(file);
		}
	}
}


void ASTree::profileHeaders(std::vector<std::string>& files, int cfile) {
    //Using the value of the cfile, which denotes the current file the program
	//is in, the correct string is built then inserted into a new ASTree node as
	//it's text portion. If cfile is greater than 0 the string builds with the
	//include and declares the function and it's own name variable as externs. 
	int idx = 0, j = files.size();
	std::string temp, includes;
    ASTree *nptr = new ASTree(token);
    if(cfile == 0){
		includes = "\n#include \"profile.hpp\"\nprofile functions;\n";
		while(idx < j){
			temp = "profile " + files[idx] + ";\n";
			includes += temp;
			++idx;
		}
    }
	else{
		
		includes = "\n#include \"profile.hpp\"\nextern profile functions;\n";
		temp = "extern profile " + files[cfile] + ";\n";
		includes += temp;
	}
	includes += "\n";
    nptr -> text = includes;

	//Loop goes until a node of the type category is found. It determines if the
	//category is a function, constuctor, or destructor. If it one of these it
	//inserts the new ASTree node before and then updates the iterator to the
	//new memory loactions. After insertion the loop end so that way no more
	//insertions happen. Don't need the include "profile.hpp" and the profile
	//objects in there more than once. 
	std::vector<ASTree*>::iterator i = child.begin();
	for(;i != child.end(); ++i)
		if((*i)->nodeType==category) {
			if((*i)->tag == "function" ||
			   (*i)->tag == "constructor" ||
			   (*i)->tag == "destructor") {

				i = child.insert(i, nptr);
				break;
				}
			}
		}



void ASTree::profileoutputs(std::string& outs) {

	//Loops goes until it finds any category node and checks to see if the tag
	//equals "return". If it does equal return then it inserts the output
	//statements and updates the iterator to the new memory locations. Then the
	//iterator is moved back to its previous position so that way it can look
	//for more return statements to insert the output statements before.
	//Completes when no more returns are found in the tree.  
	std::vector<ASTree*>::iterator i = child.begin();
	for(;i != child.end(); ++i) {
		if((*i)->nodeType == category){
			if((*i)->tag == "return") {
				ASTree *nptr = new ASTree(token);

				nptr -> text = outs;
				i = child.insert(i, nptr);
				++i;

			}
			else
				(*i)->profileoutputs(outs);
		}
	}
}

std::vector<ASTree*>::iterator ASTree::lookForInsertSpot(ASTree* node) {
	std::vector<ASTree*>::iterator it = node->child.begin();

	while(it != node->child.end()) {
		if((*it)->tag == "block")
			return it;

		if((*it)->nodeType == category)
			return lookForInsertSpot(*it);

		++it;
	}
}

std::string ASTree::getName(std::vector<ASTree*>::iterator r) const {
	return ((*r)->child[0]->text);
}
/////////////////////////////////////////////////////////////////////
// Destructor for ASTree
//
ASTree::~ASTree() {
    
    for(std::vector<ASTree*>::const_iterator i = child.begin(); i != child.end(); ++i)
		delete *i;

                                                                        
    
}


/////////////////////////////////////////////////////////////////////
// Constructs a category, token, or whitespace node for the tree.
//
ASTree::ASTree(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
		case whitespace:
            text = s;
            break;
    }
}


/////////////////////////////////////////////////////////////////////
// Copy Constructor for ASTree
//
ASTree::ASTree(const ASTree& actual) {
    
    switch(actual.nodeType){
		case category:
			tag = actual.tag;
			closeTag = actual.closeTag;
			for(std::vector<ASTree*>::const_iterator i = actual.child.begin(); i != actual.child.end(); ++i)
				child.push_back((*i) -> copyASTree());
			break;
		case token:
		case whitespace:
			text = actual.text;
			break;
	}

}

/////////////////////////////////////////////////////////////////////
// Constant time swap for ASTree
//
void ASTree::swap(ASTree& b) {
    
    std::swap(nodeType, b.nodeType);
	std::swap(tag, b.tag);
	std::swap(closeTag, b.closeTag);
	std::swap(text, b.text);

	child.swap(b.child);
}

/////////////////////////////////////////////////////////////////////
// Assignment for ASTree
//
ASTree& ASTree::operator=(ASTree rhs) {
    
    swap(rhs);
    
    return *this;                               
    
}
                                                                                            
ASTree* ASTree::copyASTree(){
	
	nodes tnode = nodeType;
	
	ASTree* temp = new ASTree(tnode);

	temp -> tag = tag;
	temp -> closeTag = closeTag;
	temp -> text = text;

	for(std::vector<ASTree*>::const_iterator i = child.begin(); i != child.end(); ++i)
		temp -> child.push_back((*i) -> copyASTree());

	return temp;
}


/////////////////////////////////////////////////////////////////////
// Read in and construct ASTree
// REQUIRES: '>' was previous charater read 
//           && this == new ASTree(category, "TagName")
//
//
std::istream& ASTree::read(std::istream& in) {
    ASTree *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                //Found a tag 
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                  //Found close tag, stop recursion
            }
            subtree = new ASTree(category, temp);  //New subtree
            subtree->read(in);                     //Read it in
            in.get(ch);
            child.push_back(subtree);              //Add it to child
        } else {                       //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i = tokenList.begin(); i != tokenList.end(); ++i){
                if (isspace((*i)[0])) 
                    subtree = new ASTree(whitespace, *i);
                else
                    subtree = new ASTree(token, *i);
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}


/////////////////////////////////////////////////////////////////////
// Print an ASTree 
// REQUIRES: indent >= 0
std::ostream& ASTree::print(std::ostream& out, int indent) const {
    if (TAGS) out << std::setw(indent) << " ";
    if (TAGS) out << "<" << tag << ">" << std::endl; 
    for (std::vector<ASTree*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        switch ((*i)->nodeType) {
            case category:
                (*i)->print(out, indent + 4);
                break;
            case token:
                //out << std::setw(indent) << " ";
                out << (*i)->text; // << std::endl;
                break;
            case whitespace:
                out << (*i)->text;
                break;
        }
    }
    if (TAGS) out << std::setw(indent) << " ";
    if (TAGS) out << "<" << closeTag << ">" << std::endl;
    return out;
}

    
    
    

/////////////////////////////////////////////////////////////////////
// Utilities
//

/////////////////////////////////////////////////////////////////////
// Reads until a ch is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != ch for all i.
//
std::string readUntil(std::istream& in, char ch) {
	std::string result;
    char key;
    in.get(key);
    while (!in.eof() && (key != ch)) {
        result += key;
        in.get(key);
    }
    
    return result;
}

/////////////////////////////////////////////////////////////////////
// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
//
std::string unEscape(std::string s) {
    unsigned pos = 0;
    while ((pos = s.find("&gt;")) != s.npos)  s.replace(pos, 4, ">");
    while ((pos = s.find("&lt;")) != s.npos)  s.replace(pos, 4, "<");
    while ((pos = s.find("&amp;")) != s.npos) s.replace(pos, 5, "&");
    return s;
}


/////////////////////////////////////////////////////////////////////
// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}  
//
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string              temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

