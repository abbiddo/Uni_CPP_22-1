#include <iostream>
using namespace std;

int main() {
	int n, sum, average;

	while (1) {
		cout << "�� : ";
		cin >> sum;
		cout << "�ο��� : ";
		cin >> n;
		try {
			if (n == 0) throw n;
			else average = sum / n;
		}
		catch (int x) {		// double ������ �ϸ� ���� ���� �߻� 
			cout << "���� " << n << "���� ���� �� ����\n";
			average = 0;
			cout << endl;
			continue;
		}
		cout << "��� = : " << average << endl << endl;
	}
}