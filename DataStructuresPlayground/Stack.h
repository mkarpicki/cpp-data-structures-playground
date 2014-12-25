#pragma once

class Stack
{
public:
	Stack();
	~Stack();

	void push(int);
	int pop();

private:

	class StackItem {
	public:
		StackItem();
		StackItem(int);
		~StackItem();

		StackItem * previousItem;
		int value;
	};

	StackItem * lastItem;

};



