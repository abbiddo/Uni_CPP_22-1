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
	cout << "정수 두 개 입력하시든가>> ";
	cin >> a >> b;

	if (bigger(a, b, big)) cout << "same" << endl;
	else cout << big;
}