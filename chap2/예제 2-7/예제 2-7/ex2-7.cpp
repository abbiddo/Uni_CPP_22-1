#include <iostream>
#include <string>
using namespace std;

int main() {
	string song("Falling in love with you");
	string elvis="Elvis Presley";
	string singer;

	cout << song + "�� �θ� ������"; // + ������ (���۷�����) ������
	cout << "(��Ʈ : ù���ڴ�" << elvis[0] << ")";

	getline(cin, singer); // ��� string ��� ���� �ʼ�

	if (singer == elvis) cout << "�¾ҽ��ϴ�"; // == ������ (���۷�����) ������
	else cout << "Ʋ�Ƚ��ϴ�. " + elvis + "�Դϴ�." << endl;
}