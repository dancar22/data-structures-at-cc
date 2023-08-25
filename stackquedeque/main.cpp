#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <deque> // double ended queue

using namespace std;

bool ll_function(const string &s) {
	if (s >= "3333") {
		return true;
	} else {
		return false;
	}
}

void displayDeque(deque<int> l) {
	for (deque<int>::iterator cantaloupe = l.begin(); cantaloupe != l.end(); cantaloupe++){
		cout << "list element " << *cantaloupe << endl;
	}
}

void displayList(list<int> l) {
	for (list<int>::iterator cantaloupe = l.begin(); cantaloupe != l.end(); cantaloupe++){
		cout << "list element " << *cantaloupe << endl;
	}
}


int main() {
	cout << "***list***" << endl;


	list<string> list1;
	list1.push_back("1111");
	list1.push_back("2222");
	list1.push_back("3333");
	list1.push_back("4444");

	//pass the function, remove_if will iterate through every element and remove if the ll_function returns true
	list1.remove_if(ll_function);

	//iterator to work with list1
	list<string>::iterator x;

	//points x to the beginning
	x = list1.begin();

	cout << *x << endl;



	//points x to the end
	x = list1.end();

	cout << "\n***queue***" << endl;

	// queue - new elements go into the back and when you take something out it always comes out of the front
	// first in first out
	queue <int> q1;
	q1.push(11);
	q1.push(22);
	q1.push(33);
	q1.push(44);


	int value = q1.front();

	cout << "value at the front of the queue: " << value << endl;
	q1.pop();

	//	stack - kind of looks like the queue, when you add something it goes to the top, when you take something out it comes out of the top
	// last in first out
	stack<int> stack1;
	stack1.push(11);
	stack1.push(12);
	stack1.push(13);
	stack1.push(14);
	stack1.push(15);

	//this one is 15 because its the last one added
	value = stack1.top();
	cout << "stack 1: " << value << endl;
	//remove the last one
	stack1.pop();
	//14 will be the next one because it was the second to last added
	value = stack1.top();
	cout << "stack 1: " << value << endl;

	// dequeue is like a queue but it has pushfront pushback and popfront and popback

	cout << "\n***dequeue***" << endl;
	deque<int> d1;
	d1.push_back(11);
	d1.push_front(15);
	d1.push_front(16);
	d1.push_back(12);
	d1.push_back(13);
	d1.push_front(17);
	d1.push_back(14);
	d1.push_front(18);
	d1.pop_back();
	d1.pop_front();
	displayDeque(d1);

	int i = 1000000;
	while (1) {
		d1.push_front(i);
	}


	return 0;
}
