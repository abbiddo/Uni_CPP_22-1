#include <iostream>
using namespace std;

int main() {
	cout << "입력할 정수의 개수는?";
	int n;
	cin >> n;
	
	if (n < 1) return 0;
	int* p = new int[n];
	
	if (!p) {
		cout << "메모리를 할당할 수 없습니다.";
		return 0;
	}

	for (int i = 0; i < n; i++) cin >> p[i];
	
	int sum = 0;
	for (int i = 0; i < n; i++) sum += p[i];

	cout << "평균 : " << sum / n;
	delete[] p;
}