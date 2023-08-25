#include <iostream>

using namespace std;

/* Represents a singular students with a name and a student ID
 */
struct Student {

	string studentName;
	int studentID;

};

/* Represents a part of a linked list, is only capable of storing objects of type Student
 */
struct LLnode {

	LLnode * fwdPtr;
	Student theData;

};

/*	Adds an LLnode to the front of the linked list
 */
void push_front (LLnode * & llh, const Student & s);

/*	Adds an LLnode to the front of the linked list
 */
void push_back (LLnode * & llh, const Student & s);

/*	Outputs the data of every student that is stored inside of the given linked list
 */
void display_nodes(LLnode * & llh);

/* Returns the length of the given linked list
 */
int list_length (LLnode * & llh);

/* Returns the student object that is stored by the first LLnode in the provided linked list
 */
Student retrieve_front (LLnode * & llh);

/* Returns the student object that is stored by the first LLnode in the provided linked list
 */
Student retrieve_back (LLnode * & llh);


int main() {

	LLnode * theLLHeader1 = nullptr;
	Student temp;
	temp.studentName = "student1";
	temp.studentID = 11111;
	cout << "Main:  number of nodes in empty list " << list_length(theLLHeader1) << endl;
	cout << "Main:  contents of LL1 nodes" << endl;
	display_nodes(theLLHeader1);
	push_front (theLLHeader1, temp);
//	push_front (theLLHeader2, {"Charlie",78901});	// not all compilers support this
	cout << "Main:  number of nodes in list after 1 push - " << list_length(theLLHeader1) << endl;
	cout << "Main:  contents of list after 1 push " << endl;
	display_nodes(theLLHeader1);
	temp.studentName = "student2";
	temp.studentID = 22222;
	push_back (theLLHeader1, temp);
	temp.studentName = "student3";
	temp.studentID = 33333;
	push_front (theLLHeader1, temp);
	temp.studentName = "student4";
	temp.studentID = 44444;
	push_back (theLLHeader1, temp);
	cout << "Main:  number of nodes after 4 pushes - " << list_length(theLLHeader1) << endl;
	cout << "Main:  contents of list after 4 pushes " << endl;
	display_nodes (theLLHeader1);
	temp = retrieve_front(theLLHeader1);
	cout << "Main:  retrieve front: " << temp.studentName << " " << temp.studentID << endl;
	temp = retrieve_back(theLLHeader1);
	cout << "Main:  retrieve back: " << temp.studentName << " " << temp.studentID << endl;
	cout << endl;

	LLnode * theLLHeader2 = nullptr;
	temp.studentName = "Adam";
	temp.studentID = 15555;
	push_front (theLLHeader2, temp);
	temp.studentName = "Betty";
	temp.studentID = 25555;
	push_front (theLLHeader2, temp);
	temp.studentName = "Charlie";
	temp.studentID = 35555;
	push_front (theLLHeader2, temp);
	temp.studentName = "Donna";
	temp.studentID = 45555;
	push_back (theLLHeader2, temp);
	temp.studentName = "Earnie";
	temp.studentID = 55555;
	push_back (theLLHeader2, temp);
	temp.studentName = "Felicity";
	temp.studentID = 65555;
	push_back (theLLHeader2, temp);
	cout << "Main:  contents of LL2 nodes" << endl;
	display_nodes (theLLHeader2);

	return 0;
}

void push_front (LLnode * & llh, const Student & s) {

	LLnode * newNode;
	newNode = new LLnode;

	newNode -> theData.studentName = s.studentName;
	newNode -> theData.studentID = s.studentID;

	LLnode * temp = llh;
	llh = newNode;
	newNode -> fwdPtr = temp;

}

void push_back(LLnode * & llh, const Student & s) {

	LLnode * newNode;
	newNode = new LLnode;

	newNode -> fwdPtr = nullptr;
	newNode -> theData.studentName = s.studentName;
	newNode -> theData.studentID = s.studentID;

	LLnode * temp = llh;

	if (temp != nullptr) {

		while (temp -> fwdPtr != nullptr) {

			temp = temp -> fwdPtr;

		}

		temp -> fwdPtr = newNode;

	} else {

		llh = newNode;

	}


}


void display_nodes(LLnode * & llh) {

	if (llh == nullptr) {

		cout << "No contents to display" << endl;

	}

	LLnode * temp = llh;
	int i = 0;

	while(temp != nullptr) {

		cout << "node " << i << " address -> " << temp << " data -> " << temp -> theData.studentName << " " << temp -> theData.studentID << endl;
		i++;
		temp = temp -> fwdPtr;

	}

}

int list_length (LLnode * & llh) {

	LLnode * temp = llh;
	int counter = 0;

	while (temp != nullptr) {

		counter++;
		temp = temp -> fwdPtr;

	}

	return counter;

}

Student retrieve_front (LLnode * & llh) {

	if (llh == nullptr) {

		string s = "Unable to retrieve front. Linked List is empty.";
		throw s;

	}

	return llh -> theData;

}

Student retrieve_back (LLnode * & llh) {

	if (llh == nullptr) {

		string s = "Unable to retrieve back. Linked List is empty.";
		throw s;

	}

	LLnode * temp = llh;

	while (temp -> fwdPtr != nullptr) {

		temp = temp -> fwdPtr;

	}

	return temp -> theData;

}



