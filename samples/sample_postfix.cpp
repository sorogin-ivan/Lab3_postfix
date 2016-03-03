#include <iostream>
#include "postfix.h"

using namespace std;


int main(void)
{
	string str;
	setlocale(LC_ALL, "Russian");
	cout << "Введите выражение, которое необходимо перевести в постфиксную форму" << endl << 
		"Выражения могут состоять только из латинских букв и операций *,/,-,+,=,'(',')' и, разумеется, из цыфр"  << endl;
	getline(cin, str);
	map<char, ExpType> m;
	Postfix p;
	string str1;
	try
	{
		str1 = p.Record(str);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		return 0;
	}

	cout << "Польская форма: " << str1 << endl;
	ExpType result;
	try
	{
		result = p.Count(str1, m);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		return 0;
	}
	cout << "Результат: " << result << endl;
	return 0;
}