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
	cout << "복사 생성자 실행 radius = " << radius << endl;
}*/

int main() {
	Circle src(30);
	Circle dest(src);

	cout << "원본의 면적 = " << src.getArea() << endl;
	cout << "사본의 면적 = " << dest.getArea() << endl;

	// 둘은 완전 다른 객체
	
	src.setRadius(20);

	cout << "원본의 면적 = " << src.getArea() << endl;
	cout << "사본의 면적 = " << dest.getArea() << endl;
}