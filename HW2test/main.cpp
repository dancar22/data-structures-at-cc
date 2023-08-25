#include <iostream>
#include "LL.h"
#include <ctime>

using namespace std;


int main() {

	srand(time(0));

	LL<int> longlist;



	for (int i = 0; i < 10; i++ ) {

		int ip = rand() % 100;

		cout << ip << ", " << flush;
		longlist.push_back(ip);


	}
	cout << endl;

	longlist.display_list();










}
