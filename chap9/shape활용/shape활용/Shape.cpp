#include <iostream>
#include "Shape.h"
using namespace std;

void Shape::paint() { draw(); }
// void Shape::draw() { cout << "--Shape--\n"; }
Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}