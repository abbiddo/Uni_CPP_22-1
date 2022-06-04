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
	cout << "\n        [ 좌석 예약 현황 ]" << endl;
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
	cout << "       영화 메뉴 - " << strMovieName << endl;
	cout << "------------------------------------\n";

	cout << " 1. 상영 영화 정보\n";
	cout << " 2. 좌석 예약 현황\n";
	cout << " 3. 좌석 예약 하기\n";
	cout << " 4. 좌석 예약 취소\n";
	cout << " 5. 좌석 예약 결제\n";
	cout << " 7. 메인 메뉴 이동\n\n";
}

void EuropeScreen::showMovieInfo() {
	cout << "\n------------------------------------\n";
	cout << "       [ " << strMovieName << " ]\n";
	cout << "------------------------------------\n";

	cout << "  영화관 : 유럽 영화 1관\n";
	cout << "  주인공 : 롤프 라스가드, 필립 버그\n";
	cout << "  줄거리 : 오베가 애플 전자제품 가게에서 ...\n";
	cout << "  가격 " << nTicketPrice << endl;
}
void AsiaScreen::showMovieInfo() {
	cout << "\n------------------------------------\n";
	cout << "       [ " << strMovieName << " ]\n";
	cout << "------------------------------------\n";

	cout << "  영화관 : 아시아 영화 2관\n";
	cout << "  주인공 : 지창욱, 심은경, 안재홍\n";
	cout << "  줄거리 : 주머니 사정이 넉넉하지 않아 ...\n";
	cout << "  가격 " << nTicketPrice << endl;
}
void PremiumScreen::showMovieInfo() {
	cout << "\n------------------------------------\n";
	cout << "       [ " << strMovieName << " ]\n";
	cout << "------------------------------------\n";

	cout << "  영화관 : 프리미엄 영화 3관\n";
	cout << "  주인공 : 다니엘 래드클리프, 엠마 왓슨 \n";
	cout << "  줄거리 : 해리의 호그와트 마법학교 입학 통지서 ...\n";
	cout << "  가격 " << nTicketPrice << endl;
}

void Screen::reserveTicket() {
	int r, c;
	cout << "\n  [ 좌석 예약 ]\n";
	cout << "좌석 행 번호 입력(1 - " << nRowMax << ") : ";
	cin >> r;
	cout << "좌석 행 번호 입력(1 - " << nColMax << ") : ";
	cin >> c;

	if (pSeatArray[r - 1][c - 1].getCheck() == SEAT_RESERVED_MARK) {
		cout << "이미 예약된 좌석입니다.\n";
		return;
	}
	if (pSeatArray[r - 1][c - 1].getCheck() == SEAT_COMPLETION_MARK) {
		cout << "이미 예매된 좌석입니다.\n";
		return;
	}
	cout << "행[" << r << "] 열[" << c << "] " << nCurrentReservedId << " 예약 번호로 접수되었습니다.\n";

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
	cout << "\n  [ 좌석 취소 ]\n";
	cout << "예약 번호 입력 : ";
	cin >> n;

	Ticket* seat = checkReservedID(n);
	if (!seat) {
		cout << "예약 번호를 확인해주세요.\n";
		return;
	}

	if (seat->getCheck() == SEAT_COMPLETION_MARK) {
		cout << "이미 결제가 완료된 좌석입니다.\n";
		return;
	}

	seat->setSeat(0, 0);
	seat->setReservedID(0);
	seat->setCheck(SEAT_EMPTY_MARK);
	cout << n << " 예약 번호가 취소 처리되었습니다.\n";
}

void Screen::Payment() {
	int n, m;
	cout << "\n  [ 예약 좌석 결제 ]\n";
	cout << "예약 번호 입력 : ";
	cin >> n;

	Ticket* seat = checkReservedID(n);
	if (!seat) {
		cout << "예약 번호를 확인해주세요.\n";
		return;
	}

	if (seat->getCheck() == SEAT_COMPLETION_MARK) {
		cout << "이미 결제가 완료된 좌석입니다.\n";
		return;
	}

	cout << "\n------------------------------------\n";
	cout << "       결제 방식 선택\n";
	cout << "------------------------------------\n";

	cout << " 1. 모바일 결제\n";
	cout << " 2. 은행 이체 결제\n";
	cout << " 3. 카드 결제\n";

	cout << "\n 결제 방식 (1~3): "; cin >> m;
	seat->setPayMethod(m);

	string number, name;
	int pay;

	if (m == MOBILE_PHONE_PAYMENT) {
		MobilePay mpay(MOBILE_PHONE_INTEREST_RATE);
		cout << "        [ 모바일 결제 ]\n";
		cout << "핸드폰 번호 입력(11자리수) : "; cin >> number;
		cout << "이름 : "; cin >> name;

		pay = mpay.charge(nTicketPrice);
		cout << "모바일 결제가 완료되었습니다. : ";
	}
	else if (m == BANK_TRANSFER_PAYMENT) {
		BankTransfer bpay(BANK_TRANSFER_INTEREST_RATE);
		cout << "        [ TUK 은행 결제 ]\n";
		cout << "은행 번호 입력(12자리수) : "; cin >> number;
		cout << "이름 : "; cin >> name;

		pay = bpay.charge(nTicketPrice);
		cout << "TUK 은행 결제가 완료되었습니다. : ";
	}
	else if (m == CREDIT_CARD_PAYMENT) {
		CardPay cpay(CREDIT_CARD_INTEREST_RATE);
		cout << "        [ 신용카드 결제 ]\n";
		cout << "은행 번호 입력(12자리수) : "; cin >> number;
		cout << "이름 : "; cin >> name;

		pay = cpay.charge(nTicketPrice);
		cout << "신용카드 결제가 완료되었습니다. : ";
	}
	else cout << " 결제를 실패했습니다.\n";

	cout << pay << endl;
	seat->setPayAmount(pay);
	seat->setCheck(SEAT_COMPLETION_MARK);
}