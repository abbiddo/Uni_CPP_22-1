#include <iostream>
#include <ctime>
#include "ATMachine.h"

using namespace std;

ATMachine::ATMachine(int size, int balance, string password) {
	nMaxAccountNum = size;
	nMachineBalance = balance;
	nCurrentAccountNum = 0;
	strManagerPassword = password;
	pAcctArray = new Account[nMaxAccountNum];
}
ATMachine::~ATMachine() {
	cout << "안녕히 가세요";
	delete[] pAcctArray;
}
void ATMachine::displayMenu() {
	cout << "\n";
	cout << "----------------------\n";
	cout << "-    TUKOREA BANK    -\n";
	cout << "----------------------\n";
	cout << " 1. 계좌 개설\n";
	cout << " 2. 계좌 조회\n";
	cout << " 3. 계좌 입금\n";
	cout << " 4. 계좌 출금\n";
	cout << " 6. 계좌 해지\n";
	cout << " 9. 업무 종료\n";
}
void ATMachine::createAccount() {
	string name;

	cout << " ----- 개설 -----\n";
	cout << " 이름 입력: ";
	cin >> name;
	cout << " 암호 입력: ";
	cin >> strManagerPassword;

	int id = 0;
	srand(time(NULL));
	id = rand() % 1001;

	if (id < BASE_ACCOUNT_ID) id += BASE_ACCOUNT_ID;
	for (int i = 0; i < nCurrentAccountNum; i++) {
		if (pAcctArray[i].getAcctID() == id) {
			i = -1;
			srand(time(NULL));
			id = rand() % 1001;
			if (id < 100) id += 100;
		}
	}
	
	pAcctArray[nCurrentAccountNum].create(id, 0, name, strManagerPassword);
	cout << "\n" << name << "님 " << id << " 계좌번호가 정상적으로 개설되었습니다. 감사합니다\n\n";
	nCurrentAccountNum++;
}
void ATMachine::checkMoney() {
	int id;
	string password;

	cout << " ----- 조회 -----\n";
	cout << " 계좌번호 입력: ";
	cin >> id;
	cout << " 비밀번호 입력: ";
	cin >> password;

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].check(id, password); // 변수명 좀
		
		if (ox!=-1) {
			cout << " 현재 잔액 : " << ox << "\n\n";
			return;
		}
	}

	cout << "계좌 혹은 비밀번호가 틀립니다.\n";
}
void ATMachine::closeAccount() {
	int id;
	string password;

	cout << " ----- 조회 -----\n";
	cout << " 계좌번호 입력: ";
	cin >> id;
	cout << " 비밀번호 입력: ";
	cin >> password;

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].check(id, password); // 변수명 좀 
		if (ox == 0) {
			pAcctArray[i].close();
			cout << "\n " << id << " 계좌가 해지되었습니다. 감사합니다.\n";
			return;
		}
		if (ox > 0) {
			cout << id << " 계좌를 해지할 수 없습니다. 잔액 : " << ox << endl;
			return;
		}
	}

	cout << "계좌 혹은 비밀번호가 틀립니다.\n";
}
void ATMachine::depositMoney() {
	int id, money;
	string password;

	cout << " ----- 입금 -----\n";
	cout << " 계좌번호 입력: ";
	cin >> id;
	cout << " 비밀번호 입력: ";
	cin >> password;
	cout << " 입금액  입력: ";
	cin >> money;

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].deposit(id, password, money); // 변수명 좀 
		if (ox != -1) {
			nMachineBalance += ox;
			cout << " 현재 잔액 : " << ox << endl;
			cout << " 입금완료\n\n";
			return;
		}
	}

	cout << "계좌 혹은 비밀번호가 틀립니다.\n";
}
void ATMachine::widrawMoney() {
	int id, money;
	string password;

	cout << " ----- 출금 -----\n";
	cout << " 계좌번호 입력: ";
	cin >> id;
	cout << " 비밀번호 입력: ";
	cin >> password;
	cout << " 출금액  입력: ";
	cin >> money;

	if (nMachineBalance - money < 0) {
		cout << "ATM기계에 잔액이 부족합니다. 죄송합니다.\n";
		return;
	}

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].widraw(id, password, money); // 변수명 좀 
		if (ox == -100) {
			cout << "고객님의 계좌 잔액이 부족합니다.\n";
			return;
		}

		if (ox != -1) {
			nMachineBalance -= money;
			cout << " 현재 잔액 : " << ox << endl;
			cout << " 출금완료\n\n";
			return;
		}
	}

	cout << "계좌 혹은 비밀번호가 틀립니다.\n";
}