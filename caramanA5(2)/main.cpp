#include <iostream>
#include "stack.h"

using namespace std;


int main() {
	Stack s;

	for (int i = 0; i < 100; i++) {
		s.push(i);
		int b;
		s.top(b);
		cout << "i = " << i << "| s.top() = " << b << endl;
	}

	for (int i = 99; i >= 0; i--) {
		int b;
		s.top(b);
		cout << "i = " << i << "| s.top() = " << b << endl;
		s.pop();

	}
	int i;
	if(!s.top(i)) {
		cout << "correct" << endl;
	}

	for (int i = 0; i < 100; i++) {
			s.push(i);
			int b;
			s.top(b);
			cout << "i = " << i << "| s.top() = " << b << endl;
		}

	s.destroy();
	for (int i = 99; i >= 0; i--) {
		int b = 0;
		s.top(b);
		cout << "i = " << i << "| s.top() = " << b << endl;
		s.pop();

	}

	for (int i = 0; i < 100; i++) {
				s.push(i);
				int b;
				s.top(b);
				cout << "i = " << i << "| s.top() = " << b << endl;
			}




	return 0;
}
