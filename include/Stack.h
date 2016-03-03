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
	int operator==(const Stack<PType>& s)const;
	int operator!=(const Stack<PType>& s)const;
	void Print()const;
	PType GetKey();

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
PType Stack<PType>::Pop(void)
{
	if (IsEmpty() == 1)
		throw "Error: Stack Is Empty";
	PType tmp = pList->GetFirst()->key;
	pList->Remove(tmp);
	return tmp;
};

template <class PType>
int Stack<PType>::operator==(const Stack<PType>& s)const
{
	return (*List == *(s.List));
}

template <class PType>
int Stack<PType>::operator!= (const Stack<PType>& s)const
{
	return (*List != *(s.List));
}

template <class PType>
void Stack<PType>::Print()const
{
	Stack<PType>* s = new Stack<PType>(*this);
	while (!(s->IsEmpty()))
		cout << s->Pop() << endl;
}

template <class PType>
PType Stack<PType>::GetKey()
{
	if (IsEmpty())
		throw
		exception ("Stack is empty");
	return List->getfirst()->key;
}

#endif