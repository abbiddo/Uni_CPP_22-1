#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s, '\n');

	int sum = 0;
	int start = 0;

	while (1) {
		int index, n;
		index = s.find('+');// , start);
		string num;

		if (index == -1) {
			num = s.substr(start);
			n = stoi(num);
			sum += n;
			break;
		}
		
		num = s.substr(start, index-start);
		n = stoi(num);
		start = index + 1;
		sum += n;
	}

	cout << sum;
}