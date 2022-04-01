#ifndef ATMACHINE_H
#define ATMACHINE_H
#include <string>
#include "Account.h"
using std::string;

#define NEGATIVE_ATM_BALANCE -10

class ATMachine {
private:
	Account* pAcctArray;
	int nMachineBalance;
	int nMaxAccountNum;
	int nCurrentAccountNum;
	string strManagerPassword;

public:
	ATMachine(int size, int balance, string password);
	~ATMachine();

	void displayMenu();
	void createAccount();
	void closeAccount();
	void checkMoney();

	void depositMoney();
	void widrawMoney();
};

#endif