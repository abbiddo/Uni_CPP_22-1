#include <iostream>
using namespace std;

void get1() {
	cout << "cin.get() : ";
	int ch;
	while ((ch = cin.get()) != EOF) {
		cout.put(ch);
		if (ch == '\n') break;
	}
}

void get2() {
	cout << "cin.get(char&) : ";
	char ch;
	while (1) {
		cin.get(ch);
		if (cin.eof()) break;
		cout.put(ch);
		if (ch == '\n') break;
	}
}

int main() {
	get1();
	get2();
}