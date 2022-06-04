#ifndef TICKETBOX_H
#define TICKETBOX_H

#define TICKETBOX_MANAGER_PWD "admin"

class TicketBox {
public:
	virtual Screen* selectMenu() { return NULL; }		// 상영관 선택 메뉴 (1관, 2관, 3관)
	void Initialize(){}
};
class TUKoreaTBox :public TicketBox {
	EuropeScreen* pEuropeScreen;
	AsiaScreen* pAsiaScreen;
	PremiumScreen* pPremiumScreen;
public:
	TUKoreaTBox();
	~TUKoreaTBox();
	Screen* selectMenu();	
	void Initialize();	// 스크린 객체 생성

	void Manage();	// 관리자 메뉴
};

#endif