#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	cout << "���� ���ڿ��� �Է��ϼ���." << endl;
	getline(cin, s, '\n');

	int sum = 0, startindex=0;

	while (1) {
		int findex = s.find('+', startindex);
		if (findex == -1) {
			string part = s.substr(startindex);
			if (part == "") break;
			cout << part << endl;
			sum += stoi(part);
			break;
		}

		int count = findex - startindex;
		string part = s.substr(startindex, count);
		cout << part << endl;
		sum += stoi(part);
		startindex = findex + 1;
	}
	cout << "���ڵ��� ����" << sum;
}