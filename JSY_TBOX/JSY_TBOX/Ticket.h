#ifndef TICKET_H
#define TICKET_H

#define SEAT_EMPTY_MARK '-'
#define SEAT_RESERVED_MARK 'R'
#define SEAT_COMPLETION_MARK '$'

class Ticket {
	int nRow;				// 좌석 행
	int nCol;				// 좌석 열
	char charCheck;	// 예약 여부
	int nReservedID;	// 예약 번호
	int nPayAmount;	// 결제 금액
	int nPayMethod;	// 결제 수단
public:
	Ticket(){}
	void setCheck(char check) { charCheck = check; }							// 좌석 상태 저장
	char getCheck() { return charCheck; }											// 좌성 상태 읽기

	void setSeat(int row, int col) { nRow = row; nCol = col; }				// 좌석 번호 저장
	void setReservedID(int reserved) { nReservedID = reserved; }		// 좌석 예약 번호 저장
	int getReservedID() { return nReservedID; }									// 좌석 예약 번호 읽기

	void setPayAmount(int amount) { nPayAmount = amount; }			// 결제 금액 저장
	int getPayAmount() { return nPayAmount; }									// 결제 금액 읽기
	void setPayMethod(int method) { nPayMethod = method; }			// 결제 수단 저장
};

#endif