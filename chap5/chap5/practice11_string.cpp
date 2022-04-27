#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class Book {
	string title;
	int price;
public:
	Book(string title, int price);
	~Book() {};
	void show() { cout << title << " " << price << "ø¯" << endl; }
};
Book::Book(string title, int price) {
	this->title = title;
	this->price = price;
}

int main() {
	string a = "∏Ì«∞C++";
	Book cpp(a, 10000);
	Book java = cpp;
	cpp.show();
	java.show();
}