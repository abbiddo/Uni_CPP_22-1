#include <iostream>
using namespace std;

int getExp(int base, int exp) {
	if (base <= 0 || exp <= 0) throw "���� X";
	
	int value = 1;
	for (int i = 0; i < exp; i++) value *= base;
	return value;
}

int main() {
	int v = 0;
	try {
		v = getExp(2, -3);			// throw�� �Ѿ�� �ݺ��� break ���� �����ΰ� ��
		cout << "2�� 3���� " << v << " �Դϴ�.\n";
		v = getExp(2, 3);
		cout << "2�� 3���� " << v << " �Դϴ�.\n";
	}
	catch (const char* s) {
		cout << "���� " << s << endl;
	}
}