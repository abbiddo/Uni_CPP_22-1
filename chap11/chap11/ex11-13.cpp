#include <iostream>
using namespace std;

istream& question(istream& ins) {
	cout << "�ſ�� �ſ�� ���� ���� ���ڴ�? ";
	return ins;
}

// �ȿ��� �Է� �� �޾�?

//istream& question(istream& ins, string answer) {
//	cout << "�ſ�� �ſ�� ���� ���� ���ڴ�?";
//	ins >> answer;
//	return ins;
//}

int main() {
	string answer;
	cin >> question >> answer;
	cout << answer << endl;
}