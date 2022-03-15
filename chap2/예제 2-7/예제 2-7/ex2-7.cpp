#include <iostream>
#include <string>
using namespace std;

int main() {
	string song("Falling in love with you");
	string elvis="Elvis Presley";
	string singer;

	cout << song + "를 부른 가수는"; // + 연산자 (오퍼레이터) 재정의
	cout << "(힌트 : 첫글자는" << elvis[0] << ")";

	getline(cin, singer); // 얘는 string 헤더 파일 필수

	if (singer == elvis) cout << "맞았습니다"; // == 연산자 (오퍼레이터) 재정의
	else cout << "틀렸습니다. " + elvis + "입니다." << endl;
}