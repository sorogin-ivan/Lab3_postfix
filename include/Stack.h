#ifndef _STACK_H_

#define _STACK_H_

#include "list.h"

template <class PType>

class Stack {

private: 

	List<PType>* pList;

public:

	Stack ();
	Stack (const Stack<PType>&);
	~Stack();
	bool IsFull () const;
	bool IsEmpty () const;
	void Push (const PType&);
	PType Pop(void);

};

template <class PType>
Stack<PType>::Stack ()
{
	pList = new List<PType>();
}

template <class PType>
Stack<PType>::Stack(const Stack<PType>& st)
{
	pList = new List<PType>(*st.pList);
}

template <class PType>
Stack<PType>::~Stack(){
	delete pList;
}

//Проверка на полноту
template <class PType>
bool Stack<PType>::IsFull() const{
	Node<PType>* tmp;
	try{
		tmp = new Node<PType>;
	} 
	catch (...) {
		return true;
	}
	delete tmp;
	return false;
}

//Проверка на пустоту
template <class PType>
bool Stack<PType>::IsEmpty() const
{
	return (pList->getfirst() == 0);
}

//Добавление элемента в стэк
template <class PType>
void Stack<PType>::Push(const PType& key){
	if (IsFull())
		throw("Error: Stack Is Full");
	pList->push(key);
}

//Удаление из стэка
template <class PType>
PType stack<PType>::pop(void)
{
	if (IsEmpty() == 1)
		throw "Error: Stack Is Empty";
	PType tmp = pList->getfirst()->key;
	pList->remove(tmp);
	return tmp;
}

#endif