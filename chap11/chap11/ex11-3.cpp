#include <iostream>
#include <string>
using namespace std;

int main() {
	char cmd[80] = { 0 };
	cout << "cin.get(char*, int)�� ���ڿ��� �н��ϴ�.\n";
	cin.ignore(10);
	cin.getline(cmd, 80);
	cout << cmd << " " << cin.gcount();
	//while (1) {
	//	cout << "�����Ϸ��� exit�� �Է��ϼ��� : ";
	//	cin.get(cmd, 80);	
	//	/* �Է� ���� �����ϸ� ���� �ݺ���
	//	���ϱ� . . . */
	//	if (strcmp(cmd, "exit") == 0) {
	//		cout << "���α׷� ����\n";
	//		return 0;
	//	}
	//	else {
	//		cin.ignore();
	//	}
	//}
}