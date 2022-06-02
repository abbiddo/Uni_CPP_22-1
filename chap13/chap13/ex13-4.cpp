#include <iostream>
using namespace std;

int main() {
	int n, sum, average;

	while (1) {
		cout << "합 : ";
		cin >> sum;
		cout << "인원수 : ";
		cin >> n;
		try {
			if (n == 0) throw n;
			else average = sum / n;
		}
		catch (int x) {		// double 형으로 하면 실행 오류 발생 
			cout << "예외 " << n << "으로 나눌 수 없음\n";
			average = 0;
			cout << endl;
			continue;
		}
		cout << "평균 = : " << average << endl << endl;
	}
}