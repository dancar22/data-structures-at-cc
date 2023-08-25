#include <iostream>
#include <cmath>

using namespace std;

int isPrime(long long int n, long long int div = 2) {

	if (n <= 1) {
		return false;
	}

	if (div > pow(n, 0.5)) {
		return true;
	}
	if (n % div == 0) {
		return false;
	}

	return isPrime(n, div + 1);

}

int fib(int n) {

	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {

		return fib(n - 1) + fib (n - 2);

	}

}

int mult(int x, int y) {

	if (y == 1) {

		return x;

	} else {

		return x + mult(x, y - 1);

	}

}

unsigned long long int fac(int i) {

	if (i == 1) {
		return 1;
	} else {
		return i * fac(i - 1);
	}

}


int main() {

	for (int i = 0; i < 1000; i ++) {
		if (isPrime(i)) {
			cout << i << ", ";
		}

	}

//	for (int i = 1; i < 0; i ++) {
//
//		cout << "factorial of " << i << ": " << fib(i) << endl;
//
//	}

//	int n = 6;
//	int product = 1;
//
//	while (n > 1) {
//		product *= n;
//
//		n--;
//
//	}
//
//	cout << product << endl;




}
