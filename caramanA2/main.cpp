#include <iostream>
#include "Student.h"
#include "LL.h"

using namespace std;


int main() {
// A2 main test pgm 3 - use for submission
	LL <Student> ll1;
	cout << "main: length of empty list - " << ll1.list_length() << endl;
	ll1.display_list();

	Student temp;
	temp.data = "aaaaa";
	temp.key = 12345;
	ll1.push_front(temp);
	temp.data = "bbbbb";
	temp.key = 23456;
	ll1.push_back(temp);
	temp.data = "before aaaaa";
	temp.key = 34567;
	ll1.push_front(temp);
	temp.data = "after bbbbb";
	temp.key = 45678;
	ll1.push_back(temp);
	cout << "main: length of list after 4 pushes - " << ll1.list_length() << endl;
	ll1.display_list();
	cout << endl;

	temp = ll1.search_list (23456);
	if (temp.key != 0)
		cout << "main: node with key 23456 found" << endl;
	else
		cout << "main: node with key 23456 not found - that's an error" << endl;

	temp = ll1.search_list (23457);
	if (temp.key != 0)
		cout << "main: node with key 23457 found - that's an error" << endl;
	else
		cout << "main: node with key 23457 not found" << endl;

	bool b;
	b = ll1.delete_node (45678);
	if (b)
		cout << "main: node with key 23456 deleted" << endl;
	else
		cout << "main: node with key 23456 not deleted - that's an error" << endl;

	cout << "main: length of list after delete - " << ll1.list_length() << endl;
	cout << "main: display of list after delete" << endl;
	ll1.display_list();

	ll1.destroy_list();
	cout << "main: length of list after destroy - " << ll1.list_length() << endl;
	cout << "main: display of list after destroy" << endl;
	ll1.display_list();
	cout << endl;

	return 0;
}







