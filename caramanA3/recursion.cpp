#include <iostream>

using namespace std;

long long int fibb(int n) {

	cout << "\ncomputing fibb #" << n << endl;

	if (n == 1) {
		return 0;
	} else if (n == 2) {
		return 1;
	}

	return fibb(n - 1) + fibb(n - 2);

}

long long int pow(int x, int y) {

	if (y == 1) {
		return x;
	}

	return x * pow(x, y - 1);
}


long long int sum (int sumArray[], int size) {

	if (size == 1) {
		return sumArray[0];
	} else {
		return sumArray[size - 1] + sum(sumArray, size - 1);
	}

}

int countOccurrences(string s) {

	if (s == "") {
		return 0;
	}

	char c = s[s.size() - 1];

	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {

		if (s.size() == 1) {
			return 1;
		}

		s.pop_back();
		return 1 + countOccurrences(s);

	}

	if (s.size() == 1) {

		return 0;
	}

	s.pop_back();
	return countOccurrences(s);

}

string reverseString(string s) {

	if (s.size() == 1) {

		return s;

	} else if (s.size() == 0) {

		return "";

	}

	char c = s[s.size() - 1];
	s.pop_back();


	return c + reverseString(s);

}
