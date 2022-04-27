#include <iostream>
using namespace std;

class Power {
	int kick, punch;
public:
	Power(int kick = 0, int punch = 0) { this->kick = kick; this->punch = punch; }
	void show();
	bool operator!();
};
void Power::show() {
	cout << "kick = " << kick << ", punch = " << punch << endl;
}
bool Power::operator!() {
	return (kick == 0 && punch == 0);
}

int main() {
	Power a, b(5, 5);
	cout << !a;
	cout << !b;
}