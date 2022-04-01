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
	cout << "�ȳ��� ������";
	delete[] pAcctArray;
}
void ATMachine::displayMenu() {
	cout << "\n";
	cout << "----------------------\n";
	cout << "-    TUKOREA BANK    -\n";
	cout << "----------------------\n";
	cout << " 1. ���� ����\n";
	cout << " 2. ���� ��ȸ\n";
	cout << " 3. ���� �Ա�\n";
	cout << " 4. ���� ���\n";
	cout << " 6. ���� ����\n";
	cout << " 9. ���� ����\n";
}
void ATMachine::createAccount() {
	string name;

	cout << " ----- ���� -----\n";
	cout << " �̸� �Է�: ";
	cin >> name;
	cout << " ��ȣ �Է�: ";
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
	cout << "\n" << name << "�� " << id << " ���¹�ȣ�� ���������� �����Ǿ����ϴ�. �����մϴ�\n\n";
	nCurrentAccountNum++;
}
void ATMachine::checkMoney() {
	int id;
	string password;

	cout << " ----- ��ȸ -----\n";
	cout << " ���¹�ȣ �Է�: ";
	cin >> id;
	cout << " ��й�ȣ �Է�: ";
	cin >> password;

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].check(id, password); // ������ ��
		
		if (ox!=-1) {
			cout << " ���� �ܾ� : " << ox << "\n\n";
			return;
		}
	}

	cout << "���� Ȥ�� ��й�ȣ�� Ʋ���ϴ�.\n";
}
void ATMachine::closeAccount() {
	int id;
	string password;

	cout << " ----- ��ȸ -----\n";
	cout << " ���¹�ȣ �Է�: ";
	cin >> id;
	cout << " ��й�ȣ �Է�: ";
	cin >> password;

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].check(id, password); // ������ �� 
		if (ox == 0) {
			pAcctArray[i].close();
			cout << "\n " << id << " ���°� �����Ǿ����ϴ�. �����մϴ�.\n";
			return;
		}
		if (ox > 0) {
			cout << id << " ���¸� ������ �� �����ϴ�. �ܾ� : " << ox << endl;
			return;
		}
	}

	cout << "���� Ȥ�� ��й�ȣ�� Ʋ���ϴ�.\n";
}
void ATMachine::depositMoney() {
	int id, money;
	string password;

	cout << " ----- �Ա� -----\n";
	cout << " ���¹�ȣ �Է�: ";
	cin >> id;
	cout << " ��й�ȣ �Է�: ";
	cin >> password;
	cout << " �Աݾ�  �Է�: ";
	cin >> money;

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].deposit(id, password, money); // ������ �� 
		if (ox != -1) {
			nMachineBalance += ox;
			cout << " ���� �ܾ� : " << ox << endl;
			cout << " �ԱݿϷ�\n\n";
			return;
		}
	}

	cout << "���� Ȥ�� ��й�ȣ�� Ʋ���ϴ�.\n";
}
void ATMachine::widrawMoney() {
	int id, money;
	string password;

	cout << " ----- ��� -----\n";
	cout << " ���¹�ȣ �Է�: ";
	cin >> id;
	cout << " ��й�ȣ �Է�: ";
	cin >> password;
	cout << " ��ݾ�  �Է�: ";
	cin >> money;

	if (nMachineBalance - money < 0) {
		cout << "ATM��迡 �ܾ��� �����մϴ�. �˼��մϴ�.\n";
		return;
	}

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].widraw(id, password, money); // ������ �� 
		if (ox == -100) {
			cout << "������ ���� �ܾ��� �����մϴ�.\n";
			return;
		}

		if (ox != -1) {
			nMachineBalance -= money;
			cout << " ���� �ܾ� : " << ox << endl;
			cout << " ��ݿϷ�\n\n";
			return;
		}
	}

	cout << "���� Ȥ�� ��й�ȣ�� Ʋ���ϴ�.\n";
}