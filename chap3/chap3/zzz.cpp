//#include <iostream>
//#include <cstring>
//using namespace std;
//class Point {
//public:
//	int x, y;
//	Point();
//	Point(int a, int b);
//	Point f() { return *this; }
//	void g(Point p) {
//		p.show();
//	}
//	void show();
//
//	Point* re() { return this; }
//};
//Point::Point() { x = 1; y = 1; }
//Point::Point(int a, int b) : x(a),y(b){ }
//void Point::show() {
//	cout << x << " " << y << endl;
//}
//
//int main() {
//	Point p1(2,3);
//	Point p2(p1);
//
//	Point p3;
//	p3 = p2.f();
//	p3.show();
//	p1.g(p2);
//
//	/*Point t[3] = { Point(1,2),Point(2,3),Point(3,2) };
//	t[0].show();
//	t->show();
//	(*t).show();
//	(t + 2)->show();*/
//}

//#include <iostream>
//using namespace std;
//
//class Swap{
//public:
//	void s1(int a, int b);
//	void s1(int* a, int* b);
//	void s2(int& a, int& b);
//	void show(int a, int b) { cout << a << " " << b << endl; }
//};
//void Swap::s1(int a, int b) {
//	int tmp;
//	tmp = a; a = b; b = tmp;
//}
//void Swap::s1(int* a, int* b) {
//	int tmp;
//	tmp = *a; *a =* b; *b = tmp;
//}
//void Swap::s2(int& a, int& b) {
//	int tmp;
//	tmp = a; a = b; b = tmp;
//}
//
//int main() {
//	Swap swap;
//	int a = 3, b = 5;
//	swap.show(a, b);
//	swap.s1(a, b);
//	swap.show(a,b);
//	swap.s1(&a, &b);
//	swap.show(a,b);
//	swap.s2(a, b);
//	swap.show(a,b);
//}


#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int r = 1) { radius = r; cout << radius << " 积己磊 角青\n"; }
	~Circle() { cout << radius << " 家戈磊 角青"; }
	void setRadius(int r) { radius = r; }
	int getRadius() { return radius; }
};
void increase(Circle c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
}
void increase(Circle* c) {
	int r = (*c).getRadius();
	(*c).setRadius(r + 1);
}
void increase2(Circle& c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
}

int main() {
	Circle c1;
	increase(c1);
	increase(&c1);
	increase2(c1);
	increase2(c1);
}
