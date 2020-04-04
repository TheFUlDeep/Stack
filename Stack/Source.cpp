#include<iostream>
#include "Stack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	TheFulDeep::Stack<char> a;
	cout << a.getSize() << endl;
	a.push('a');
	a.push('b');
	a.push('c');
	a.push('d');
	a.push('e');
	a.push('f');
	a.pop(2);
	cout << a.getSize() << endl << endl;

	cout << "cout" << endl;
	cout << a;

	system("pause");
	return 0;
}