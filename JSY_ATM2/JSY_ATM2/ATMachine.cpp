#include <iostream>
#include "ATMachine.h"
#include "Statistics.h"

using namespace std;

ATMachine::ATMachine(int size, int balance, string password) {      // ATM 초기화
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
void ATMachine::displayMenu() {         // ATM 화면
	cout << "\n";
	cout << "----------------------\n";
	cout << "-    TUKOREA BANK    -\n";
	cout << "----------------------\n";
	cout << " 1. 계좌 개설\n";
	cout << " 2. 계좌 조회\n";
	cout << " 3. 계좌 입금\n";
	cout << " 4. 계좌 출금\n";
	cout << " 5. 계좌 이체\n";
	cout << " 6. 계좌 해지\n";
	cout << " 9. 업무 종료\n";
}
void ATMachine::createAccount() {       // 계좌 개설
	string name, password;

	cout << " ----- 개설 -----\n";      // 정보 입력 받기
	cout << " 이름 입력: ";
	cin >> name;
	cout << " 암호 입력: ";
	cin >> password;

	int id = 0;                         // 계좌 번호 랜덤 생성 (1000 이하)
	id = rand() % 1001;
	if (id < BASE_ACCOUNT_ID) id += BASE_ACCOUNT_ID;      // 계좌 번호가 100 미만이면 +100

	for (int i = 0; i < nCurrentAccountNum; i++) {        // 계좌 번호 중복 검사
		if (pAcctArray[i].getAcctID() == id) {
			i = 0;
			id = rand() % 1001;
			if (id < BASE_ACCOUNT_ID) id += BASE_ACCOUNT_ID;
		}
	}

	pAcctArray[nCurrentAccountNum].create(id, 0, name, password);     // 계좌 생성
	cout << "\n" << name << "님 " << id << " 계좌번호가 정상적으로 개설되었습니다. 감사합니다\n\n";
	nCurrentAccountNum++;               // 계좌 개수 증가
}
void ATMachine::checkMoney() {          // 계좌 조회
	int id;
	string password;

	cout << " ----- 조회 -----\n";
	cout << " 계좌번호 입력: ";
	cin >> id;
	cout << " 비밀번호 입력: ";
	cin >> password;

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].check(id, password);       // 계좌 인증 (성공 시 잔액 / 실패 시 -1 반환)

		if (ox != -1) {
			cout << " 현재 잔액 : " << ox << "\n\n";
			return;
		}
	}

	cout << "계좌 혹은 비밀번호가 틀립니다.\n";          // 일치 하는 계좌가 존재하지 않을 때 출력
}
void ATMachine::closeAccount() {        // 계좌 해지
	int id;
	string password;

	cout << " ----- 조회 -----\n";
	cout << " 계좌번호 입력: ";
	cin >> id;
	cout << " 비밀번호 입력: ";
	cin >> password;

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].check(id, password);       // 계좌 인증 (성공 시 잔액 / 실패 시 -1 반환)
		if (ox == 0) {                                    // 잔액이 없을 시 해지
			pAcctArray[i].close();
			cout << "\n " << id << " 계좌가 해지되었습니다. 감사합니다.\n";
			return;
		}
		if (ox > 0) {                                     // 잔액이 있을 시 잔액 출력
			cout << id << " 계좌를 해지할 수 없습니다. 잔액 : " << ox << endl;
			return;
		}
	}

	cout << "계좌 혹은 비밀번호가 틀립니다.\n";           // 일치 하는 계좌가 존재하지 않을 때 출력
}
void ATMachine::depositMoney() {        // 계좌 입금
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
		int ox = pAcctArray[i].deposit(id, password, money);   // 계좌 인증 후 입금 (성공 시 잔액 / 실패 시 -1 반환)
		if (ox != -1) {
			nMachineBalance += ox;
			cout << " 현재 잔액 : " << ox << endl;
			cout << " 입금완료\n\n";
			return;
		}
	}

	cout << "계좌 혹은 비밀번호가 틀립니다.\n";           // 일치 하는 계좌가 존재하지 않을 때 출력
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
		int ox = pAcctArray[i].widraw(id, password, money); // 계좌 인증 후 출금 (성공 시 잔액 / 계좌 잔액이 부족할 시 -100 / 실패 시 -1 반환)
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

	cout << "계좌 혹은 비밀번호가 틀립니다.\n";           // 일치 하는 계좌가 존재하지 않을 때 출력
}
void ATMachine::transfer() {
	int id, money, id2;
	string password;

	cout << " ----- 이체 -----\n";
	cout << " 계좌번호 입력: ";
	cin >> id;
	cout << " 비밀번호 입력: ";
	cin >> password;
	cout << " 이체계좌 입력: ";
	cin >> id2;
	cout << " 이체금액 입력: ";
	cin >> money;

	for (int i = 0; i < nCurrentAccountNum; i++) {
		int ox = pAcctArray[i].widraw(id, password, money); // 계좌 인증 후 출금 (성공 시 잔액 / 계좌 잔액이 부족할 시 -100 / 실패 시 -1 반환)
		if (ox == -100) {
			cout << "고객님의 계좌 잔액이 부족합니다.\n";
			return;
		}

		if (ox != -1) {
			for (int j = 0; j < nCurrentAccountNum; j++) {
				int ox2 = pAcctArray[j].deposit(id2, money);
				if (ox2 != -1) {
					cout << " 현재 잔액 : " << ox << endl;
					cout << " 이체완료\n\n";
					return;
				}
			}
			cout << "이체 계좌를 확인해주세요\n";
			pAcctArray[i].deposit(id, password, money);           // 이체 계좌를 찾지 못하면 다시 본 계좌에 입금
			return;
		}
	}

	cout << "계좌 혹은 비밀번호가 틀립니다.\n";
}

bool ATMachine::isManager(string password) {
	return (strManagerPassword == password);
}
void ATMachine::displayReport() {   // ATM잔고, 고객 잔고 총액, 평균, 최고 출력
	cout << "\n";
	cout << " ---------------------\n";
	cout << " ATM  현재 잔고:        " << nMachineBalance << "원" << endl;
	cout << " 고객 잔고 총액:        " << Statistics::sum(pAcctArray, nCurrentAccountNum) << "원(총" << nCurrentAccountNum << "명)" << endl;
	cout << " 고객 잔고 평균:        " << Statistics::average(pAcctArray, nCurrentAccountNum) << "원" << endl;
	cout << " 고객 잔고 최고:        " << Statistics::max(pAcctArray, nCurrentAccountNum) << "원" << endl;
	cout << " ---------------------\n";
	cout << " -  고객 계좌 목록   -\n";
	cout << " ---------------------\n";
	Statistics::sort(pAcctArray, nCurrentAccountNum);  // 고객 계좌 내림차순으로 출력
}

void ATMachine::managerMode() {
	string passwd;

	cout << " ----- 관리 -----\n";
	cout << " 관리자 비밀번호 입력: ";
	cin >> passwd;

	if (!isManager(passwd)) {               // 관리자 비밀번호 일치하지 않으면 메뉴 종료
		cout << " 비밀번호가 틀립니다.\n";
		return;
	}

	cout << " 관리자입니다.\n";
	displayReport();                        // 관리자 비밀번호 일치하면 displayReport 함수 실행
}