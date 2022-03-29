#include <iostream>
#include <string>
using namespace std;

class Person {
	string name;
	string tel;
public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};
Person::Person() {

}
void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main() {
	Person person[3];
	string name, tel;

	cout << "이름과 전화 번호를 입력해주세요\n";
	for (int i = 0; i < 3; i++) {
		cout << "사람 " << i + 1<<">> ";
		cin >> name >> tel;
		person[i].set(name, tel);
	}
	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++) cout << person[i].getName()<<" ";
	cout << "\n";
	cout << "전화번호 검색합니다. 이름을 입력하세요>>";

	string telname;
	cin >> telname;

	for (int i = 0; i < 3; i++) {
		if (person[i].getName() == telname) {
			cout << "전화 번호는 " << person[i].getTel();
			break;
		}
	}
}