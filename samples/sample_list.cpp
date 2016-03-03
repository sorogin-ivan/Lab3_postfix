#include "list.h"

void main()
{    
	setlocale(LC_ALL, "Russian");
    List<int> *l = new List<int>;
    cout << "Изначальный" << endl;
    l->Print();
    cout << "добавка элемента" << endl;
    l->Push(1);
    l->Print();
	cout << "Проверка добавления в конце списка" << endl;
    l->PushEnd(3);
    l->Print();
    cout << "Проверка добавления элемента" << endl;
    l->PushAfter(1, 2);
    l->Print();
    cout << "Проверка удаления" << endl;
    l->Remove(1);
    l->Print();
    cout << endl;
}