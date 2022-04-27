#include <iostream>
using namespace std;

class Rectangle {
public:
	int width, height;
//	Rectangle();
	Rectangle(int w=1, int h=1);
//	Rectangle(int length);
	bool isSquare();
};

//Rectangle::Rectangle() :Rectangle(1,1){}
//Rectangle::Rectangle(int length) : Rectangle(length, length) {
//	//width = height = length;
//}
Rectangle::Rectangle(int w, int h) :width(w), height(h){
	width = w;
	height = h;
}
bool Rectangle::isSquare() {
	cout << width << " " << height << endl;
	return (width == height);
}

int main() {
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);

	if (rect1.isSquare()) cout << "rect1 is Square"<<endl;
	if (rect2.isSquare()) cout << "rect2 is Square" << endl;
	if (rect3.isSquare()) cout << "rect3 is Square" << endl;
}