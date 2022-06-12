#include <iostream>
using namespace std;

int getExp(int base, int exp) {
	if (base <= 0 || exp <= 0) throw "음수 X";
	
	int value = 1;
	for (int i = 0; i < exp; i++) value *= base;
	return value;
}

int main() {
	int v = 0;
	try {
		v = getExp(2, -3);			// throw로 넘어가면 반복문 break 같은 느낌인가 봐
		cout << "2의 3승은 " << v << " 입니다.\n";
		v = getExp(2, 3);
		cout << "2의 3승은 " << v << " 입니다.\n";
	}
	catch (const char* s) {
		cout << "예외 " << s << endl;
	}
}