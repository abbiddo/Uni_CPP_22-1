#include <iostream>
using namespace std;

int main() {
	char line[80];
	cout << "cin.getline()\n";
	cout << "exit �Է� �� ����.\n";

	int no = 1;
	while (1) {
		cout << "����" << no << " : ";
		cin.getline(line, 80);
		if (strcmp(line, "exit") == 0) break;
		cout << "echo ->";
		cout << line << endl;
		no++;
	}
}