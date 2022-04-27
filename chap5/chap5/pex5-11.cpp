#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person {
	char* name;
	int id;
public:
	Person(int id, char* name);
	Person(Person& person);
	~Person();
};
Person::Person(int id, char* name) {
	this->id = id;
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);
}
Person::Person(Person& person) {
	id = person.id;
	int len = strlen(person.name);
	name = new char[len + 1];
	strcpy(name, person.name);
}
Person::~Person() {
	delete[] name;
}

int main() {
	char a[] = "Kiate";
	Person father(1, a);
	Person k(father);
}