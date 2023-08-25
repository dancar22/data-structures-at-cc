#include <iostream>
#include <iomanip>
#include "recursion.h"

using namespace std;

int main() {

	cout << "********** first 10 fibonacci numbers **********" << endl;
	for (int i=1; i<=10; i++)
	{
		cout << setw (6) << fibb(i);
	}
	cout << endl << "********** end of fibonacci test **********" << endl;
	cout << endl << endl;

	cout << "3 to the 4th is " << pow (3, 4) << endl;
	cout << "5 to the 1st is " << pow (5, 1) << endl;
	cout << endl << endl;

	int array[5] = {5,4,3,2,1};
	cout << "sum of entire array is " << sum (array, 5) << endl;
	cout << "sum of first element only is " << sum (array, 1) << endl;
	cout << "sum of first three elements is " << sum (array, 3) << endl;
	cout << endl << endl;

	string s = "now is the time for each good person";
	cout << "number of vowels is " << countOccurrences (s) << endl;
	s = "aeiouy";
	cout << "number of vowels is " << countOccurrences (s) << endl;
	s = "bcd";
	cout << "number of vowels is " << countOccurrences (s) << endl;
	cout << endl << endl;

	cout << "reverse of " << s << " is " << reverseString (s) << endl;
	s = "abcd";
	cout << "reverse of " << s << " is " << reverseString (s) << endl;
	return 0;
}
