#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(int id, char* name);
	~Person();
	void changeName(char* name);
	void show() { cout << id << "," << name << endl; }
};
Person::Person(int id, char* name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}
Person::~Person() {
	if (name) delete[] name;
}
void Person::changeName(char* name) {
	if (strlen(name) > strlen(this->name)) return;
	strcpy(this->name, name);
}

int main() {
	char a[] = "Kitae";
	Person father(1, a);
	Person daughter(father);

	cout << "daughter ��ü ���� ���� ---" << endl;
	father.show();
	daughter.show();

	char b[] = "Grace";
	daughter.changeName(b);
	cout << "daughter �̸��� Grace�� ������ �� ---" << endl;
	father.show();
	daughter.show();

	return 0;
}