/**
* @readme
* because of problems with linkers and templating whole implementation is kept in header file instead of having it splitted between definition and implementation
*/
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
	/*
	if max size was defined during construction
	check if current size is not big enought to not allow pushing 
	new item
	*/
	if (maxSize > 0 && currentSize == maxSize)
	{
		return false;
	}

	/* create new item on stack with delivered value */
	StackItem * newItem = new StackItem(value);

	/* 
	if there was already last element (stack not empty
	point to it in new item's 'previous' field
	*/
	if (lastItem != NULL)
	{
		newItem->previousItem = lastItem;
	}

	/* set new added item to be kept as 'last' */
	lastItem = newItem;

	/* increate stack size */
	currentSize++;

	return true;
}

template <class StackElement>
bool Stack<StackElement>::isEmpty()
{
	/*return boolean depending if last item set already or not */
	return (lastItem == NULL) ? true : false;
}

template <class StackElement>
StackElement * Stack<StackElement>::pop()
{
	/* if last item not set (stack empty) return NULL */
	if (lastItem == NULL)
	{
		return NULL;
	}

	/* get value of last item on stack */
	StackElement * value = new StackElement();
	*value = *(lastItem->value);

	//release memory
	delete lastItem->value;

	/* 
	set prevoius item (kept in last) as new last item 
	if there would be only one element that is poped then it's previous is NULL
	so this will be new 'last' one then
	*/
	lastItem = lastItem->previousItem;

	/* decrease stack size */
	currentSize--;

	return value;
}

template <class StackElement>
Stack<StackElement>::StackItem::StackItem(StackElement * element)
{
	value = new StackElement();
	*value = *element;
}

template <class StackElement>
Stack<StackElement>::StackItem::~StackItem()
{
	delete value;
}



