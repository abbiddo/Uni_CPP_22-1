#include <iostream>
#include "ATMachine.h"
#include "Statistics.h"

using namespace std;

ATMachine::ATMachine(int size, int balance, string password) {      // ATM �ʱ�ȭ
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
void ATMachine::displayMenu() {         // ATM ȭ��
	cout << "\n";
	cout << "----------------------\n";
	cout << "-    TUKOREA BANK    -\n";
	cout << "----------------------\n";
	cout << " 1. ���� ����\n";
	cout << " 2. ���� ��ȸ\n";
	cout << " 3. ���� �Ա�\n";
	cout << " 4. ���� ���\n";
	cout << " 5. ���� ��ü\n";
	cout << " 6. ���� ����\n";
	cout << " 9. ���� ����\n";
}
void ATMachine::createAccount() {       // ���� ����
	string name, password;

	cout << " ----- ���� -----\n";      // ���� �Է� �ޱ�
	cout << " �̸� �Է�: ";
	cin >> name;
	cout << " ��ȣ �Է�: ";
	cin >> password;

	int id = 0;                         // ���� ��ȣ ���� ���� (1000 ����)
	id = rand() % 1001;
	if (id < BASE_ACCOUNT_ID) id += BASE_ACCOUNT_ID;      // ���� ��ȣ�� 100 �̸��̸� +100

	for (int i = 0; i < nCurrentAccountNum; i++) {        // ���� ��ȣ �ߺ� �˻�
		if (pAcctArray[i].getAcctID() == id) {
			i = 0;
			id = rand() % 1001;
			if (id < BASE_ACCOUNT_ID) id += BASE_ACCOUNT_ID;
		}
	}

	pAcctArray[nCurrentAccountNum].create(id, 0, name, password);     // ���� ����
	cout << "\n" << name << "�� " << id << " ���¹�ȣ�� ���������� �����Ǿ����ϴ�. �����մϴ�\n\n";
	nCurrentAccountNum++;               // ���� ���� ����
}
void ATMachine::checkMoney() {          // ���� ��ȸ
	int id;
	string password;

	cout << " ----- ��ȸ -----\n";
	cout << " ���¹�ȣ �Է�: ";
	cin >> id;
	cout << " ��й�ȣ �Է�: ";
	cin >> password;

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].check(id, password);       // ���� ���� (���� �� �ܾ� / ���� �� -1 ��ȯ)

		if (ox != -1) {
			cout << " ���� �ܾ� : " << ox << "\n\n";
			return;
		}
	}

	cout << "���� Ȥ�� ��й�ȣ�� Ʋ���ϴ�.\n";          // ��ġ �ϴ� ���°� �������� ���� �� ���
}
void ATMachine::closeAccount() {        // ���� ����
	int id;
	string password;

	cout << " ----- ��ȸ -----\n";
	cout << " ���¹�ȣ �Է�: ";
	cin >> id;
	cout << " ��й�ȣ �Է�: ";
	cin >> password;

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].check(id, password);       // ���� ���� (���� �� �ܾ� / ���� �� -1 ��ȯ)
		if (ox == 0) {                                    // �ܾ��� ���� �� ����
			pAcctArray[i].close();
			cout << "\n " << id << " ���°� �����Ǿ����ϴ�. �����մϴ�.\n";
			return;
		}
		if (ox > 0) {                                     // �ܾ��� ���� �� �ܾ� ���
			cout << id << " ���¸� ������ �� �����ϴ�. �ܾ� : " << ox << endl;
			return;
		}
	}

	cout << "���� Ȥ�� ��й�ȣ�� Ʋ���ϴ�.\n";           // ��ġ �ϴ� ���°� �������� ���� �� ���
}
void ATMachine::depositMoney() {        // ���� �Ա�
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
		int ox = pAcctArray[i].deposit(id, password, money);   // ���� ���� �� �Ա� (���� �� �ܾ� / ���� �� -1 ��ȯ)
		if (ox != -1) {
			nMachineBalance += ox;
			cout << " ���� �ܾ� : " << ox << endl;
			cout << " �ԱݿϷ�\n\n";
			return;
		}
	}

	cout << "���� Ȥ�� ��й�ȣ�� Ʋ���ϴ�.\n";           // ��ġ �ϴ� ���°� �������� ���� �� ���
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
		int ox = pAcctArray[i].widraw(id, password, money); // ���� ���� �� ��� (���� �� �ܾ� / ���� �ܾ��� ������ �� -100 / ���� �� -1 ��ȯ)
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

	cout << "���� Ȥ�� ��й�ȣ�� Ʋ���ϴ�.\n";           // ��ġ �ϴ� ���°� �������� ���� �� ���
}
void ATMachine::transfer() {
	int id, money, id2;
	string password;

	cout << " ----- ��ü -----\n";
	cout << " ���¹�ȣ �Է�: ";
	cin >> id;
	cout << " ��й�ȣ �Է�: ";
	cin >> password;
	cout << " ��ü���� �Է�: ";
	cin >> id2;
	cout << " ��ü�ݾ� �Է�: ";
	cin >> money;

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].widraw(id, password, money); // ���� ���� �� ��� (���� �� �ܾ� / ���� �ܾ��� ������ �� -100 / ���� �� -1 ��ȯ)
		if (ox == -100) {
			cout << "������ ���� �ܾ��� �����մϴ�.\n";
			return;
		}

		if (ox != -1) {
			for (int j = 0; j < nCurrentAccountNum; j++) {
				int ox2 = pAcctArray[j].deposit(id2, money);
				if (ox2 != -1) {
					cout << " ���� �ܾ� : " << ox << endl;
					cout << " ��ü�Ϸ�\n\n";
					return;
				}
			}
			cout << "��ü ���¸� Ȯ�����ּ���\n";
			pAcctArray[i].deposit(id, password, money);           // ��ü ���¸� ã�� ���ϸ� �ٽ� �� ���¿� �Ա�
			return;
		}
	}

	cout << "���� Ȥ�� ��й�ȣ�� Ʋ���ϴ�.\n";
}

bool ATMachine::isManager(string password) {
	return (strManagerPassword == password);
}
void ATMachine::displayReport() {   // ATM�ܰ�, �� �ܰ� �Ѿ�, ���, �ְ� ���
	cout << "\n";
	cout << " ---------------------\n";
	cout << " ATM  ���� �ܰ�:        " << nMachineBalance << "��" << endl;
	cout << " �� �ܰ� �Ѿ�:        " << Statistics::sum(pAcctArray, nCurrentAccountNum) << "��(��" << nCurrentAccountNum << "��)" << endl;
	cout << " �� �ܰ� ���:        " << Statistics::average(pAcctArray, nCurrentAccountNum) << "��" << endl;
	cout << " �� �ܰ� �ְ�:        " << Statistics::max(pAcctArray, nCurrentAccountNum) << "��" << endl;
	cout << " ---------------------\n";
	cout << " -  �� ���� ���   -\n";
	cout << " ---------------------\n";
	Statistics::sort(pAcctArray, nCurrentAccountNum);  // �� ���� ������������ ���
}

void ATMachine::managerMode() {
	string passwd;

	cout << " ----- ���� -----\n";
	cout << " ������ ��й�ȣ �Է�: ";
	cin >> passwd;

	if (!isManager(passwd)) {               // ������ ��й�ȣ ��ġ���� ������ �޴� ����
		cout << " ��й�ȣ�� Ʋ���ϴ�.\n";
		return;
	}

	cout << " �������Դϴ�.\n";
	displayReport();                        // ������ ��й�ȣ ��ġ�ϸ� displayReport �Լ� ����
}