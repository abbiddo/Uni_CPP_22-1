//4-7, 4-8, 4-9
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int r = 1) { radius = r; }
	~Circle() { cout << "소멸자 실행 " << radius << endl; }
	void setRadius(int r) { radius = r; }
	void getArea() { cout << 3.14 * radius * radius << endl; }
};

int main() {
	/* 4-7
	Circle* p, * q;
	p = new Circle;
	q = new Circle(30);
	cout << p->getArea() << endl;
	cout << q->getArea() << endl;

	delete p;
	delete q;*/

	/* 4-8
	int radius;
	while (1) {
		cin >> radius;
		if (radius < 0) break;
		Circle* p = new Circle(radius);
		cout << p->getArea() << endl;

		delete p;
	}*/

	int n;
	cin >> n;
	Circle* p = new Circle[n];

	for (int i = 0; i < n; i++) p[i].setRadius(i+5);
	for (int i = 0; i < n; i++) (p+i)->getArea();

	Circle* pArray = p;
	for (int i = 0; i < n; i++) (pArray++)->getArea();

	delete[] p;

	// 가리키는 주소가 사라져서 쓰레기값 나옴
	for (int i = 0; i < n; i++) (pArray++)->getArea();
}