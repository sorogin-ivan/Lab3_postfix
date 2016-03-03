#include "stack.h"

void main()
{
	setlocale(LC_ALL, "Russian");
	int i = 0;
	Stack<int>* s = new Stack<int>();
	cout << "Введите размер" << endl;
	int n;
	cin >> n;
	int k;
	for (i=0; i < n; i++)
	{
		cout << "Введите ваши элементы: ";
		cin >> k;
		s->Push(k);
	}
	cout << endl << "Вы добавили " << n << " элемента(-ов) " << endl;
	s->Print();	
	cout << endl << "Удалили один элемент " << endl;
	s->Pop();
	s->Print();
	return;
}