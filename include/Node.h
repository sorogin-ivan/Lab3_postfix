#ifndef __NODE_H__

#define __NODE_H__

#include <iostream>

#include <cstdlib>

const int MAX_STRING = 100000;

using namespace std;

template <class PType>

class Node {

public:

	PType key;
	Node<PType>* pNext;
	Node() {pNext = 0;};
	Node(const PType& k) {key = k; pNext = 0;};

};

#endif