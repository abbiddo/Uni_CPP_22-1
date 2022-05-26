#include <iostream>
using namespace std;

int main() {
	// 15
	[](int x, int y) {cout << "���� " << x + y; }(2, 3);
	cout << endl << endl;

	// 16
	auto love = [](string a, string b) {cout << a << "���� " << b << "�� ����" << endl; };
	love("��", "��");
	love("����", "�ø�");
	cout << endl;

	// 17
	double pi = 3.14;
	auto calc = [pi](int r)->double { return pi * r * r; };
	cout << "������ " << calc(3) << endl << endl;

	// 18
	int sum = 0;
	[&sum](int x, int y) {sum = x + y; }(2, 3);
	cout << "���� " << sum << endl << endl;
}