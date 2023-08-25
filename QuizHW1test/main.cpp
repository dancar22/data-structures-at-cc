#include <iostream>
#include <vector>

using namespace std;

int SIZE = 5;

void anotherFunc(int myints []) {

	for (int i = 0; i < SIZE; i++) {

		cout << myints[i] << endl;

	}

}

void xyz(vector<int> v) {

	int n = 9;

	cout << &n << endl;

}

void myFunc(int  * & myint) {

	cout << *myint << endl;
}

int main() {



	int * ip = new int;
	*ip = 5;

	int * ip2 = &ip;

	cout << "first: " << *ip << *(*ip2) << endl;





	return 0;
}
