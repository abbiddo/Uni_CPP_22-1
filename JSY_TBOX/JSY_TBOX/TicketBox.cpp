#include <iostream>
#include "Screen.h"
#include "TicketBox.h"
#include "Statistics.h"
using namespace std;

TUKoreaTBox::TUKoreaTBox() {
	pEuropeScreen = NULL;
	pAsiaScreen = NULL;
	pPremiumScreen = NULL;
}
TUKoreaTBox::~TUKoreaTBox() {
	delete pEuropeScreen;
	delete pAsiaScreen;
	delete pPremiumScreen;
}
Screen* TUKoreaTBox::selectMenu() {
	cout << "\n ----------------------\n";
	cout << "    �󿵰� ���� �޴�\n";
	cout << " ----------------------\n";

	cout << " 1.   ����   ��ȭ 1��\n";
	cout << " 2.  �ƽþ�  ��ȭ 2��\n";
	cout << " 3. �����̾� ��ȭ 3��\n";
	cout << " 9.   ���   ����\n\n";

	cout << " ���� (1~3, 9) �� �� ���� : ";

	int n;
	cin >> n;

	switch (n) {
	case 1:
		return pEuropeScreen;
	case 2:
		return pAsiaScreen;
	case 3:
		return pPremiumScreen;
	case 9:
		Manage();
		return NULL;
	default:
		return NULL;
	}
}
void TUKoreaTBox::Initialize() {	// ��ũ�� ��ü ����
	// Screen(��ȭ����, Ƽ�ϰ���, �¼�(nRowMax), �¼�(nColMax))
	pEuropeScreen = new EuropeScreen("������� ����", 10000, 10, 10);
	pAsiaScreen = new AsiaScreen("���۵� ����", 12000, 10, 10);
	pPremiumScreen = new PremiumScreen("�ظ�����", 30000, 6, 6);
}

void TUKoreaTBox::Manage() {
	string passwd;
	cout << "\n ----------------------\n";
	cout << "      ������ �޴�\n";
	cout << " ----------------------\n";

	cout << "������ ��й�ȣ �Է� : ";
	cin >> passwd;
	cout << endl;

	if (passwd != TICKETBOX_MANAGER_PWD) {
		cout << "������ ��.\n";
		return;
	}
	 
	cout << " 1. ���� ��ȭ �󿵰� ���� �ݾ� : " << Statistics::totalRevenue(pEuropeScreen) << endl;
	cout << " 2. �ƽþ� ��ȭ �󿵰� ���� �ݾ� : " << Statistics::totalRevenue(pAsiaScreen) << endl;
	cout << " 3. �����̾� ��ȭ �󿵰� ���� �ݾ� : " << Statistics::totalRevenue(pPremiumScreen) << endl;
	
	cout << " 4. ��ü Ƽ�� �Ǹŷ� : " << Statistics::totalSalesCount(pEuropeScreen) 
													+ Statistics::totalSalesCount(pAsiaScreen) 
													+ Statistics::totalSalesCount(pPremiumScreen) << endl;
}