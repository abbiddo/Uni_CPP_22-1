#include <iostream>
using namespace std;

class Base {
public:
	virtual void f() { cout << "Base\n"; }
};
class Derived: public Base {
public:
	void f() { cout << "Derived\n"; }
};
class GrandDerived : public Derived{
public:
	void f() { cout << "GrandDerived\n"; }
};

int main() {
	GrandDerived g, * gp;
	Base* bp;
	Derived* dp;

	bp = dp = gp = &g;

	bp->f();
	dp->f();
	gp->f();
}