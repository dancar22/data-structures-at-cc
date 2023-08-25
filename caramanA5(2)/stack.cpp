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

	(LLarrays.back())[topElement] = i;
	topElement++;
	return;

}

bool Stack::top(int & i) {

	if (LLarrays.size() == 0 || (LLarrays.size() == 1 && topElement == 0)) {

		return false;

	} else {
		i = LLarrays.back()[topElement - 1];
		return true;

	}

}

void Stack::destroy() {

	while(LLarrays.size() != 0) {

		delete[] (LLarrays.back());
		LLarrays.pop_back();

	}

	topElement = arraySize;

}

bool Stack::pop() {

	if (LLarrays.size() == 0) {

		return false;

	} else if (topElement == 1) {

		delete[] (LLarrays.back());
		LLarrays.pop_back();
		topElement = arraySize;
		return true;
	} else {

		topElement--;
		return true;

	}

}
