#ifndef _POSTFIX_H_
#define _POSTFIX_H_

#include "Stack.h"
#include <string>

using namespace std;

class Postfix {
private:
	
	Stack<char>* res; 
	Stack<char>* oper;	
	string v1; 

public:
	Postfix(const string&);
	~Postfix();
	int operaci (const char);
	int prioritet (const char); 
	char skobka (); 
	char ponizhenie (char a); 
	string printres (); 
	string postfix (); 
};
 
#endif
