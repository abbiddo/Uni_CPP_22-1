#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s, '&');
	cin.ignore();

	cout << "find : ";
	string f;
	getline(cin, f, '\n');

	cout << "replace : ";
	string re;
	getline(cin, re, '\n');

	int flen = f.length();
	int rlen = re.length();
	int start = 0;

	while (1) {
		int index = s.find(f, start);
		if (index == -1) break;

		s.replace(index, flen, re);
		start = index + rlen;
	}

	cout << s;
}