#include <iostream>
#include <ctime>

using namespace std;

int generateKey() {
	int a,b,c,d;
	a = rand();
	b = rand();
	c = rand();
	d = abs (a*b*c) % 999999999;
	return d;

}

int hashFunction(int key) {

	return key % 109;

}

int main() {

	srand(time(0));
//	for (int i = 0; i < 10; i++) {
//		cout << generateKey() << endl;
//	}
	int k = 0;
	int index = 0;

	int hashResults[109] = {0};
	int i;
	for (int i = 0; i < 109; i++) {
		k = generateKey();
		index = hashFunction(k);
		hashResults[index]++;

	}

	for (int i = 0; i < 109; i++) {

		cout << "number " << i << ": " << hashResults[i] << endl;
	}

//	int employeeTable[3000];
//	int key;
//	cout << "enter key" << endl;
//	cin >> key;
//	while (key > 0) {
//		int hashedIndex = hashFunction(key);
//		employeeTable[hashedIndex] = key;
//		cout << "the hash was " << hashedIndex << endl;
//		cout << "enter key" << endl;
//		cin >> key;
//	}
}
