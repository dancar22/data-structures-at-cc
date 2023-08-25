/*
 * LL.h
 *
 *  Created on: Sep 2, 2022
 *      Author: dancar
 */

#ifndef LL_H_
#define LL_H_


#include <iostream>

using namespace std;


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
	bool push_back(const cont & s);
	int list_length ();
	cont& retrieve_front ();
	cont& retrieve_back ();
	void destroy_list();
	void push_back_helper(LLnode<cont> * & current, LLnode<cont> * newNode);
	int list_length_helper (LLnode<cont> * temp);
	void pop_back();
	void display_list();



};

template <class cont>
void LL<cont>::display_list() {

	if (llh == nullptr) {

		cout << "No contents to display" << endl;

	}

	LLnode<cont> * temp = llh;
	int i = 0;

	while(temp != nullptr) {

		cout << "node " << i << " address -> " << temp << " data -> " << temp -> theData << endl;
		i++;
		temp = temp -> fwdPtr;

	}

}

template <class cont>
LL<cont>::LL() {

	llh = nullptr;

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

	newNode -> theData = s;

	LLnode<cont> * temp = llh;
	llh = newNode;
	newNode -> fwdPtr = temp;

}

//template <class cont>
//bool LL<cont>::push_back(const cont & s) {
//
//	LLnode<cont> * newNode;
//	newNode = new LLnode<cont>;
//	newNode -> theData = s;
//
//	if (llh == nullptr) {
//		llh = newNode;
//		newNode -> fwdPtr = nullptr;
//		return true;
//	}
//
//	if (llh -> fwdPtr == nullptr) {
//
//		if (llh -> theData < s) {
//			llh -> fwdPtr = newNode;
//			newNode -> fwdPtr = nullptr;
//			return true;
//		} else if (llh -> theData > s){
//
//			newNode -> fwdPtr = llh;
//			llh = newNode;
//			return true;
//
//		} else {
//			return false;
//		}
//
//	}
//
//	if (llh -> theData < s) {
//		llh -> fwdPtr = newNode;
//		newNode -> fwdPtr = nullptr;
//		return true;
//	} else if (llh -> theData > s){
//
//		newNode -> fwdPtr = llh;
//		llh = newNode;
//		return true;
//
//	} else {
//		return false;
//	}
//
//
//	LLnode<cont> * temp = llh;
//
//	while (temp -> fwdPtr != nullptr && temp -> fwdPtr -> theData < s) {
//		temp = temp -> fwdPtr;
//	}
//
//
//	if (temp -> fwdPtr == nullptr) {
//
//		if (temp -> theData == s) {
//			return false;
//		}
//
// 		temp -> fwdPtr = newNode;
// 		newNode -> fwdPtr = nullptr;
// 		return true;
//
//	}
//
//	if (temp -> fwdPtr -> theData == s) {
//		return false;
//	}
//
//	temp -> fwdPtr = newNode;
//	newNode -> fwdPtr = temp -> fwdPtr;
//	return true;
//
//
//
//
//
//
//
//
//}

template <class cont>
bool LL<cont>::push_back(const cont & s) {


	LLnode<cont> * newNode;
	newNode = new LLnode<cont>;
	newNode -> theData = s;

	if (llh == nullptr) {
		llh = newNode;
		newNode -> fwdPtr = nullptr;
		return true;
	}

	if (llh -> fwdPtr == nullptr) {
		if (llh -> theData == s) {
			return false;
		}

		if (llh -> theData < s) {
			llh -> fwdPtr = newNode;
			newNode -> fwdPtr = nullptr;
			return true;
		} else {

			newNode -> fwdPtr = llh;
			llh = newNode;
			return true;

		}

	}

	if (llh -> theData == s || llh -> fwdPtr -> theData == s) {
		return false;
	}

	LLnode<cont> * current = llh -> fwdPtr;
	LLnode<cont> * next = current -> fwdPtr;

	if (next == nullptr) {

		if (llh -> theData == s || llh -> fwdPtr -> theData == s) {
			return false;
		}

		if (llh -> theData > s) {
			newNode -> fwdPtr = llh;
			llh = newNode;
			return true;
		}

		if (llh -> fwdPtr -> theData > s) {
			newNode -> fwdPtr = llh -> fwdPtr;
			llh -> fwdPtr = newNode;
			return true;
		}


		newNode -> fwdPtr = llh -> fwdPtr -> fwdPtr;
		llh -> fwdPtr -> fwdPtr = newNode;
		return true;


	}

	while (next -> fwdPtr != nullptr && next -> theData < newNode -> theData) {
		if (next -> theData == s) {
			return false;
		}

		current = next;
		next = next -> fwdPtr;

	}

	if (next -> theData == s) {
		return false;
	}

	if (next -> fwdPtr == nullptr) {

		if (next -> theData < newNode -> theData) {
			next -> fwdPtr = newNode;
			newNode -> fwdPtr = nullptr;
			return true;
		}

	}

	if (llh -> theData > s) {
		newNode -> fwdPtr = llh;
		llh = newNode;
		return true;
	}

	if (llh -> fwdPtr -> theData > s) {
		newNode -> fwdPtr = llh -> fwdPtr;
		llh -> fwdPtr = newNode;
		return true;
	}

	if (llh -> fwdPtr -> fwdPtr -> theData > s) {
		newNode -> fwdPtr = llh -> fwdPtr -> fwdPtr;
		llh -> fwdPtr -> fwdPtr = newNode;
		return true;
	}

	current -> fwdPtr = newNode;
	newNode -> fwdPtr = next;
	return true;

}

template <class cont>
void LL<cont>::pop_back() {

	if (llh == nullptr) {
		return;
	}

	if (llh -> fwdPtr == nullptr) {

		delete llh;
		llh = nullptr;
		return;

	}

	LLnode<cont> * temp;
	temp = llh;

	while ((temp -> fwdPtr) -> fwdPtr  != nullptr) {

		temp = temp-> fwdPtr;

	}

	delete temp -> fwdPtr;
	temp -> fwdPtr = nullptr;


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
cont& LL<cont>::retrieve_front () {

	if (llh == nullptr) {

		string s = "Unable to retrieve front. Linked List is empty.";
		throw s;

	}

	return llh -> theData;

}

template <class cont>
cont& LL<cont>::retrieve_back () {

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
