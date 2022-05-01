#include <iostream>
#include "Statistics.h"
using namespace std;

int Statistics::sum(Account* pArray, int size) { // 합 반환
	int result = 0;
	for (int i = 0; i < size; i++) 
		result += pArray[i].getBalance();
	return result;
}
int Statistics::average(Account* pArray, int size) { // 합/사이즈 => 평균 리턴
	int result = 0;
	for (int i = 0; i < size; i++)
		result += pArray[i].getBalance();
	return result/size;
}
int Statistics::max(Account* pArray, int size) { // 최고 잔액 반환
	int result = pArray[0].getBalance();
	for (int i = 1; i < size; i++)
		if (result < pArray[i].getBalance()) result = pArray[i].getBalance();
	return result;
}
void Statistics::sort(Account* pArray, int size) {
	Account temp;
	for (int i = 0; i < size-1; i++) {           // 버블 정렬 
		for (int j = 0; j < size - i - 1; j++) {
			if (pArray[j].getBalance() < pArray[j + 1].getBalance()) {
				temp = pArray[j];
				pArray[j] = pArray[j + 1];
				pArray[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < size; i++)
		cout << " " << i + 1 << ". " << pArray[i].getAccountName() << "        " << pArray[i].getAcctID() << "       " << pArray[i].getBalance()<<"원\n";
}