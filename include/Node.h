#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

template <class VT>
class Node {
    VT key;
    Node<VT>* Next;

    Node(void);
    Node(const VT& keyX);
    Node(const Node<VT>* node);
    ~Node(void);
};

#endif