#include <iostream>
using namespace std;

istream& question(istream& ins) {
	cout << "거울아 거울아 누가 제일 예쁘니? ";
	return ins;
}

// 안에서 입력 못 받아?

//istream& question(istream& ins, string answer) {
//	cout << "거울아 거울아 누가 제일 예쁘니?";
//	ins >> answer;
//	return ins;
//}

int main() {
	string answer;
	cin >> question >> answer;
	cout << answer << endl;
}