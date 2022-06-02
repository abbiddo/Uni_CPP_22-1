#include <iostream>
using namespace std;

ostream& fivestar(ostream& outs) { return outs << "*****"; }
ostream& rightarrow(ostream& outs) { return outs << "---->"; }
ostream& beep(ostream& outs) { return outs << '\a'; }

int main() {
	cout << "벨이 울령" << beep << endl;
	cout << "C " << rightarrow << " C++ " << rightarrow << " JAVA" << endl;
	cout << "Visual" << fivestar << "C++" << endl;
}