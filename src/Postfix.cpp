#include "stack.h"
#include "postfix.h"


int Postfix::Operator(char k)
{
	switch (k)
	{
		case '+':
			return 2;
		case '-':
			return 2;
		case '*':
			return 3;
		case '/':
			return 3;
		case '(':
			return 1;
		case ')':
			return 1;
	}
	return 0;
}

void Postfix::Bracket(const string& str)const
{
	int l = 0;
	int r = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
			l++;
		if (str[i] == ')')
			r++;
	}
	if (l != r)
		throw
		exception("You entered incorrect string");
}

int Postfix::Line(const string &s) const
{
	if (s.length() == 0)
		return 1;
	Postfix p;
	if (s.length() == 1)
		if (p.Operator(s[0]))
			return 1;
	if (p.Operator(s[0]) > 1)
		return 1;
	char left;
	char right;
	int m = 0;
	for (int i, j = 1; j < s.length(); j++)
	{
		i = m;
		left = s[i];
		right = s[j];
		if (right == ' ')
			continue;
		if ((!p.Operator(left)) && (!p.Operator(right)))
			return 1;
		if ((left == '(') && ((right == '+') || (right == '*') || (right == '/')))
			return 1;
		if ((right == ')') && ((left == '-') || (left == '+') || (left == '*') || (left == '/')))
			return 1;
		if ((left == ')') && (right == '('))
			return 1;
		if ((left == right) && (left == '('))
			continue;
		if ((left == right) && (left == ')'))
			continue;
		if (p.Operator(left) == p.Operator(right))
			return 1;
		if ((left == '*') && ((right == '+') || (right == '-') || (right == '/') || (right == ')') || (right == '+')))
			return 1;
		if ((left == '/') && ((right == '+') || (right == '-') || (right == '*') || (right == ')') || (right == '+')))
			return 1;
		if ((left == '+') && ((right == '*') || (right == '-') || (right == '/') || (right == ')') || (right == '+')))
			return 1;
		if ((left == '-') && ((right == '+') || (right == '-') || (right == '/') || (right == ')') || (right == '+')))
			return 1;
		if ((right == ')') && ((left == '+') || (left == '-') || (left == '*') || (left == '/')))
			return 1;
		m = j;
	}
	return 0;
}


string Postfix::Record(const string& infstring)const
{

	if (!infstring.length())
		throw
		exception("String is empty");
	Bracket(infstring);
	int tmp1 = Line(infstring);
	if (tmp1)
		throw
		exception("You have entered incorrect string");
	map <char, int> operations;
	operations['*'] = 3;
	operations['/'] = 3;
	operations['+'] = 2;
	operations['-'] = 2;
	operations['('] = 1;
	Stack<char> result;
	Stack<char> operationsstack;
	char temp;
	for (int i = 0; i < infstring.length(); i++)
	{
		if (infstring[i] == ' ')
			continue;
		temp = infstring[i];
		if (operations.count(temp))
		{
			if ((!operationsstack.IsEmpty()) && (operations[temp] <= operations[operationsstack.GetKey()]) && (temp != '('))
				while ((!operationsstack.IsEmpty()) && (operations[temp] <= operations[operationsstack.GetKey()]))
					result.Push(operationsstack.Pop());
			operationsstack.Push(temp);
			continue;
		}
		if (((temp >= 'a') && (temp <= 'z')) || ((temp >= 'A') && (temp <= 'Z')))
		{
			result.Push(temp);
			continue;
		}
		if (temp == ')')
		{
			char t = '0';
			while ((!operationsstack.IsEmpty()) && (t != '('))
			{
				t = operationsstack.Pop();
				result.Push(t);
			}
			if (t == '(')
				result.Pop();
			continue;
		}
		throw 
			exception("You have entered anavailable symbol");
	}
	while (!operationsstack.IsEmpty())
		result.Push(operationsstack.Pop());
	if (result.IsEmpty())
		throw 
			exception("You haven't entered any expression");
	string resultstring = "";
	while (!result.IsEmpty())
		operationsstack.Push(result.Pop());
	while (!operationsstack.IsEmpty())
		resultstring += operationsstack.Pop();
	return resultstring;
}

ExpType Postfix::Count(const string& poststring, map<char, ExpType> values)
{
	if (poststring == "")
		throw
		exception("String is empty");
	Stack<ExpType> result;
	char tmp;
	ExpType leftOperand;
	ExpType rightOperand;
	for (int i = 0; i < poststring.length(); i++) 
	{
		tmp = poststring[i];
		if (poststring[poststring.length() - 1] == '=')
			values[poststring[0]] = 0;
		if (((tmp >= 'a') && (tmp <= 'z')) || ((tmp >= 'A') && (tmp <= 'Z'))) 
		{
			if (!values.count(tmp))
			{
				cout << "Enter " << tmp << ": ";
				cin >> values[tmp];
			}
			result.Push(values[tmp]);
			continue;
		}
		if (result.IsEmpty())
			throw 
			exception("There is no result");
		rightOperand = result.Pop();
		if ((result.IsEmpty()) && (tmp == '-'))
		{
			result.Push(-rightOperand);
			continue;
		}
		if (result.IsEmpty())
			throw 
			exception("There is no result");
		leftOperand = result.Pop();
		switch (tmp)
		{
		case '+':
			result.Push(leftOperand + rightOperand);
			break;
		case '-':
			result.Push(leftOperand - rightOperand);
			break;
		case '*':
			result.Push(leftOperand * rightOperand);
			break;
		case '/':
			if (rightOperand == 0)
				throw
				exception("You can't divide by 0");
			result.Push(leftOperand / rightOperand);			
			break;
		}
	}

	ExpType res = result.Pop();
	if (!result.IsEmpty())
		throw
		exception("You have entered incorrect string");
	return res;
}