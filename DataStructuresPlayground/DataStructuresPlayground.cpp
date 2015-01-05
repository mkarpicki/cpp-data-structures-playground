// DataStructuresPlayground.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"

#include <iostream>
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

#include "Stack.h"
#include "Queue.h"
#include "SequenceListInt.h"
#include "BST.h"

#include "SomeItem.h"

using namespace std;

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


/****************************************
* Simple Sequence list based on integers
*****************************************/

void playWithSequenceListInt()
{
	SequenceListInt * list = new SequenceListInt();

	int removed = 0;

	bool isEmpty = false;

	isEmpty = list->isEmpty();

	list->insert(1);
	list->insert(2);
	list->insert(0);
	list->insert(3);
	list->insert(3);

	isEmpty = list->isEmpty();

	removed = list->remove(3);
	removed = list->remove(1);

	isEmpty = list->isEmpty();

	removed = list->remove(0);
	removed = list->remove(0);
	removed = list->remove(2);

	isEmpty = list->isEmpty();

	removed = list->remove(0);
}

/****************************************
* Simple BST implementation 
*****************************************/

void playWithBST()
{
	BST<char> * bst = new BST<char>();

	std::array<int, 10> foo = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// obtain a time-based seed:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	shuffle(foo.begin(), foo.end(), std::default_random_engine(seed));


	for (int i = 0; i < foo.size() - 1; i++)
	{
		std::cout << foo[i] << "\n";

		char data = foo[i];

		bst->insert(foo[i], &data);
	}

	return;

}

int _tmain(int argc, _TCHAR* argv[])
{

	playWithStack();
	playWithQueue();

	playWithSequenceListInt();

	playWithBST();

	//system("PAUSE");

	return 0;
}

