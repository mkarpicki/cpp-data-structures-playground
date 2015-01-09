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
 global flag for hidding logs
 This is lame but for now this is not my
 main focus.
 @todo Probably I should create a wrapper "doLog" and have flag inside or overwrite << operator?
*****************************************/
bool doLog = true;


/**************************************** 
 * Stack 
*****************************************/

void stackWithIntegers()
{
	if (doLog == true)
	{
		std::cout << "*** stackWithIntegers ***\n";
	}

	Stack<int> * stack = new Stack<int>();

	bool isEmpty = false;

	std::array<int, 10> testArray = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	stack->pop();

	isEmpty = stack->isEmpty();

	for (int i = 0; i < testArray.size(); i++)
	{
		if (doLog == true)
		{
			std::cout << "push: " << testArray[i] << "\n";
		}
		stack->push(&testArray[i]);
	}

	isEmpty = stack->isEmpty();

	for (int i = 0; i < testArray.size(); i++)
	{
		int * value = stack->pop();

		if (doLog == true)
		{
			std::cout << "pop: " << *value << "\n";
		}
	}
	
	isEmpty = stack->isEmpty();
}

void stackWithChars()
{
	if (doLog == true)
	{
		std::cout << "*** stackWithChars ***\n";
	}

	Stack<char> * stack = new Stack<char>();

	bool isEmpty = false;

	std::array<char, 10> testArray = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };

	stack->pop();

	isEmpty = stack->isEmpty();

	for (int i = 0; i < testArray.size(); i++)
	{
		if (doLog == true)
		{
			std::cout << "push: " << testArray[i] << "\n";
		}
		stack->push(&testArray[i]);
	}

	isEmpty = stack->isEmpty();

	for (int i = 0; i < testArray.size(); i++)
	{
		char * value = stack->pop();

		if (doLog == true)
		{
			std::cout << "pop: " << *value << "\n";
		}
	}

	isEmpty = stack->isEmpty();
}

void stackWithCustomObjects()
{
	if (doLog == true)
	{
		std::cout << "*** stackWithCustomObjects ***\n";
	}

	Stack<SomeItem> * stack = new Stack<SomeItem>();

	bool isEmpty = false;

	stack->pop();

	isEmpty = stack->isEmpty();

	for (int i = 0; i < 10; i++)
	{
		SomeItem * someItem = new SomeItem(i);

		if (doLog == true)
		{
			std::cout << "push: " << someItem->someInt << ", " << someItem->someChar << "\n";
		}

		stack->push(someItem);
	}

	isEmpty = stack->isEmpty();

	for (int i = 0; i < 10; i++)
	{
		SomeItem * someItem = stack->pop();

		if (doLog == true)
		{
			std::cout << "pop: " << someItem->someInt << ", " << someItem->someChar << "\n";
		}
	}

	isEmpty = stack->isEmpty();
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
	if (doLog == true)
	{
		std::cout << "*** queueWithIntegers ***\n";
	}

	Queue<int> * queue = new Queue<int>();

	bool isEmpty = false;

	std::array<int, 10> testArray = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	queue->pop();

	isEmpty = queue->isEmpty();

	for (int i = 0; i < testArray.size(); i++)
	{
		if (doLog == true)
		{
			std::cout << "push: " << testArray[i] << "\n";
		}
		queue->push(&testArray[i]);
	}

	isEmpty = queue->isEmpty();

	for (int i = 0; i < testArray.size(); i++)
	{
		int * value = queue->pop();

		if (doLog == true)
		{
			std::cout << "pop: " << *value << "\n";
		}
	}

	isEmpty = queue->isEmpty();
}

void queueWithChars()
{
	if (doLog == true)
	{
		std::cout << "*** queueWithChars ***\n";
	}

	Queue<char> * queue = new Queue<char>();

	bool isEmpty = false;

	std::array<char, 10> testArray = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };

	queue->pop();

	isEmpty = queue->isEmpty();

	for (int i = 0; i < testArray.size(); i++)
	{
		if (doLog == true)
		{
			std::cout << "push: " << testArray[i] << "\n";
		}
		queue->push(&testArray[i]);
	}

	isEmpty = queue->isEmpty();

	for (int i = 0; i < testArray.size(); i++)
	{
		char * value = queue->pop();

		if (doLog == true)
		{
			std::cout << "pop: " << *value << "\n";
		}
	}

	isEmpty = queue->isEmpty();
}

void queueWithCustomObjects()
{
	if (doLog == true)
	{
		std::cout << "*** queueWithCustomObjects ***\n";
	}

	Queue<SomeItem> * queue = new Queue<SomeItem>();

	bool isEmpty = false;

	queue->pop();

	isEmpty = queue->isEmpty();

	for (int i = 0; i < 10; i++)
	{
		SomeItem * someItem = new SomeItem(i);

		if (doLog == true)
		{
			std::cout << "push: " << someItem->someInt << ", " << someItem->someChar << "\n";
		}
		queue->push(someItem);
	}

	isEmpty = queue->isEmpty();

	for (int i = 0; i < 10; i++)
	{
		SomeItem * someItem = queue->pop();

		if (doLog == true)
		{
			std::cout << "pop: " << someItem->someInt << ", " << someItem->someChar << "\n";
		}
	}

	isEmpty = queue->isEmpty();
}

void limitedQueueWithChars()
{
	if (doLog == true)
	{
		std::cout << "*** limitedQueueWithChars ***\n";
	}

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
	if (doLog == true)
	{
		std::cout << "*** playWithSequenceListInt ***\n";
	}

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
	if (doLog == true)
	{
		std::cout << "*** playWithBST ***\n";
	}

	BST<int> * bst = new BST<int>();
	int * foundData;

	std::array<int, 10> foo = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	// obtain a time-based seed:
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	shuffle(foo.begin(), foo.end(), std::default_random_engine(seed));


	for (int i = 0; i < foo.size(); i++)
	{
		int data = NULL;
		data = (foo[i] + 65);

		if (doLog == true)
		{
			std::cout << "insert key: " << foo[i] << " :: " << "data :" << data << "\n";
		}

		bst->insert(foo[i], &data);
	}

	for (int i = 0; i < foo.size() + 1; i++)
	{
		foundData = bst->search(i);

		if (doLog == true)
		{
			if (foundData == NULL)
			{
				std::cout << "key: " << i << " found : NULL\n";
			}
			else
			{
				std::cout << "key: " << i << " found : " << *foundData << "\n";
			}
		}
	}

	return;

}

int _tmain(int argc, _TCHAR* argv[])
{

	playWithStack();
	playWithQueue();

	playWithSequenceListInt();

	playWithBST();

	system("PAUSE");

	return 0;
}

