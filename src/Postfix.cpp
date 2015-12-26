#include "Postfix.h"

Postfix::Postfix(const string& a) 
{
	res = new Stack<char>();
	oper = new Stack<char>();
	v1 = a;
}

Postfix::~Postfix() {
}

int Postfix::operaci(const char a) 
{
	switch (a)
	{
	case '*':
		return 3;
	case '/':
		return 3;
	case '+':
		return 2;
	case '-':
		return 2;
	case '(':
		return 1;
	case ')':
		return 1;
	}
}

int Postfix::prioritet(const char a) 
{
	if ((a == '*') || (a == '/') || (a == '+') || (a == '-') || (a == '(') || (a == ')')) 
		return operaci(a);
	if (((a >= 'a') && (a <= 'z')) || ((a >= 'A') && (a <= 'Z')) || (a == ' ') || ((a >=-1000) && (a <= 1000)))
	return 0;
	else throw "a";
}

char Postfix::skobka()
{
	char a = oper->Pop();
	while (a != '(')
	{
		res->Push(a);
		a = oper->Pop();
	}
	
	return (a);
}

char Postfix::ponizhenie(char a) 
{
	char b = oper->Pop();
	while ((operaci(a)) < (operaci(b)) && (oper->IsEmpty() != true)) 
	{
		res->Push(b);
		b = oper->Pop();
	}
	if (operaci(a) <= operaci(b))
		res->Push(b);
	else oper -> Push(b);
	return a;
}

string Postfix::printres()
{
	char a;
	if (oper->IsEmpty() == 0)
		throw ("Error");
	while (res->IsEmpty() != 1)
	{
		a = res->Pop();	
		while (a == '(')
			a = res->Pop();			
		oper->Push(a);
	}
	string v;
	while (oper->IsEmpty() != 1)
		v.push_back(oper->Pop());	
	return v;
}

string Postfix::postfix () 
{
	if (v1 == "")
		throw ("Error"); 
	char a;
	char tmp;
	int n=0, m=0; 
	for (int i=0; i<v1.length();i++) 
	{
		a = v1[i];
		n = prioritet(a);
		if (n == 0)
			res->Push(a);
		else 
		{
			if (a == ')') 
				a = skobka();
			else if ((n < m) && (a != '('))
				a = ponizhenie(a);
			oper->Push(a);
			m = n;
		}
	}
	if (oper->IsEmpty() != true)
		while (oper->IsEmpty() != true)
		{
			tmp = oper->Pop();
			res->Push(tmp);
		}
	string v2 = printres();
	return v2;
}