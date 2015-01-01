#pragma once

template <class StackElement>
class Stack
{
public:
	Stack();
	Stack(int);
	~Stack();

	bool push(StackElement *);
	StackElement * pop();
	bool isEmpty();

private:

	class StackItem 
	{
	public:
		StackItem();
		StackItem(StackElement *);
		~StackItem();

		StackItem * previousItem;
		StackElement * value;
	};

	StackItem * lastItem;
	int currentSize;
	int maxSize;

};

template <class StackElement>
Stack<StackElement>::Stack()
{
	lastItem = NULL;
	currentSize = 0;
	maxSize = 0;
}

template <class StackElement>
Stack<StackElement>::Stack(int sizeDef)
{
	lastItem = NULL;
	currentSize = 0;
	maxSize = (sizeDef > 0) ? sizeDef : 0;
}

template <class StackElement>
Stack<StackElement>::~Stack()
{

}

template <class StackElement>
bool Stack<StackElement>::push(StackElement * value)
{

	if (maxSize > 0 && currentSize == maxSize)
	{
		return false;
	}

	StackItem * newItem = new StackItem(value);


	if (lastItem != NULL)
	{
		newItem->previousItem = lastItem;
	}

	lastItem = newItem;

	currentSize++;

	return true;
}

template <class StackElement>
bool Stack<StackElement>::isEmpty()
{
	return (lastItem == NULL) ? true : false;
}

template <class StackElement>
StackElement * Stack<StackElement>::pop()
{
	if (lastItem == NULL)
	{
		return NULL;
	}

	StackElement * value = lastItem->value;

	lastItem = lastItem->previousItem;

	currentSize--;

	return value;
}

template <class StackElement>
Stack<StackElement>::StackItem::StackItem(StackElement * val)
{
	value = val;
}

template <class StackElement>
Stack<StackElement>::StackItem::~StackItem()
{
	
}



