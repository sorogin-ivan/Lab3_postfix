#ifndef _STACK_H_
#define _STACK_H_
#include "list.h"

template <class VT>
class Stack {
public:
	Stack(void);
	Stack(const Stack<VT>*);
	~Stack(void);

	// Проверка на полноту.
	int IsFull(void) const;

	// Проверка на пустоту.
	int IsEmpty(void) const;

	// Положить элемент в стек.
	void Push(const VT&);
	
	// Взять элемент из стека.
	KeyType Pop(void);
private:
	List<VT>* list_;
};

#endif