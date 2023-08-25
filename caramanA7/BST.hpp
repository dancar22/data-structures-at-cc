#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <cmath>

using namespace std;

template <class T>
struct Tnode {
	T nodeValue;
	Tnode<T> * Lchild;
	Tnode<T> * Rchild;
};


template <class T>
class BSTree {

public:

	bool search(int);
	void insert(int);
	void udelete(int);
	void printRohit();
	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();
	BSTree();
private:
	int height();

	int heightInternal(Tnode<T> *);
	void udeleteInternal(Tnode<T> *&);
	void inOrderTraversal(Tnode<T> *);
	void preOrderTraversal(Tnode<T> *);
	void postOrderTraversal(Tnode <T> *);
	void printRohitLevel(Tnode<T> *, int, int, int, string &, const int);
	Tnode<T> * tRoot;


};

template <class T>
BSTree<T>::BSTree() {

	tRoot = nullptr;

}

template <class T>
void BSTree<T>::inOrderTraversal() {

	cout << "start of in order traversal: ";
	inOrderTraversal(tRoot);
	cout << endl;
	return;
}

template <class T>
void BSTree<T>::inOrderTraversal(Tnode<T> * current) {

	if (current != nullptr) {
		inOrderTraversal(current -> Lchild);
		cout << current -> nodeValue << ", ";
		inOrderTraversal(current -> Rchild);
	}

}

template <class T>
void BSTree<T>::preOrderTraversal() {

	cout << "start of pre order traversal: ";
	preOrderTraversal(tRoot);
	cout << endl;
	return;
}

template <class T>
void BSTree<T>::preOrderTraversal(Tnode<T> * current) {

	if (current != nullptr) {
		cout << current -> nodeValue << ", ";
		preOrderTraversal(current -> Lchild);
		preOrderTraversal(current -> Rchild);
	}

}

template <class T>
void BSTree<T>::postOrderTraversal() {

	cout << "start of post order traversal: ";
	postOrderTraversal(tRoot);
	cout << endl;
	return;
}

template <class T>
void BSTree<T>::postOrderTraversal(Tnode<T> * current) {

	if (current != nullptr) {
		postOrderTraversal(current -> Lchild);
		postOrderTraversal(current -> Rchild);

		cout << current -> nodeValue << ", ";
	}

}

template <class T>
void BSTree<T>::udelete(int i) {

	bool found = false;
	if (tRoot == nullptr) {
		return;
	} else {
		Tnode<T> * current = tRoot;
		Tnode<T> * trailing = tRoot;
		while (current != nullptr && !found) {
			if (current -> nodeValue == i) {
				found = true;
			} else {
				trailing = current;
				if (current -> nodeValue > i) {
					current = current -> Lchild;

				} else {
					current = current -> Rchild;
				}

			}
		}

		if (current == nullptr) {
			return;
		} else {
			if (current == tRoot) {
				udeleteInternal(tRoot);
			} else if (trailing -> nodeValue > i) {
				udeleteInternal(trailing -> Lchild);
			} else {
				udeleteInternal(trailing -> Rchild);

			}
		}


	}

}

template <class T>
void BSTree<T>::udeleteInternal(Tnode<T> *& deleter) {




	Tnode<T> * temp = deleter;

	if (deleter -> Lchild == nullptr && deleter -> Rchild == nullptr)  {
		delete deleter;
		deleter = nullptr;
	} else if (deleter -> Rchild == nullptr){
		deleter = deleter -> Lchild;
		delete temp;

	}	else if (deleter -> Lchild == nullptr){
		deleter = deleter -> Rchild;
		delete temp;

	} else {


		Tnode<T> * current = deleter -> Lchild;
		Tnode<T> * rightMostsParent = deleter -> Lchild;

		bool rightMost = false;
		if (current -> Rchild == nullptr) {
			rightMost = true;
		}
		while (current -> Rchild != nullptr) {
			current = current -> Rchild;
		}

		deleter -> nodeValue = current -> nodeValue;

		if (rightMost) {
			deleter -> Lchild = deleter -> Lchild -> Lchild;
		} else {

			while (rightMostsParent -> Rchild -> Rchild != nullptr) {
				rightMostsParent = rightMostsParent -> Rchild;
			}

			rightMostsParent -> Rchild = rightMostsParent -> Rchild -> Lchild;

		}

		delete current;

	}

}



template <class T>
bool BSTree<T>::search(int i) {

	if (tRoot == nullptr) {
		return false;
	} else {
		Tnode<T> * current = tRoot;
		while (current != nullptr) {
			if (current -> nodeValue == i) {
				return true;
			} else if (current -> nodeValue > i) {
				current = current -> Lchild;
			} else {
				current = current -> Rchild;

			}
		}
		return false;
	}
}


template <class T>
int BSTree<T>::height(){

	return heightInternal(tRoot);
}

template <class T>
int BSTree<T>::heightInternal(Tnode<T> * p) {

	if (p != nullptr) {
		int lh = heightInternal(p -> Lchild);
		int rh = heightInternal (p -> Rchild);
		if (lh > rh) {
			return lh + 1;
		} else {
			return rh + 1;
		}
	} else {
		return -1;
	}

	return 0;

}


template <class T>
void BSTree<T>::insert(int i) {

	Tnode<T> * temp = new Tnode<T>;
	temp -> nodeValue = i;
	temp -> Lchild = nullptr;
	temp -> Rchild = nullptr;

	if (tRoot == nullptr) {
		tRoot = temp;
	} else {
		Tnode<T> * current = tRoot;
		Tnode<T> * trailing = nullptr;

		while (current != nullptr) {
			trailing = current;
			if (current -> nodeValue == i) {
				return;
			} else if (current -> nodeValue > i) {
				current = current -> Lchild;
			} else {
				current = current -> Rchild;
			}

		}

		if (trailing -> nodeValue > i) {
			trailing -> Lchild = temp;
		} else {
			trailing -> Rchild = temp;
		}
	}



}

template <class T>
void BSTree<T>::printRohit(){
/* Created by Rohit Jaganathan for Professor Hrycewicz's CS 20 class on 11/27/2020
 *
 * Prints the tree vertically
 * First, a string is generated for each line. Because this results in very wide trees, the second part of the function makes it so that the space between each node is equal to GAP
 *
 * Preconditions:
 * none
 *
 * Postconditions:
 * tree has been printed
 *
 * Usage:
 *      treename.printRohit();		 treename is the name of a BinarySearchTree object
 *
 *      The BinarySearchTree class must have a tree root (pointer) named treeRoot
 *      A class or struct named Treenode must be used with the following members:
 *           Lchild - pointer to the left subtree
 *           Rchild - pointer to the right subtree
 *           nodeValue - an integer containing the node's key value
 *      When a subtree is null, the child pointer must contain nullptr
 */
	const int WIDTH = 3;		//must be greater than the max characters printed per node; for example, if printing 2 digit numbers, WIDTH should be >= 3
	const int GAP = 5;			//gap between each node
	int height = this->height();
	string lines[height+1];

	//generates a string for each level of the tree
	for(int i=1; i<=height+1; i++){
		string line;
		printRohitLevel(tRoot, i, i, height, line, WIDTH);
		lines[i-1] = line;
	}

	//removes the unnecessary spaces from the lines
	int space = 0;
	bool allSpace;
	for(unsigned int i=0; i<lines[0].length(); i++){
		allSpace = true;
		for(string line: lines){
			if(line.at(i) != ' '){
				allSpace = false;
			}
		}
		if(allSpace){		//every line has a space at this index
			space += 1;
		}
		else{
			if(space > GAP){		//the space is too long and must be reduced to GAP
				for(string& line: lines){
					line.erase(i-space, space-GAP);
				}
				i-= (space-GAP);
			}
			else if(space < GAP && space>0){		//the space is too small and must be expanded to GAP
				string spaces;
				for(int j=0; j< (GAP-space); j++){
					spaces += " ";
				}
				for(string& line: lines){
					line.insert(i-space, spaces);
				}
				i += (GAP-space);
			}
			space = 0;
		}
	}

	//prints out each line
	for(string line: lines){
		cout << line << endl << endl << endl;
	}
}

/* Generates a string for each level for the tree.
 * Recursively reaches the specified level
 * A multiple of WIDTH number of spaces is added before and after each node which is necessary so that everything is lined up correctly. The multiple is determined using powers of 2 based on the relation of level to height
 *
 * Preconditions:
 * node- the node currently being examined; starts with root node
 * x- starts as the level to print; is decreased with each recursion until it becomes one, which means we are at the right level or we reach a null node
 * level- the level to print; does not change with recursion
 * height- the height of the tree
 * print- the string to store the data in; passed by reference
 * WIDTH- the max number of characters of a printed node
 *
 * Postconditions:
 * print now contains the string with this level's nodes
 */
template <class T>
void BSTree<T>::printRohitLevel(Tnode<T>* node, int x, int level, int height, string& print, const int WIDTH){
	if(node == nullptr){		//this node is empty so generates enough spaces based on which level the node is located on in relation to the level that must be printed and the height of the tree
		for(int i=0; i< WIDTH*pow(2,height+1-level+x); i++)
			print+= " ";
	}
	else if(x == 1){		//the node is on the right level
		for(int i=0; i< WIDTH*(pow(2,height+1-level)); i++)		//space to print before node
			print+= " ";
		int val = node->nodeValue;
		string value = to_string(val);
		print+= value;
		for(unsigned int i=0; i< (WIDTH-value.length()); i++)		//if the width of the node is less than WIDTH, prints spaces
			print+= " ";
		for(int i=0; i< WIDTH*(pow(2,height+1-level)-1); i++)		//space to print after node
			print+= " ";
	}
	else{
		printRohitLevel(node->Lchild, x-1, level, height, print, WIDTH);
		printRohitLevel(node->Rchild, x-1, level, height, print, WIDTH);
	}
}







#endif
