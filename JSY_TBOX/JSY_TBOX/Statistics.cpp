#include <iostream>
#include "Statistics.h";

int Statistics::totalRevenue(Screen* pScreen) {
	Ticket** seat = pScreen->getTicketArray();
	int revenue = 0;

	for (int i = 0; i < pScreen->getRowMax(); i++) 
		for (int j = 0; j < pScreen->getColMax(); j++) 
			if (seat[i][j].getCheck() == '$') revenue += seat[i][j].getPayAmount();
	
	return revenue;
}
int Statistics::totalSalesCount(Screen* pScreen) {
	Ticket** seat = pScreen->getTicketArray();
	int cnt = 0;

	for (int i = 0; i < pScreen->getRowMax(); i++)
		for (int j = 0; j < pScreen->getColMax(); j++)
			if (seat[i][j].getCheck() == '$') cnt++;

	return cnt;
}