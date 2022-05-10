#include <iostream>
using namespace std;

class Base {
public:
	virtual ~Base() { cout << "~Base()\n"; }
};

class Derived : public Base {
public:
	virtual ~Derived() { cout << "~Derived()\n"; }
	// virtual 생략 가능
};

int main() {
	Derived* dp = new Derived();
	Base* bp = new Derived();

	delete dp;
	delete bp;
}