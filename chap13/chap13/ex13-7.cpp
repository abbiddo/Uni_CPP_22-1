#include <iostream>
using namespace std;

class MyStack {
	int data[100];
	int tos;
public:
	MyStack() { tos = -1; }
	void push(int n) throw(char*);
	int pop() throw(char*);
};
void MyStack::push(int n) {
	if (tos == 99) throw "Stack Full";
	data[++tos] = n;
}
int MyStack::pop() {
	if (tos == -1) throw "Stack Empty";
	int rData = data[tos--];
	return rData;
}

int main() {
	MyStack intStack;
	try {
		intStack.push(100);
		intStack.push(200);
		cout << intStack.pop() << endl;
		cout << intStack.pop() << endl;
		cout << intStack.pop() << endl;
		cout << intStack.pop() << endl;
	}
	// 사이엔 무엇도 들어갈 수 없음
	catch (const char* s) {
		cout << "예외 발생 : " << s << endl;
	}
}