#include <iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base::f() called\n"; }
};

class Derived : public Base {
public:
	virtual void f() { cout << "Derived::f() called\n"; }
};

int main() {
	Derived d, * pDer;
	pDer = &d;
	pDer->f();

	Base* pBase;
	pBase = pDer; // 업캐스팅
	pBase->f();
}