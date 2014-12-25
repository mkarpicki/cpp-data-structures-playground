#include "stdafx.h"
#include "Stack.h"


Stack::Stack()
{
	lastItem = NULL;
}


Stack::~Stack()
{
}

void Stack::push(int value)
{
	StackItem * newItem = new StackItem(value);


	if (lastItem != NULL)
	{
		newItem->previousItem = lastItem;
	}

	lastItem = newItem;

	return;
}

int Stack::pop()
{
	if (lastItem == NULL)
	{
		return NULL;
	}

	int value = lastItem->value;
	StackItem * itemToDrop = lastItem;

	lastItem = lastItem->previousItem;

	delete itemToDrop;

	return value;
}

Stack::StackItem::StackItem(int val)
{
	value = val;
}


Stack::StackItem::~StackItem()
{
}