#include <iostream>
#include <fstream>
#include "EmployeeData.h"
#include "HTE.h"

using namespace std;

int hash_function(string key) {

	string characters = key.substr(0, 3);
	int integers = stoi(key.substr(3, 6));

	for (int i = 0; i < characters.size(); i+=1) {

		integers += (characters[i] % 5);

	}

	return integers % 160;

}

bool isValidHash(string userInput) {

	if (userInput.length() != 9) {
		return false;
	}

	for (int i = 0; i < 3; i++) {

		if (userInput[i] < 64 || userInput[i] > 91) {

			return false;

		}

	}

	for (int i = 3; i < userInput.length(); i++) {

		if (userInput[i] < 47 || userInput[i] > 58) {

			return false;

		}

	}

	return true;

}


int main() {

	int hashTableEnt[160] = {0};

	ifstream inFile;
	inFile.open("a6data F22.txt", ios::in);

	if (!inFile.is_open()) {
		cout << "open failure" << endl;
		exit(-1);
	}


	string input;
	getline(inFile, input);
	EmployeeData temp;
	int i = 0;

	while(!inFile.eof()) {

		i = 0;
		temp.id = input.substr(i, 9);
		i += 9;
		temp.name = input.substr(i, 24);

		int j = hash_function(temp.id);

		hashTableEnt[j]++;

		getline(inFile, input);
	}

	inFile.close();

	int numWithZero = 0;
	int numWith1 = 0;
	double numWithMore = 0;
	double totalWithMore = 0;

	for (int i = 0; i < 160; i++) {
		int j = hashTableEnt[i];

		if (j == 0) {
			numWithZero++;
		} else if (j == 1) {
			numWith1++;
		} else {
			numWithMore++;
			totalWithMore += j;
		}

	}


	cout << "number of elements with 0 hashes\t" << numWithZero << endl;
	cout << "number of elements with 1 hash\t\t" << numWith1 << endl;
	cout << "number of elements with >1 hash\t\t" << numWithMore << endl;
	cout << "average chain size for elements with > 1 hash\t" << totalWithMore/numWithMore << endl;


	HTE hashTable[160];

	for (int i = 0; i < 160; i++) {

		hashTable[i].employee.id = "0";
		hashTable[i].employee.name = "";

	}

	inFile.open("a6data F22.txt", ios::in);

	if (!inFile.is_open()) {
		cout << "open failure" << endl;
		exit(-1);
	}


	getline(inFile, input);


	while(!inFile.eof()) {

		i = 0;
		temp.id = input.substr(i, 9);
		i += 9;
		temp.name = input.substr(i, 24);


		int j = hash_function(temp.id);


		if (hashTable[j].employee.id == "0") {
			hashTable[j].employee = temp;
		} else {
			hashTable[j].collisions.push_back(temp);
		}


		getline(inFile, input);
	}
	inFile.close();


	int numOfEmployees = 0;

	for (int i = 0; i < 160; i++) {

		cout << "hash table entry " << i << " ";

		EmployeeData temp = hashTable[i].employee;
		HTE tempHTE = hashTable[i];

		if (temp.id == "0") {
			cout << "no data" << endl;
		} else {

			cout << "employee " << temp.id << " name " << temp.name << endl;

			tempHTE.collisions.display_list();
			numOfEmployees += (1 + tempHTE.collisions.list_length());
		}


	}

	cout << "end of the list. There are " << numOfEmployees << " employees." << endl;


	string userInput;
	cout << "enter key to search for:" << endl;
	getline(cin, userInput);
	while(userInput != "0") {

		if (isValidHash(userInput)) {

			int j = hash_function(userInput);

			EmployeeData temp;
			temp.id = "0";

			if (hashTable[j].employee.id == userInput) {
				temp = hashTable[j].employee;
			} else {
				temp = hashTable[j].collisions.search_list(userInput);
			}

			if (temp.id == "0" or temp.id == "") {

				cout << "employee not found" << endl;

			} else {
				cout << "employee " << temp.id << " name " << temp.name << endl;
			}

		} else {
			cout << "improper format, ID has to follow the following format: ABC123456" << endl;
		}


		cout << "enter key to search for:" << endl;
		getline(cin, userInput);



	}

	cout << "thanks and have a good day!" << endl;

	for (int i = 0; i < 160; i++) {
		hashTable[i].collisions.destroy_list();
	}



	return 0;
}
