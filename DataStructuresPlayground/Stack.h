#pragma once

template <class StackElement>
class Stack
{
public:
	Stack();
	~Stack();

	void push(StackElement *);
	StackElement * pop();

private:

	class StackItem {
	public:
		StackItem();
		StackItem(StackElement *);
		~StackItem();

		StackItem * previousItem;
		StackElement * value;
	};

	StackItem * lastItem;


};

template <class StackElement>
Stack<StackElement>::Stack()
{
	lastItem = NULL;
}

template <class StackElement>
Stack<StackElement>::~Stack()
{

}

template <class StackElement>
void Stack<StackElement>::push(StackElement * value)
{
	StackItem * newItem = new StackItem(value);


	if (lastItem != NULL)
	{
		newItem->previousItem = lastItem;
	}

	lastItem = newItem;

	return;
}

template <class StackElement>
StackElement * Stack<StackElement>::pop()
{
	if (lastItem == NULL)
	{
		return NULL;
	}

	StackElement * value = lastItem->value;
	StackItem * itemToDrop = lastItem;

	lastItem = lastItem->previousItem;

	delete itemToDrop;

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



