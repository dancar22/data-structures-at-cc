/*
 * stack.h
 *
 *  Created on: Sep 19, 2022
 *      Author: dancar
 */

#ifndef STACK_H_
#define STACK_H_

#include "LL.h"
using namespace std;


class Stack {

private:

	int arraySize;
	int topElement;

	LL<int*> LLarrays;



public:

	Stack(int i = 16);
	void push(int);
	bool top(int & i);
	bool pop();
	void destroy();

};





#endif /* STACK_H_ */
