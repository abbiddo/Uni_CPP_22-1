#include "Account.h"
using namespace std;

Account::Account() {        // 계좌 초기화
	nID = -1;
	nBalance = 0;
}
void Account::create(int id, int money, string name, string password) {     // 계좌 개설
	nID = id;
	nBalance = money;
	strAccountName = name;
	strPassword = password;
}
void Account::close() {     // 계좌 해지 (사용자 정보 삭제)
	strAccountName = "";
	strPassword = "admin";
}
int Account::check(int id, string password) {                    // 계좌 조회 (성공 시 잔액 / 실패 시 -1 반환) 
	if (authenticate(id, password) == AUTHENTIFICATION_SUCCESS) return nBalance;
	return AUTHENTIFICATION_FAIL;
}
inline bool Account::authenticate(int id, string password) {     // 계좌 인증 (true/false)
	return ((id == nID) && (password == strPassword));
}
int Account::deposit(int id, string password, int money) {       // 계좌 입금
	if (authenticate(id, password) == AUTHENTIFICATION_SUCCESS) {
		nBalance += money;
		return nBalance;
	}
	return AUTHENTIFICATION_FAIL;
}
int Account::widraw(int id, string password, int money) {        // 계좌 출금
	if (authenticate(id, password) == AUTHENTIFICATION_SUCCESS) {
		if (nBalance - money < 0) return -100;        // 잔액보다 큰 금액을 출금하려고 하면 -100 반환
		nBalance -= money;
		return nBalance;                              // 출금 가능한 금액이면 출금 후 잔액 반환
	}
	return AUTHENTIFICATION_FAIL;
}
int Account::deposit(int id, int money) {             // 계좌 이체
	if (id == nID) {                                  // 이체할 계좌가 맞으면 입금 후 잔액 반환
		nBalance += money;
		return nBalance;
	}
	return AUTHENTIFICATION_FAIL;
}