#include "Account.h"
using namespace std;

Account::Account() {        // ���� �ʱ�ȭ
	nID = -1;
	nBalance = 0;
}
void Account::create(int id, int money, string name, string password) {     // ���� ����
	nID = id;
	nBalance = money;
	strAccountName = name;
	strPassword = password;
}
void Account::close() {     // ���� ���� (����� ���� ����)
	strAccountName = "";
	strPassword = "admin";
}
int Account::check(int id, string password) {                    // ���� ��ȸ (���� �� �ܾ� / ���� �� -1 ��ȯ) 
	if (authenticate(id, password) == AUTHENTIFICATION_SUCCESS) return nBalance;
	return AUTHENTIFICATION_FAIL;
}
inline bool Account::authenticate(int id, string password) {     // ���� ���� (true/false)
	return ((id == nID) && (password == strPassword));
}
int Account::deposit(int id, string password, int money) {       // ���� �Ա�
	if (authenticate(id, password) == AUTHENTIFICATION_SUCCESS) {
		nBalance += money;
		return nBalance;
	}
	return AUTHENTIFICATION_FAIL;
}
int Account::widraw(int id, string password, int money) {        // ���� ���
	if (authenticate(id, password) == AUTHENTIFICATION_SUCCESS) {
		if (nBalance - money < 0) return -100;        // �ܾ׺��� ū �ݾ��� ����Ϸ��� �ϸ� -100 ��ȯ
		nBalance -= money;
		return nBalance;                              // ��� ������ �ݾ��̸� ��� �� �ܾ� ��ȯ
	}
	return AUTHENTIFICATION_FAIL;
}
int Account::deposit(int id, int money) {             // ���� ��ü
	if (id == nID) {                                  // ��ü�� ���°� ������ �Ա� �� �ܾ� ��ȯ
		nBalance += money;
		return nBalance;
	}
	return AUTHENTIFICATION_FAIL;
}