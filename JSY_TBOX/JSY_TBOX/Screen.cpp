#include <iostream>
#include <string>
#include "Screen.h"
#include "Pay.h"
using namespace std;

Screen::Screen(string name, int price, int row, int col) {
	strMovieName = name;
	nRowMax = row;
	nColMax = col;
	nTicketPrice = price;
	nCurrentReservedId = 100;

	pSeatArray = new Ticket * [nRowMax];
	for (int r = 0; r < nRowMax; r++) pSeatArray[r] = new Ticket[nColMax];
	for (int i = 0; i < nRowMax; i++)
		for (int j = 0; j < nColMax; j++) pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);
}
Screen::~Screen() {
	for (int r = 0; r < nRowMax; r++) delete[] pSeatArray[r];
	delete[] pSeatArray;
}
void Screen::showSeatMap() {
	cout << "\n        [ �¼� ���� ��Ȳ ]" << endl;
	cout << "        ";
	for (int i = 0; i < nColMax; i++) cout << "[" << i + 1 << "] ";
	cout << "\n";

	for (int i = 0; i < nRowMax; i++) {
		cout << "[" << i + 1 << "]\t";
		for (int j = 0; j < nColMax; j++)
			cout << "[" << pSeatArray[i][j].getCheck() << "] ";
		cout << "\n";
	}
}
void Screen::showMovieMenu() {
	cout << "\n------------------------------------\n";
	cout << "       ��ȭ �޴� - " << strMovieName << endl;
	cout << "------------------------------------\n";

	cout << " 1. �� ��ȭ ����\n";
	cout << " 2. �¼� ���� ��Ȳ\n";
	cout << " 3. �¼� ���� �ϱ�\n";
	cout << " 4. �¼� ���� ���\n";
	cout << " 5. �¼� ���� ����\n";
	cout << " 7. ���� �޴� �̵�\n\n";
}

void EuropeScreen::showMovieInfo() {
	cout << "\n------------------------------------\n";
	cout << "       [ " << strMovieName << " ]\n";
	cout << "------------------------------------\n";

	cout << "  ��ȭ�� : ���� ��ȭ 1��\n";
	cout << "  ���ΰ� : ���� �󽺰���, �ʸ� ����\n";
	cout << "  �ٰŸ� : ������ ���� ������ǰ ���Կ��� ...\n";
	cout << "  ���� " << nTicketPrice << endl;
}
void AsiaScreen::showMovieInfo() {
	cout << "\n------------------------------------\n";
	cout << "       [ " << strMovieName << " ]\n";
	cout << "------------------------------------\n";

	cout << "  ��ȭ�� : �ƽþ� ��ȭ 2��\n";
	cout << "  ���ΰ� : ��â��, ������, ����ȫ\n";
	cout << "  �ٰŸ� : �ָӴ� ������ �˳����� �ʾ� ...\n";
	cout << "  ���� " << nTicketPrice << endl;
}
void PremiumScreen::showMovieInfo() {
	cout << "\n------------------------------------\n";
	cout << "       [ " << strMovieName << " ]\n";
	cout << "------------------------------------\n";

	cout << "  ��ȭ�� : �����̾� ��ȭ 3��\n";
	cout << "  ���ΰ� : �ٴϿ� ����Ŭ����, ���� �ӽ� \n";
	cout << "  �ٰŸ� : �ظ��� ȣ�׿�Ʈ �����б� ���� ������ ...\n";
	cout << "  ���� " << nTicketPrice << endl;
}

void Screen::reserveTicket() {
	int r, c;
	cout << "\n  [ �¼� ���� ]\n";
	cout << "�¼� �� ��ȣ �Է�(1 - " << nRowMax << ") : ";
	cin >> r;
	cout << "�¼� �� ��ȣ �Է�(1 - " << nColMax << ") : ";
	cin >> c;

	if (pSeatArray[r - 1][c - 1].getCheck() == SEAT_RESERVED_MARK) {
		cout << "�̹� ����� �¼��Դϴ�.\n";
		return;
	}
	if (pSeatArray[r - 1][c - 1].getCheck() == SEAT_COMPLETION_MARK) {
		cout << "�̹� ���ŵ� �¼��Դϴ�.\n";
		return;
	}
	cout << "��[" << r << "] ��[" << c << "] " << nCurrentReservedId << " ���� ��ȣ�� �����Ǿ����ϴ�.\n";

	pSeatArray[r - 1][c - 1].setCheck(SEAT_RESERVED_MARK);
	pSeatArray[r - 1][c - 1].setSeat(r, c);
	pSeatArray[r - 1][c - 1].setReservedID(nCurrentReservedId);
	nCurrentReservedId++;
}

Ticket* Screen::checkReservedID(int id) {
	for (int i = 0; i < nRowMax; i++)
		for (int j = 0; j < nColMax; j++)
			if (pSeatArray[i][j].getReservedID() == id)
				return &pSeatArray[i][j];
	return NULL;
}
void Screen::cancelReservation() {
	int n;
	cout << "\n  [ �¼� ��� ]\n";
	cout << "���� ��ȣ �Է� : ";
	cin >> n;

	Ticket* seat = checkReservedID(n);
	if (!seat) {
		cout << "���� ��ȣ�� Ȯ�����ּ���.\n";
		return;
	}

	if (seat->getCheck() == SEAT_COMPLETION_MARK) {
		cout << "�̹� ������ �Ϸ�� �¼��Դϴ�.\n";
		return;
	}

	seat->setSeat(0, 0);
	seat->setReservedID(0);
	seat->setCheck(SEAT_EMPTY_MARK);
	cout << n << " ���� ��ȣ�� ��� ó���Ǿ����ϴ�.\n";
}

void Screen::Payment() {
	int n, m;
	cout << "\n  [ ���� �¼� ���� ]\n";
	cout << "���� ��ȣ �Է� : ";
	cin >> n;

	Ticket* seat = checkReservedID(n);
	if (!seat) {
		cout << "���� ��ȣ�� Ȯ�����ּ���.\n";
		return;
	}

	if (seat->getCheck() == SEAT_COMPLETION_MARK) {
		cout << "�̹� ������ �Ϸ�� �¼��Դϴ�.\n";
		return;
	}

	cout << "\n------------------------------------\n";
	cout << "       ���� ��� ����\n";
	cout << "------------------------------------\n";

	cout << " 1. ����� ����\n";
	cout << " 2. ���� ��ü ����\n";
	cout << " 3. ī�� ����\n";

	cout << "\n ���� ��� (1~3): "; cin >> m;
	seat->setPayMethod(m);

	string number, name;
	int pay;

	if (m == MOBILE_PHONE_PAYMENT) {
		MobilePay mpay(MOBILE_PHONE_INTEREST_RATE);
		cout << "        [ ����� ���� ]\n";
		cout << "�ڵ��� ��ȣ �Է�(11�ڸ���) : "; cin >> number;
		cout << "�̸� : "; cin >> name;

		pay = mpay.charge(nTicketPrice);
		cout << "����� ������ �Ϸ�Ǿ����ϴ�. : ";
	}
	else if (m == BANK_TRANSFER_PAYMENT) {
		BankTransfer bpay(BANK_TRANSFER_INTEREST_RATE);
		cout << "        [ TUK ���� ���� ]\n";
		cout << "���� ��ȣ �Է�(12�ڸ���) : "; cin >> number;
		cout << "�̸� : "; cin >> name;

		pay = bpay.charge(nTicketPrice);
		cout << "TUK ���� ������ �Ϸ�Ǿ����ϴ�. : ";
	}
	else if (m == CREDIT_CARD_PAYMENT) {
		CardPay cpay(CREDIT_CARD_INTEREST_RATE);
		cout << "        [ �ſ�ī�� ���� ]\n";
		cout << "���� ��ȣ �Է�(12�ڸ���) : "; cin >> number;
		cout << "�̸� : "; cin >> name;

		pay = cpay.charge(nTicketPrice);
		cout << "�ſ�ī�� ������ �Ϸ�Ǿ����ϴ�. : ";
	}
	else cout << " ������ �����߽��ϴ�.\n";

	cout << pay << endl;
	seat->setPayAmount(pay);
	seat->setCheck(SEAT_COMPLETION_MARK);
}