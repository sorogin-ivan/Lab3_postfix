#ifndef _STACK_H_
#define _STACK_H_
#include "list.h"

template <class VT>
class Stack {
public:
	Stack(void);
	Stack(const Stack<VT>*);
	~Stack(void);

	// �������� �� �������.
	int IsFull(void) const;

	// �������� �� �������.
	int IsEmpty(void) const;

	// �������� ������� � ����.
	void Push(const VT&);
	
	// ����� ������� �� �����.
	KeyType Pop(void);
private:
	List<VT>* list_;
};

#endif