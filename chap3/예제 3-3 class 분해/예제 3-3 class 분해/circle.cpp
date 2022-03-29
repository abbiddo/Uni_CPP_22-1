#include <iostream>
#include "circle.h"
using namespace std;

Circle::Circle() :Circle(1) {} // 위임 생성자
Circle::Circle(int r) { // 타겟 생성자
	radius = r;
	cout << "반지름 " << radius << "원 생성" << endl;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}