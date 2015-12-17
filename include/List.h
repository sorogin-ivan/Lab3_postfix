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

    // ����� ��������� �� ���� ������� ��������� �������� � ������.
    Node<VT>* FindFirstIn(const VT&) const;

    // �������� ������� � ������ ������.
    int  Push       (const VT&);

    // �������� ������� ����� ���������� ����.
    int  PushAfter  (const VT&, const VT&);

    // �������� ������� �� ���������� ����.
    int  PushBefore (const VT&, const VT&);

    // �������� ������� � �����
    int  PushEnd   (const VT&);

    // ������� ������ ����, ���������� ��������� ����.
    void  Remuve    (const VT&);

    // �������� ��������� �� ������ ������� ������.
    Node<VT>* GetFirst  (void) const;
private:
    // ��������� �� ������ ���� ������.
    Node* First;
};



#endif