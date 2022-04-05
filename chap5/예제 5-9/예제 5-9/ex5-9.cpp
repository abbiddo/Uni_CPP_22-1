#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
//	Circle(Circle& c);
	Circle() { radius = 1; }
	Circle(int radius) { this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	void setRadius(int radius) { this->radius = radius; }
};
/*Circle::Circle(Circle& c) {
	this->radius = c.radius;
	cout << "���� ������ ���� radius = " << radius << endl;
}*/

int main() {
	Circle src(30);
	Circle dest(src);

	cout << "������ ���� = " << src.getArea() << endl;
	cout << "�纻�� ���� = " << dest.getArea() << endl;

	// ���� ���� �ٸ� ��ü
	
	src.setRadius(20);

	cout << "������ ���� = " << src.getArea() << endl;
	cout << "�纻�� ���� = " << dest.getArea() << endl;
}