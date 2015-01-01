// DataStructuresPlayground.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include "Stack.h"
#include "Queue.h"

#include "SomeItem.h"


/**************************************** 
 * Stack 
*****************************************/

void stackWithIntegers()
{
	Stack<int> * stack = new Stack<int>();

	int one = 1, two = 2, three = 3;
	bool isEmpty = false;

	isEmpty = stack->isEmpty();

	stack->pop();

	stack->push(&one);
	stack->push(&two);
	stack->push(&three);

	isEmpty = stack->isEmpty();

	stack->pop();
	stack->pop();
	stack->pop();

	isEmpty = stack->isEmpty();
}

void stackWithChars()
{
	Stack<char> * stack = new Stack<char>();

	char a = 'a', b = 'b', c = 'c';

	stack->pop();

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

	stack->pop();

	stack->push(someItem1);
	stack->push(someItem2);
	stack->push(someItem3);

	stack->pop();
	stack->pop();
	stack->pop();
}

void limitedStackWithIntegers()
{
	Stack<int> * stack = new Stack<int>(2);

	int a = 123, b = 234, c = 345;

	bool wasPushed = false;

	wasPushed = stack->push(&a);
	wasPushed = stack->push(&b);
	wasPushed = stack->push(&c);

	stack->pop();
	wasPushed = stack->push(&c);
}

void playWithStack()
{
	stackWithIntegers();
	stackWithChars();
	stackWithCustomObjects();

	limitedStackWithIntegers();
}

/****************************************
 * Queue
*****************************************/

void queueWithIntegers()
{
	Queue<int> * queue = new Queue<int>();

	int a = 101, b = 202, c = 303;
	bool isEmpty = false;

	isEmpty = queue->isEmpty();

	queue->pop();

	queue->push(&a);
	queue->push(&b);
	queue->push(&c);

	isEmpty = queue->isEmpty();

	queue->pop();
	queue->pop();
	queue->pop();

	isEmpty = queue->isEmpty();
}

void queueWithChars()
{
	Queue<char> * queue = new Queue<char>();

	char a = 'a', b = 'b', c = 'c';

	queue->pop();

	queue->push(&a);
	queue->push(&b);
	queue->push(&c);

	queue->pop();
	queue->pop();
	queue->pop();
}

void queueWithCustomObjects()
{
	SomeItem * someItem1 = new SomeItem();
	SomeItem * someItem2 = new SomeItem();
	SomeItem * someItem3 = new SomeItem();

	Queue<SomeItem> * queue = new Queue<SomeItem>();

	queue->pop();

	queue->push(someItem1);
	queue->push(someItem2);
	queue->push(someItem3);

	queue->pop();
	queue->pop();
	queue->pop();
}

void limitedQueueWithChars()
{
	Queue<char> * queue = new Queue<char>(2);

	char a = 'z', b = 'y', c = 'x';

	bool wasPushed = false;

	wasPushed = queue->push(&a);
	wasPushed = queue->push(&b);
	wasPushed = queue->push(&c);

	queue->pop();

	wasPushed = queue->push(&c);

}

void playWithQueue()
{
	queueWithIntegers();
	queueWithChars();
	queueWithCustomObjects();

	limitedQueueWithChars();

}

int _tmain(int argc, _TCHAR* argv[])
{

	playWithStack();
	playWithQueue();

	//system("PAUSE");

	return 0;
}

