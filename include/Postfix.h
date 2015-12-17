#ifndef _POSTFIX_H_
#define _POSTFIX_H_
#include "stack.h"

#define _SPACE_ ' '

typedef double VT;

template <class VT>
class Postfix {
private:
	int RightBr(void);
	void DecreasePriority(int);
	int  PriorietyOperator(const char)const;
	int  IsOperator(const char)const;
	int  IsOperand(const char)const;
	Stack<VT> Res;
	Stack<VT> Operator;
	string Str = '0';
public:
	Postfix();
	~Postfix();

	void ProcStr(void);
	void SetString(const string&);
	VT calculate(void);
	void GetValuesOfVariables(void);
};
 


#endif
