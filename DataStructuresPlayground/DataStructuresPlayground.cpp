// DataStructuresPlayground.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h";

int _tmain(int argc, _TCHAR* argv[])
{

	Stack * stack = new Stack();

	stack->push(1);
	stack->push(2);
	stack->push(3);

	stack->pop();
	stack->pop();
	stack->pop();


	return 0;
}

