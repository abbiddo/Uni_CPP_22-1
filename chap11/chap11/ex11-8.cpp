#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << showbase;

	cout << setw(8) << "Number";
	cout << setw(10) << "Octal";
	cout << setw(10) << "Hexa" << endl;

	for (int i = 0; i < 50; i += 5) {
		cout << setw(8) << setfill('.') << dec << i;		// setfill 한 번만 해도 됨
		cout << setw(10) << oct << i;
		cout << setw(10) << hex << i << endl;
	}
}