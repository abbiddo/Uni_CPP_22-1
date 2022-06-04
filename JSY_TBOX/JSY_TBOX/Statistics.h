#ifndef STATISTCIS_H
#define STATISTCIS_H
#include "Screen.h"

class Statistics {
public:
	static int totalRevenue(Screen* pScreen);		// 총 결제 금액 계산
	static int totalSalesCount(Screen* pScreen);	// 총 티켓 판매 수 계산
};

#endif