#include <iostream>
#include "Pay.h"
using namespace std;

int CardPay::charge(int amount) {
	return amount + amount * interest;
}
int BankTransfer::charge(int amount) {
	return amount + amount * interest;
}
int MobilePay::charge(int amount) {
	return amount + amount * interest;
}