#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ATMachine.h"
using namespace std;

int main() {
	int select; // ���� (100��), ATM �ܱ� �ʱ�ȭ, ������ ��ȣ
	ATMachine atm(100, 50000, "admin"); // ATMachine ��ü ����
	srand(time(NULL));

	while (1) {
		atm.displayMenu();
		cout << "�޴��� �����ϼ���: ";
		cin >> select;
		cout << endl;

		switch (select) {
		case 1:                    // ���� ����
			atm.createAccount();
			break;
		case 2:                    // ���� ��ȸ
			atm.checkMoney();
			break;
		case 3:                    // ���� �Ա�
			atm.depositMoney();
			break;
		case 4:                    // ���� ���
			atm.widrawMoney();
			break;
		case 5:                    // ���� ��ü
			atm.transfer();
			break;
		case 6:                    // ���� ����
			atm.closeAccount();
			break;
		case 7:                    // �� ����
			atm.managerMode();
			break;
		case 9:                    // ���α׷� ����
			return 0;
		default:
			cout << "��ȣ Ȯ�� �� �ٽ� �Է��ϼ���." << endl;
			break;
		}
	}
}