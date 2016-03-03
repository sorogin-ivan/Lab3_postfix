#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include "stack.h"
#include <string>
#include <map>

using namespace std;

typedef float ExpType;

class Postfix
{
private:
	int Operator(char);
	int Line(const string&)const;
	void Bracket(const string&)const;
public:
	string Record(const string&)const;
	ExpType Count(const string&, map<char, ExpType>);
};

#endif
