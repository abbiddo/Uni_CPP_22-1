#include <iostream>
#include <string>
using namespace std;

int main() {
	char cmd[80] = { 0 };
	cout << "cin.get(char*, int)로 문자열을 읽습니다.\n";
	while (1) {
		cout << "종료하려면 exit를 입력하세요 : ";
		cin.get(cmd, 80);	
		/* 입력 없이 엔터하면 무한 반복함
		왜일까 . . . */
		if (strcmp(cmd, "exit") == 0) {
			cout << "프로그램 종료\n";
			return 0;
		}
		else {
			cin.ignore();
		}
	}
}