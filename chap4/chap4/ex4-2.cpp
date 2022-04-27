// 4-2, 4-3
#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};

int main() {
	Circle c[3] = { Circle(10), Circle(20), Circle(30)
};
	//c[0].setRadius(10);
	//c[1].setRadius(20);
	//c[2].setRadius(30);

	//for (int i = 0; i < 3; i++) c[i].setRadius((i + 1) * 10);

	Circle* p;
	p = c;

	for (int i = 0; i < 3; i++) cout << "Circle " << i << "의 면적은 " << (p + i)->getArea() << endl;

}