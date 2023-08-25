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
	int balance = 0;
};


template <class T>
class BSTree {

public:

	bool searchR(T);
	void insertR(T);
	void udelete(T);
	void printRohitWithBF();
	void inOrderTraversal();
	void preOrderTraversal();
	void postOrderTraversal();

	void setallBF();
	T getLargestBF();

	BSTree();
private:
	int height();

	int heightInternal(Tnode<T> *);
	void udeleteInternal(Tnode<T> *&);
	void inOrderTraversal(Tnode<T> *);
	void preOrderTraversal(Tnode<T> *);
	void postOrderTraversal(Tnode <T> *);
	void printRohitWithBFLevel(Tnode<T> *, int, int, int, string &, const int);

	void setallBFInternal(Tnode<T> *);
	T getLargestBFInternal(Tnode<T> *);
	bool searchRInternal(Tnode<T> *, T);
	Tnode<T> * insertRInternal(Tnode<T> * &, T);

	Tnode<T> * tRoot;




};

template <class T>
BSTree<T>::BSTree() {

	tRoot = nullptr;

}

template <class T>
bool BSTree<T>::searchR(T i) {

	if (tRoot == nullptr) {

		return false;

	} else {

		return searchRInternal(tRoot, i);

	}

}


template <class T>
bool BSTree<T>::searchRInternal(Tnode<T> * p, T i) {

	if (p == nullptr) {
		return false;
	} else if (p -> nodeValue == i) {
		return true;
	} else {

		if (p -> nodeValue < i) {
			return searchRInternal(p -> Rchild, i);
		} else {
			return searchRInternal(p -> Lchild, i);
		}

	}

}

template<class T>
T BSTree<T>::getLargestBF() {

	return getLargestBFInternal(tRoot);

}

template<class T>
T BSTree<T>::getLargestBFInternal(Tnode<T> * p) {

	if (p != nullptr) {

		int leftLarge = getLargestBFInternal(p -> Lchild);
		int rightLarge = getLargestBFInternal(p -> Rchild);

		if (abs(p -> balance) > abs (leftLarge)) {
			leftLarge = p -> balance;
		} else if (abs(p -> balance) > abs (rightLarge)) {
			rightLarge = p -> balance;
		}

		if (abs(leftLarge) > abs(rightLarge)) {
			return leftLarge;
		} else {
			return rightLarge;
		}

	} else {
		return 0;
	}

}



template<class T>
void BSTree<T>::setallBF() {

	setallBFInternal(tRoot);

}

template<class T>
void BSTree<T>::setallBFInternal(Tnode<T> * p) {

	if (p != nullptr) {

		int lHeight = heightInternal(p -> Lchild);
		int rHeight = heightInternal(p -> Rchild);

		p -> balance = rHeight - lHeight;
		setallBFInternal(p -> Lchild);
		setallBFInternal(p -> Rchild);
		return;

	} else {
		return;
	}

}

template <class T>
void BSTree<T>::insertR(T i) {
	if (tRoot == nullptr) {

		Tnode<T> * alloc = new Tnode<T>;
		alloc -> nodeValue = i;
		alloc -> Lchild = nullptr;
		alloc -> Rchild = nullptr;
		tRoot = alloc;


	} else {

		tRoot = insertRInternal(tRoot, i);

	}



}

template <class T>
Tnode<T> * BSTree<T>::insertRInternal(Tnode<T> * & p, T i) {

	if (p -> nodeValue > i) {

		if (p -> Lchild == nullptr) {

			Tnode<T> * alloc = new Tnode<T>;
			p -> Lchild = alloc;
			alloc -> nodeValue = i;
			alloc -> Lchild = nullptr;
			alloc -> Rchild = nullptr;

		} else {
			p -> Lchild = insertRInternal(p -> Lchild, i);
		}

	} else {

		if (p -> nodeValue < i) {
			if (p -> Rchild == nullptr) {
				Tnode<T> * alloc = new Tnode<T>;
				p -> Rchild = alloc;
				alloc -> nodeValue = i;
				alloc -> Lchild = nullptr;
				alloc -> Rchild = nullptr;
			} else {
				p -> Rchild = insertRInternal(p -> Rchild, i);
			}
		}

	}
	setallBF();
	return p;

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
void BSTree<T>::udelete(T i) {

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
			setallBF();
			return;
		} else {
			if (current == tRoot) {
				udeleteInternal(tRoot);i
			} else if (trailing -> nodeValue > i) {
				udeleteInternal(trailing -> Lchild);
			} else {
				udeleteInternal(trailing -> Rchild);

			}
		}

		setallBF();

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
void BSTree<T>::printRohitWithBF(){		// pjh orig width=3 gap=5
	const int WIDTH = 7;		//must be greater than the max characters printed per node; for example, if printing 2 digit numbers, WIDTH should be >= 3
	const int GAP = 4;			//gap between each node
	int height = this->height();
	string lines[height+1];

	//generates a string for each level of the tree
	for(int i=1; i<=height+1; i++){
		string line;
		printRohitWithBFLevel(tRoot, i, i, height, line, WIDTH);
		lines[i-1] = line;
	}

	//removes the unnecessary spaces from the lines
	int space = 0;
	bool allSpace;
	for(unsigned int i=0; i<lines[0].length()-1; i++){	// pjh mod goes until length()-1 from length()
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
void BSTree<T>::printRohitWithBFLevel(Tnode<T>* node, int x, int level, int height, string& print, const int WIDTH){

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
		int bal = node->balance;				// start pjh mods
		string baln = to_string (bal);
		print+= "(";
		print+= baln;
		print+= ")";							// end pjh mods
		for(unsigned int i=0; i< (WIDTH-value.length()); i++)		//if the width of the node is less than WIDTH, prints spaces
			print+= " ";
		for(int i=0; i< WIDTH*(pow(2,height+1-level)-1); i++)		//space to print after node
			print+= " ";
	}
	else{
		printRohitWithBFLevel(node->Lchild, x-1, level, height, print, WIDTH);
		printRohitWithBFLevel(node->Rchild, x-1, level, height, print, WIDTH);

	}
}







#endif
