#include <iostream>
using namespace std;

bool average(int a[], int size, int& avg) { // int &avg나 int& avg나 같음
	if (size <= 0) return false;
	int sum = 0;
	for (int i = 0; i < size; i++) sum += a[i];
	avg = sum / size;
	return true;
}

int main() {
	int x[] = { 0,1,2,3,4,5 };
	int avg;

	if (average(x, 6, avg)) cout << avg << endl;
	else cout << "매개 변수 오류" << endl;

	if (average(x, -2, avg)) cout << avg << endl;
	else cout << "매개 변수 오류" << endl;
}