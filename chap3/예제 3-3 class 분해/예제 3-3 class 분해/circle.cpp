#include <iostream>
#include "circle.h"
using namespace std;

Circle::Circle() :Circle(1) {} // ���� ������
Circle::Circle(int r) { // Ÿ�� ������
	radius = r;
	cout << "������ " << radius << "�� ����" << endl;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}