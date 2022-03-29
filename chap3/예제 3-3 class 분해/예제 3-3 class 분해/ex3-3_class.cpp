#include <iostream>
#include "circle.h"
using namespace std;

int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "dount 면적은 " << area << endl;

	Circle pizza(30);
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;
}