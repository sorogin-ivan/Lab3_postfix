#ifndef _LIST_H_

#define _LIST_H_

#include "Node.h"

template <class PType>

class List {

private:
	
	Node<PType>* pFirst;

public:

	List (void);
	~List();
	List (const List<PType> &l);	
	void Push (const PType& tmp);
	Node<PType>* Search(const PType& key);
	void PushAfter (const PType& s, const PType& key);
	void PushBefore (const PType& s, const PType& key);
	void PushEnd (const PType&);
	void Remove (const PType& key);
	Node<PType>* GetFirst(void);

};

template <class PType> 
List<PType>::List(void) {
	pFirst = 0;
}

template <class PType> 
List<PType>::List(const List<PType>& l) 
{
	pFirst = 0;
	Node<PType>* tmp = l.pFirst;
	while (tmp != 0)
	{
		PushEnd(tmp->key);
		tmp = tmp->pNext;
	}
}


template <class PType> 
List<PType>::~List() {
	delete pFirst;
}

// добавление элемента в начало списка
template <class PType>
void List<PType>::Push (const PType& tmp) 
{
	Node<PType>* n = new Node<PType>;
	n->key = tmp;
	n->pNext = pFirst;
	pFirst = n;
}

//Поиск элемента без предыдущего
template <class PType>
Node<PType>* List<PType>::Search (const PType& k)
{
	Node<PType>* elem = pFirst;
	while (elem != 0) 
	{
		if (elem->key == k)
			break;
		elem = elem->pNext;
	}
	if (elem == 0)
		return 0;
	return elem;
}

// добавление элемента после элемента с ключом s
template <class PType>
void List<PType>::PushAfter (const PType& s, const PType& key)
{
	Node<PType>* elem = Search(s);
	if (elem == 0)
		throw ("Error: Not Found");
	Node<PType>* tmp;
	tmp = elem->pNext;
	Node<PType>* node = new Node<PType>(key);
	elem->pNext = node;
	node->pNext = tmp;
}

// добавление элемента перед элементом с ключом s
template <class PType>
void List<PType>::PushBefore (const PType& s, const PType& key)
{
	if (pFirst->key == key){ 
		Push(key);
		return;
	}
	Node<PType>* elem = pFirst->pNext;
	Node<PType>* tmp = pFirst;
	while (elem != 0) 
	{
		if (elem->key == s)
			break;
		elem = elem->pNext;
		tmp = tmp->pNext;
	}
	if (elem == 0)
		throw ("Error: Not Found");
	Node<PType>* tmp2 = elem->pNext;
	Node<PType>* node = new Node<PType>(key);
	tmp = node;
	tmp->pNext = elem;
	elem->pNext = tmp2;
}

// добавление элемента в конец списка
template <class PType> 
void List<PType>::PushEnd (const PType& key) 
{
	if (pFirst == 0)
	{
		push(key);
		return;
	}
	Node<PType>* node = new Node<PType>(key);
	Node<PType>* tmp = pFirst;
	while (tmp->pNext != 0)
		tmp = tmp->pNext;
	tmp->pNext = node;
}

//удаление элемента с ключом k
template <class PType>
void List<PType>::Remove (const PType& k)
{
	if (pFirst->key == k){ 
		pFirst = pFirst->pNext;
		return;
	}
	Node<PType>* elem = pFirst->pNext;
	Node<PType>* tmp = pFirst;
	while (elem != 0) 
	{
		if (elem->key == k)
			break;
		elem = elem->pNext;
		tmp = tmp->pNext;
	}
	if (elem == 0)
		throw ("Error: Not Found");
	 tmp->pNext = elem->pNext;
}

// получение указатеря на первый элемент списка
template <class PType>
Node<PType>* List<PType>::GetFirst(void)
{
    return pFirst;
}

#endif