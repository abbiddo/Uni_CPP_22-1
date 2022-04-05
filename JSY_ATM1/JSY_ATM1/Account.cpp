#include "Account.h"
using namespace std;

Account::Account() {
	nID = -1;
	nBalance = 0;
}
void Account::create(int id, int money, string name, string password) {
	nID = id;
	nBalance = money;
	strAccountName = name;
	strPassword = password;
}
void Account::close() {
	nID = -1;
	nBalance = 0;
	strAccountName = "";
	strPassword = "admin";
}
int Account::check(int id, string password) {
	if (authenticate(id, password) == AUTHENTIFICATION_SUCCESS) return nBalance;
	return AUTHENTIFICATION_FAIL;
}
inline bool Account::authenticate(int id, string password) {
	return ((id == nID) && (password == strPassword));
}
int Account::deposit(int id, string password, int money) {
	if (authenticate(id, password) ==  AUTHENTIFICATION_SUCCESS) {
		nBalance += money;
		return nBalance;
	}
	return AUTHENTIFICATION_FAIL;
}
int Account::widraw(int id, string password, int money) {
	if (authenticate(id, password) == AUTHENTIFICATION_SUCCESS) {
		if (nBalance - money < 0) return -100;
		nBalance -= money;
		return nBalance;
	}
	return AUTHENTIFICATION_FAIL;
}