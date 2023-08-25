#include <iostream>

using namespace std;

void BS (int array[], int high, int &numIter) {

	numIter = 0;
	int i, j;
	int temp;
	bool sorted = false;
	int upperLimit = high;

	for (i = 0; i < high && !sorted; i++) {

		sorted = true;
		for (j = 0; j < upperLimit; j++) {

			numIter++;
			if (array[j] > array[j + 1]) {

				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				sorted = false;

			}

		}
		upperLimit--;

	}

}


int main() {

	int array[5] = {54,34,37,12,9};
	int i = 3;
	cout << "array[i] = " << array[i] << endl;
	cout << "i[array] = " << i[array] << endl;

//	int numIter = 0;
//	int a[10] = {2, 3, 4, 5, 6, 6, 10, 11, 12, 1};
//
//	BS(a, 9, numIter);
//
//	for (int i = 0; i < 10; i++) {
//
//		cout << a[i] << endl;
//
//	}
//
//	cout << "iterations: " << numIter << endl;


	return 0;
}
