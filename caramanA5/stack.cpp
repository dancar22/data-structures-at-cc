#include "stack.h"
#include <list>
#include <iostream>


Stack::Stack(int i) {

	arraySize = i;
	int * allocator = new int[arraySize];
	LLarrays.push_back(allocator);
	topElement = 0;

}



void Stack::push(int i) {

	if (topElement == arraySize) {

		int * allocator = new int[arraySize];
		allocator[0] = i;
		LLarrays.push_back(allocator);
		topElement = 1;
		return;

	}

	(LLarrays.retrieve_back())[topElement] = i;
	topElement++;
	return;

}

bool Stack::top(int & i) {

	if (LLarrays.list_length() == 0 || (LLarrays.list_length() == 1 && topElement == 0)) {

		return false;

	} else {
		i = LLarrays.retrieve_back()[topElement - 1];
		return true;

	}

}

void Stack::destroy() {

	while(LLarrays.list_length() != 0) {

		delete[] (LLarrays.retrieve_back());
		LLarrays.pop_back();

	}

	topElement = arraySize;

}

bool Stack::pop() {

	if (LLarrays.list_length() == 0) {

		return false;

	} else if (topElement == 1) {

		delete[] (LLarrays.retrieve_back());
		LLarrays.pop_back();
		topElement = arraySize;
		return true;
	} else {

		topElement--;
		return true;

	}

}
