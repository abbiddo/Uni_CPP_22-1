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
Circle::Circle() :Circle(1) {} // 위임 생성자
Circle::Circle(int r) :radius(r){ // 타겟 생성자
	//radius = r;
	cout << "반지름 " << radius << "원 생성" << endl;
}
Circle::~Circle() {
	cout << "반지름 " << radius << "원 소멸" << endl;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}

void f() {
	Circle donut(100); // 변수랑 똑같이 함수 안에서는 변수 이름 같아도 됨
}

int main() {
	Circle donut;
	//double area = donut.getArea();
	cout << "dount 면적은 " << donut.getArea() << endl;

	Circle pizza(30);
	//area = pizza.getArea();
	//cout << "pizza 면적은 " << area << endl;

	f();
}