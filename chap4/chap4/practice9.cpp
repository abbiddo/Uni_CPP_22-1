#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() { cout << "�̸��� ��ȭ ��ȣ�� �Է����ּ���" << endl; }
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};
void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main() {
	Person p[3];

	for (int i = 0; i < 3; i++) {
		cout << "��� " << i + 1 << ">> ";
		string name, tel;
		cin >> name >> tel;
		p[i].set(name, tel);
	}

	cout << "��� ����� �̸��� ";
	for (int i = 0; i < 3; i++) cout << p[i].getName() << " ";
	
	cout << "\n��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>> ";
	string name;
	cin >> name;

	for (int i = 0; i < 3; i++)
		if (name == p[i].getName()) cout << p[i].getTel();
}