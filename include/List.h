#ifndef _LIST_H_
#define _LIST_H_
#include "Node.h"

template <class VT>
class List { 
public:
    List(void);
    List(const Node<VT>*);
    List(const VT&);
    List (const List<VT>*);
    ~List(void);

    int operator== (const List&)const;
    int operator!= (const List&)const;

    // Поиск указателя на узел первого вхождения элемента в список.
    Node<VT>* FindFirstIn(const VT&) const;

    // Вставить элемент в начало списка.
    int  Push       (const VT&);

    // Вставить элемент после указанного узла.
    int  PushAfter  (const VT&, const VT&);

    // Вставить элемент до указанного узла.
    int  PushBefore (const VT&, const VT&);

    // Вставить элемент в конец
    int  PushEnd   (const VT&);

    // Удалить первый узел, содерщищий указанный ключ.
    void  Remuve    (const VT&);

    // Получить указатель на первый элемент списка.
    Node<VT>* GetFirst  (void) const;
private:
    // Указатель на первый узел списка.
    Node* First;
};



#endif