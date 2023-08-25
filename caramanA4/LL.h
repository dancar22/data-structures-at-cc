/*
 * LL.h
 *
 *  Created on: Sep 2, 2022
 *      Author: dancar
 */

#ifndef LL_H_
#define LL_H_
#include "Student.h"

using namespace std;

#include <iostream>

/*	Templated long list node to be used by the long list class to store data.
 *  Stored data has to have a variable of type int called key and a variable of
 *  type string called data.
 */
template <class cont>
struct LLnode {

	LLnode * fwdPtr;
	cont theData;

};

/*	Templated long list class. Stores data using a long list node.
 * 	Stored data has to have a variable of type int called key and a variable of
 *  type string called data. Has functions in order to process said data
 */
template <class cont>
class LL {

private:

	LLnode<cont> * llh;

public:

	LL();
	void push_front (const cont & s);
	void push_back(const cont & s);
	void display_list();
	int list_length ();
	cont retrieve_front ();
	cont retrieve_back ();
	void destroy_list();
	cont search_list(int);
	bool delete_node(int);
	void push_back_helper(LLnode<cont> * & current, LLnode<cont> * newNode);
	int list_length_helper (LLnode<cont> * temp);
	bool delete_node_helper(LLnode<cont> * & current, int i);



};

template <class cont>
LL<cont>::LL() {

	llh = nullptr;

}

template <class cont>
bool LL<cont>::delete_node(int i) {

	return delete_node_helper(llh, i);

}

template <class cont>
bool LL<cont>::delete_node_helper(LLnode<cont> * & current, int i) {

	if (current == nullptr) {
		return false;
	}
	if (current -> theData.key == i) {

		LLnode<cont> * temp = current -> fwdPtr;
		delete current;
		current = temp;
		return true;

	}


	return delete_node_helper(current -> fwdPtr, i);


}

template <class cont>
cont LL<cont>::search_list(int i) {

	bool found = false;
	LLnode<cont> * temp;
	temp = llh;

	while (temp != nullptr && !found) {

		if (temp->theData.key == i) {

			found = true;

		} else {

			temp = temp -> fwdPtr;

		}

	}

	if (found) {

		return temp -> theData;

	} else {

		cont empty;
		empty.data = "";
		empty.key = 0;
		return empty;

	}


}

template <class cont>
void LL<cont>::destroy_list() {

	if (llh == nullptr) {
		return;
	}

	LLnode<cont> * temp;
	temp = llh;
	llh = temp -> fwdPtr;
	delete temp;
	destroy_list();

}


template <class cont>
void LL<cont>::push_front (const cont & s) {

	LLnode<cont> * newNode;
	newNode = new LLnode<cont>;

	newNode -> theData.data = s.data;
	newNode -> theData.key = s.key;

	LLnode<cont> * temp = llh;
	llh = newNode;
	newNode -> fwdPtr = temp;

}

template <class cont>
void LL<cont>::push_back(const cont & s) {

	LLnode<cont> * newNode;
	newNode = new LLnode<cont>;

	newNode -> fwdPtr = nullptr;
	newNode -> theData.data = s.data;
	newNode -> theData.key = s.key;

	push_back_helper(llh, newNode);

}

template <class cont>
void LL<cont>::push_back_helper(LLnode<cont> * & current, LLnode<cont> * newNode) {

	if (current == nullptr) {
		current = newNode;
		return;
	}

	push_back_helper(current -> fwdPtr, newNode);

}

template <class cont>
void LL<cont>::display_list() {

	if (llh == nullptr) {

		cout << "No contents to display" << endl;

	}

	LLnode<cont> * temp = llh;
	int i = 0;

	while(temp != nullptr) {

		cout << "node " << i << " address -> " << temp << " data -> " << temp -> theData.data << " " << temp -> theData.key << endl;
		i++;
		temp = temp -> fwdPtr;

	}

}

template <class cont>
int LL<cont>::list_length () {

	return list_length_helper(llh);

}

template <class cont>
int LL<cont>::list_length_helper (LLnode<cont> * temp) {

	if (temp == nullptr) {
		return 0;
	}

	return 1 + list_length_helper(temp -> fwdPtr);

}

template <class cont>
cont LL<cont>::retrieve_front () {

	if (llh == nullptr) {

		string s = "Unable to retrieve front. Linked List is empty.";
		throw s;

	}

	return llh -> theData;

}

template <class cont>
cont LL<cont>::retrieve_back () {

	if (llh == nullptr) {

		string s = "Unable to retrieve back. Linked List is empty.";
		throw s;

	}

	LLnode<cont> * temp = llh;

	while (temp -> fwdPtr != nullptr) {

		temp = temp -> fwdPtr;

	}

	return temp -> theData;

}



#endif /* LL_H_ */
