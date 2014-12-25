// DataStructuresPlayground.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "Stack.h"


int _tmain(int argc, _TCHAR* argv[])
{

	Stack<int> * stack = new Stack<int>();
	Stack<char> * stack2 = new Stack<char>();

	stack->push(1);
	stack->push(2);
	stack->push(3);

	stack->pop();
	stack->pop();
	stack->pop();

	stack2->push('a');
	stack2->push('b');
	stack2->push('c');

	stack2->pop();
	stack2->pop();
	stack2->pop();

	//system("PAUSE");

	return 0;
}

