#ifndef TICKETBOX_H
#define TICKETBOX_H

#define TICKETBOX_MANAGER_PWD "admin"

class TicketBox {
public:
	virtual Screen* selectMenu() { return NULL; }		// �󿵰� ���� �޴� (1��, 2��, 3��)
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
	void Initialize();	// ��ũ�� ��ü ����

	void Manage();	// ������ �޴�
};

#endif