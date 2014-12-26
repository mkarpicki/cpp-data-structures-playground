// DataStructuresPlayground.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "Stack.h"

#include "SomeItem.h"

void stackWithIntegers()
{
	Stack<int> * stack = new Stack<int>();

	int one = 1, two = 2, three = 3;

	stack->push(&one);
	stack->push(&two);
	stack->push(&three);

	stack->pop();
	stack->pop();
	stack->pop();
}

void stackWithChars()
{
	Stack<char> * stack = new Stack<char>();

	char a = 'a', b = 'b', c = 'c';

	stack->push(&a);
	stack->push(&b);
	stack->push(&c);

	stack->pop();
	stack->pop();
	stack->pop();
}
void stackWithCustomObjects()
{
	SomeItem * someItem1 = new SomeItem();
	SomeItem * someItem2 = new SomeItem();
	SomeItem * someItem3 = new SomeItem();

	Stack<SomeItem> * stack = new Stack<SomeItem>();

	stack->push(someItem1);
	stack->push(someItem2);
	stack->push(someItem3);

	stack->pop();
	stack->pop();
	stack->pop();
}

void playWithStack()
{
	stackWithIntegers();
	stackWithChars();
	stackWithCustomObjects();
}

int _tmain(int argc, _TCHAR* argv[])
{

	playWithStack();

	//system("PAUSE");

	return 0;
}

