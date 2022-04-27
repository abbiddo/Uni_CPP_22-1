#include <iostream>
#include <string>
using namespace std;

int main() {
	string a("aa");
	string b = "bb";
	string aa = a;
	string bb(b);

	a.append(b);

	cout << a << endl;
	cout << aa << endl;
	cout << b << endl;
	cout << bb << endl;

	string num = "123";
	int n = stoi(num);

	cout << n << endl;

	string* p = new string("C++");
	cout << *p << endl;

	*p = "C";
	cout << *p << endl;

	(*p).append("++++");
	cout << *p << endl;

	delete p;
}