#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};
Circle::Circle() :Circle(1) {}
Circle::Circle(int r) {
	radius = r;
//	cout << "������ ���� radius = " << radius << endl;
}
Circle::~Circle() {
//	cout << "�Ҹ��� ���� radius = " << radius << endl;
}

int main() {
	int radius;
	Circle circle;
	while (true) {
		cout << "���� ������ �Է� (������ ����)>> ";
		cin >> radius;
		circle.setRadius(radius);

		if (radius < 0) break;

//		Circle* p = new Circle(radius);
		cout << "���� ������ " << circle.getArea() << endl;
//		delete p;
	}
}

// ���� -> ����