#include <iostream>
using namespace std;

class Power {
	int kick, punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick;
		this->punch = punch;
	}
	void show();
	Power operator+ (Power op2);
};
void Power::show() {
	cout << "kick = " << kick << ", punch = " << punch << endl;
}

Power Power::operator+(Power op2) {
	Power tmp;
	tmp.kick = this->kick + op2.kick;
	tmp.punch = this->punch + op2.punch;
	return tmp;
}

int main() {
	Power a(1, 1), b;
	b = a + a + a + a + a + a + a + a + a + a + a + a;
	a.show();
	b.show();

}