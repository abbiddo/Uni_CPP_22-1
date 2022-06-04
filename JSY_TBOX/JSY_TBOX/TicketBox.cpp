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
	cout << "    상영관 메인 메뉴\n";
	cout << " ----------------------\n";

	cout << " 1.   유럽   영화 1관\n";
	cout << " 2.  아시아  영화 2관\n";
	cout << " 3. 프리미엄 영화 3관\n";
	cout << " 9.   통계   관리\n\n";

	cout << " 선택 (1~3, 9) 그 외 종료 : ";

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
void TUKoreaTBox::Initialize() {	// 스크린 객체 생성
	// Screen(영화제목, 티켓가격, 좌석(nRowMax), 좌석(nColMax))
	pEuropeScreen = new EuropeScreen("오베라는 남자", 10000, 10, 10);
	pAsiaScreen = new AsiaScreen("조작된 도시", 12000, 10, 10);
	pPremiumScreen = new PremiumScreen("해리포터", 30000, 6, 6);
}

void TUKoreaTBox::Manage() {
	string passwd;
	cout << "\n ----------------------\n";
	cout << "      관리자 메뉴\n";
	cout << " ----------------------\n";

	cout << "관리자 비밀번호 입력 : ";
	cin >> passwd;
	cout << endl;

	if (passwd != TICKETBOX_MANAGER_PWD) {
		cout << "누구냐 넌.\n";
		return;
	}
	 
	cout << " 1. 유렵 영화 상영관 결제 금액 : " << Statistics::totalRevenue(pEuropeScreen) << endl;
	cout << " 2. 아시아 영화 상영관 결제 금액 : " << Statistics::totalRevenue(pAsiaScreen) << endl;
	cout << " 3. 프리미엄 영화 상영관 결제 금액 : " << Statistics::totalRevenue(pPremiumScreen) << endl;
	
	cout << " 4. 전체 티켓 판매량 : " << Statistics::totalSalesCount(pEuropeScreen) 
													+ Statistics::totalSalesCount(pAsiaScreen) 
													+ Statistics::totalSalesCount(pPremiumScreen) << endl;
}