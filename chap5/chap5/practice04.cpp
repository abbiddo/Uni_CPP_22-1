#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big) {
	if (a < b) big = b;
	else big = a;

	if (a == b) return true;
	else return false;
}

int main() {
	int a, b, big;
	cout << "���� �� �� �Է��Ͻõ簡>> ";
	cin >> a >> b;

	if (bigger(a, b, big)) cout << "same" << endl;
	else cout << big;
}