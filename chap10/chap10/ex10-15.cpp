#include <iostream>
using namespace std;

int main() {
	// 15
	[](int x, int y) {cout << "합은 " << x + y; }(2, 3);
	cout << endl << endl;

	// 16
	auto love = [](string a, string b) {cout << a << "보다 " << b << "이 좋아" << endl; };
	love("너", "돈");
	love("만두", "냉면");
	cout << endl;

	// 17
	double pi = 3.14;
	auto calc = [pi](int r)->double { return pi * r * r; };
	cout << "면적은 " << calc(3) << endl << endl;

	// 18
	int sum = 0;
	[&sum](int x, int y) {sum = x + y; }(2, 3);
	cout << "합은 " << sum << endl << endl;
}