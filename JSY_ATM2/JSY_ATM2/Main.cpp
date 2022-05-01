#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ATMachine.h"
using namespace std;

int main() {
	int select; // 고객수 (100명), ATM 잔금 초기화, 관리자 암호
	ATMachine atm(100, 50000, "admin"); // ATMachine 객체 생성
	srand(time(NULL));

	while (1) {
		atm.displayMenu();
		cout << "메뉴를 선택하세요: ";
		cin >> select;
		cout << endl;

		switch (select) {
		case 1:                    // 계좌 개설
			atm.createAccount();
			break;
		case 2:                    // 계좌 조회
			atm.checkMoney();
			break;
		case 3:                    // 계좌 입금
			atm.depositMoney();
			break;
		case 4:                    // 계좌 출금
			atm.widrawMoney();
			break;
		case 5:                    // 계좌 이체
			atm.transfer();
			break;
		case 6:                    // 계좌 해지
			atm.closeAccount();
			break;
		case 7:                    // 고객 관리
			atm.managerMode();
			break;
		case 9:                    // 프로그램 종료
			return 0;
		default:
			cout << "번호 확인 후 다시 입력하세요." << endl;
			break;
		}
	}
}