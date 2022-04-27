#include <iostream>
using namespace std;

class Power {
	int kick, punch;
public:
	Power(int kick = 0, int punch = 0) { this->kick = kick; this->punch = punch; }
	void show();
	friend Power operator+(int op1, Power op2);
};
void Power::show() {
	cout << "kick = " << kick << ", punch = " << punch << endl;
}
Power operator+(int op1, Power op2) {
	Power tmp;
	tmp.kick = op1 + op2.kick;                        // 전역함수지만 friend로 클래스에 선언해줬기 때문에 private 접근 가능
	tmp.punch = op1 + op2.punch;
	return tmp;
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = 2+a;
	a.show();
	b.show();
}
