// 3-3,3-4,3-7,3-8
#include <iostream>
using namespace std;

class Circle {
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
	double getArea();
};
Circle::Circle() :Circle(1) {} // ���� ������
Circle::Circle(int r) :radius(r){ // Ÿ�� ������
	//radius = r;
	cout << "������ " << radius << "�� ����" << endl;
}
Circle::~Circle() {
	cout << "������ " << radius << "�� �Ҹ�" << endl;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}

void f() {
	Circle donut(100); // ������ �Ȱ��� �Լ� �ȿ����� ���� �̸� ���Ƶ� ��
}

int main() {
	Circle donut;
	//double area = donut.getArea();
	cout << "dount ������ " << donut.getArea() << endl;

	Circle pizza(30);
	//area = pizza.getArea();
	//cout << "pizza ������ " << area << endl;

	f();
}