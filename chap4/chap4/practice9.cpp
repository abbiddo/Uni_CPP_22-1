#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person() { cout << "이름과 전화 번호를 입력해주세요" << endl; }
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
		cout << "사람 " << i + 1 << ">> ";
		string name, tel;
		cin >> name >> tel;
		p[i].set(name, tel);
	}

	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++) cout << p[i].getName() << " ";
	
	cout << "\n전화번호 검색합니다. 이름을 입력하세요>> ";
	string name;
	cin >> name;

	for (int i = 0; i < 3; i++)
		if (name == p[i].getName()) cout << p[i].getTel();
}