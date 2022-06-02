#include <iostream>
using namespace std;

bool getExp(int base, int exp, int& ret) {
	if (base <= 0 || exp <= 0) return false;

	int value = 1;
	for (int i = 0; i < exp; i++) value *= base;
	ret = value;
	return true;
}

int main() {
	int v = 0;
	if (getExp(2, 3, v)) cout << v << endl;
	else cout << "돌아가\n";

	if (getExp(2,-3,v)) cout << v << endl;
	else cout << "돌아가\n";
}