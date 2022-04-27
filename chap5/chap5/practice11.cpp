#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Book {
	char* title;
	int price;
public:
	Book(const char* title, int price);
	//Book(Book& book);
	~Book();
	void set(const char* title, int price);
	void show() { cout << title << " " << price << "원" << endl; }
};
Book::Book(const char* title, int price) {
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
	this->price = price;
}
/*Book::Book(Book& b) {
	int len = strlen(b.title);
	this->title = new char[len + 1];
	strcpy(this->title, b.title);
	this->price = b.price;
}*/
void Book::set(const char* title, int price) {
	int len = strlen(title);
	this->title = new char[len + 1];
	strcpy(this->title, title);
	this->price = price;
}
Book::~Book() {
	if (title) 
		delete[] title; // if 가 있으면 오류가 나면 안됨 delete[]title만 했을 때 오류가 나야함
}

int main() {
	char a[] = "명품C++";
	Book cpp(a, 10000);
	Book java = cpp;
	cpp.show();
	java.show();

	char b[] = "어쩔";
	java.set(b, 1000);
	cpp.show();
	java.show();
}