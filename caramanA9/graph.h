/*
 * graph.h
 *
 *  Created on: Nov 27, 2022
 *      Author: dancar
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <list>
#include <vector>
#include <queue>

using namespace std;

struct Vertex {

	int vertexValue;
	list <int> neighbor;

};

void displayAdjList(vector<Vertex> v) {

	for (int i = 0; i < v.size(); i++) {

		cout << "vertex number " << i << " value " << v.at(i).vertexValue << " neighbors-> ";
		list<int>::iterator ptr = v.at(i).neighbor.begin();

		while(ptr != v.at(i).neighbor.end()) {

			cout << *ptr << " ";

			ptr++;
		}

		cout << endl;


	}


}

void displayMatrix(int ** matrix, int ROWS, int COLS) {

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

}

void dftInternal(int ** adjMatrix, int vertex, bool * visTable, int numVert) {

	cout << vertex << " " << flush;
	visTable[vertex] = true;

	int currentNeighbor = -1;

	for (int i = 0; i < numVert && currentNeighbor == -1; i ++) {

		if (adjMatrix[vertex][i] == 1) {
			currentNeighbor = i;
		}
	}

	while (currentNeighbor != -1) {

		if (!visTable[currentNeighbor]) {
			dftInternal(adjMatrix, currentNeighbor, visTable, numVert);
		}

		int oldNeighbor = currentNeighbor;
		currentNeighbor = -1;

		for (int i = oldNeighbor + 1; i < numVert && currentNeighbor == -1; i ++) {

				if (adjMatrix[vertex][i] == 1) {
					currentNeighbor = i;
				}
		}

	}



}

void dft (int * * adjMatrix, int numVert) {

	cout << "Depth - first traversal:" << endl;

	bool visTable[numVert];
	for (int i = 0; i < numVert; i++) {
		visTable[i] = false;
	}



	for (int currentVertex = 0; currentVertex < numVert; currentVertex++) {

		if (!visTable[currentVertex]) {

			dftInternal(adjMatrix, currentVertex, visTable, numVert);

		}


	}

	cout << endl;



}

void bft (vector <Vertex> & adjList, int numVert) {

	cout << "Breadth-first traversal:" << endl;


	bool visTable[numVert];
	for (int i = 0; i < numVert; i++) {
		visTable[i] = false;
	}

	queue<int> q;
	list<int>::iterator ptr;

	for (int i = 0; i < numVert; i++) {

		if(!visTable[i]) {
			q.push(i);
			visTable[i] = true;
			cout << i << " ";

			while(!q.empty()) {

				int popped = q.front();
				q.pop();

				for (ptr = adjList.at(popped).neighbor.begin(); ptr != adjList.at(popped).neighbor.end(); ptr++) {
					int neighbor = *ptr;
					if (!visTable[neighbor]) {
						q.push(neighbor);
						visTable[neighbor] = true;
						cout << neighbor << " ";

					}
				}


			}




		}


	}

	cout << endl;


}












#endif /* GRAPH_H_ */
