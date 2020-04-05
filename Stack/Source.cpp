#include<iostream>
#include "Stack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	TheFulDeep::Stack<char> a;
	cout << "size = " << a.getSize() << endl;
	a.push('a');
	a.push('b');
	a.push('c');
	a.push('d');
	a.push('e');
	a.push('f');
	cout << "pop1 = " << a.pop() << endl;
	cout << "pop2 = " << a.pop() << endl;
	cout << "size = " << a.getSize() << endl;

	cout << "cout" << endl;
	cout << a;

	cout << "pop3 = " << a.pop() << endl;
	cout << "pop4 = " << a.pop() << endl;
	cout << "pop5 = " << a.pop() << endl;
	cout << "pop6 = " << a.pop() << endl;
	//cout << "pop7 = " << a.pop() << endl; //на этой строке выбросится исключение

	cout << "size = " << a.getSize() << endl;
	cout << "isEmpty = " << a.isEmpty() << endl;



	system("pause");
	return 0;
}