#include <iostream>
#include <fstream>
#include <vector>
#include "graph.h"

using namespace std;

int main() {


	vector<Vertex> adjList;

	fstream inputFile;

	inputFile.open("A9 F2022.ini", ios::in);
	int NUM_VER;
	inputFile >> NUM_VER;
	inputFile.close();


	inputFile.open("A9data688g3 F2022.txt", ios::in);

	if(!inputFile.is_open()) {
		cout << "file not open" << endl;
		return -1;
	}

	int i = 0;

	inputFile >> i;

	while (!inputFile.eof()) {

		Vertex v;
		v.vertexValue = i;

		inputFile >> i;

		while (i != -1) {
			v.neighbor.push_back(i);
			inputFile >> i;
		}

		adjList.push_back(v);
		inputFile >> i;

	}

	inputFile.close();

	cout << "Populated adjacency list:\n" << endl;
	displayAdjList(adjList);

	int * * matrix;

	int ROWS = NUM_VER, COLS = NUM_VER;

	matrix = new int * [ROWS];

	for (int i = 0; i < ROWS; i++) {
		matrix[i] = new int [COLS];
	}


	for (int i = 0; i < ROWS; i++) {

		for (int j = 0; j < COLS; j++) {
			matrix[i][j] = 0;
		}

		list<int>::iterator ptr = adjList.at(i).neighbor.begin();

		while(ptr != adjList.at(i).neighbor.end()) {
			matrix[i][*ptr] = 1;
			ptr++;
		}

	}


	cout << "\nPopulated adjacency matrix:\n" << endl;
	displayMatrix(matrix, ROWS, COLS);

	cout << endl;

	dft (matrix, NUM_VER);

	bft(adjList, NUM_VER);



	for (int i = 0; i < ROWS; i++) {

		delete [] matrix[i];

	}

	cout << "Have a great day!" << endl;


	return 0;
}
