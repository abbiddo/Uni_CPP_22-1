#ifndef TICKET_H
#define TICKET_H

#define SEAT_EMPTY_MARK '-'
#define SEAT_RESERVED_MARK 'R'
#define SEAT_COMPLETION_MARK '$'

class Ticket {
	int nRow;				// �¼� ��
	int nCol;				// �¼� ��
	char charCheck;	// ���� ����
	int nReservedID;	// ���� ��ȣ
	int nPayAmount;	// ���� �ݾ�
	int nPayMethod;	// ���� ����
public:
	Ticket(){}
	void setCheck(char check) { charCheck = check; }							// �¼� ���� ����
	char getCheck() { return charCheck; }											// �¼� ���� �б�

	void setSeat(int row, int col) { nRow = row; nCol = col; }				// �¼� ��ȣ ����
	void setReservedID(int reserved) { nReservedID = reserved; }		// �¼� ���� ��ȣ ����
	int getReservedID() { return nReservedID; }									// �¼� ���� ��ȣ �б�

	void setPayAmount(int amount) { nPayAmount = amount; }			// ���� �ݾ� ����
	int getPayAmount() { return nPayAmount; }									// ���� �ݾ� �б�
	void setPayMethod(int method) { nPayMethod = method; }			// ���� ���� ����
};

#endif