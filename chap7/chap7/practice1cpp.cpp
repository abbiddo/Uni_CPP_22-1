#include <iostream>
using namespace std;



class Book {
	string title;
	int price, page;
public:
	Book(string title = "", int price = 0, int page = 0) {
		this->title = title;
		this->price = price;
		this->page = page;
	}
	void show() { cout << title << " " << price << "원 " << page << " 페이지" << endl; }
	string getTitle() { return title; }

//	Book& operator+= (int b);
//	Book& operator-= (int b);

	friend void operator+= (Book& book, int b);
	friend void operator-= (Book& book, int b);
};
//Book& Book::operator+= (int b) {
//	price += b;
//	return *this;
//}
//Book& Book::operator-= (int b) {
//	price -= b;
//	return *this;
//}

void operator+= (Book& book, int b) {
	book.price += b;
	//return book;
}
void operator-= (Book& book, int b) {
	book.price -= b;
	//return book;
}

int main() {
	Book a("청춘", 20000, 300), b("미래", 30000, 500);
	a += 500;
	b -= 500;
	a.show();
	b.show();
}