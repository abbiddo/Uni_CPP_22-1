#include <iostream>
using namespace std;

int main() {
	cout << "�Է��� ������ ������?";
	int n;
	cin >> n;
	
	if (n < 1) return 0;
	int* p = new int[n];
	
	if (!p) {
		cout << "�޸𸮸� �Ҵ��� �� �����ϴ�.";
		return 0;
	}

	for (int i = 0; i < n; i++) cin >> p[i];
	
	int sum = 0;
	for (int i = 0; i < n; i++) sum += p[i];

	cout << "��� : " << sum / n;
	delete[] p;
}