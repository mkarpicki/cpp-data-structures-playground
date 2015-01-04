#include "stdafx.h"
#include "SequenceListInt.h"


SequenceListInt::SequenceListInt()
{
	head = NULL;
}


SequenceListInt::~SequenceListInt()
{
	head = NULL;
}

bool SequenceListInt::isEmpty()
{
	return (head == NULL)? true: false;
}

bool SequenceListInt::insert(int value)
{

	SequenceListIntItem * newItem = new SequenceListIntItem();	
	SequenceListIntItem * previous = NULL;
	SequenceListIntItem * current = head;

	newItem->value = value;
	newItem->next = NULL;

	// list is empty?
	if (!current)
	{
		head = newItem;
		return true;
	}

	while (current)
	{
		if (current->value > value)
		{

			if (!previous)
			{
				//new element on head
				head = newItem;
			}
			else
			{
				previous->next = newItem;
			}

			newItem->next = current;
			return true;
		}
		previous = current;
		current = previous->next;

	}
	//new element at the end of the list
	previous->next = newItem;

	return true;
}

int SequenceListInt::remove(int value)
{
	int removed = 0;

	SequenceListIntItem * previous = NULL;
	SequenceListIntItem * current = head;

	if (!current)
	{
		//emty list
		return removed;
	}

	while (current)
	{
		if (current->value == value)
		{
			if (!previous)
			{
				head = current->next;
				previous = head;
			}
			else
			{
				previous->next = current->next;
			}

			removed++;
			delete	current;

			//check if last element was not removed now
			if (previous != NULL)
			{
				current = previous->next;
			}
			else
			{
				current = NULL;
			}
						
		}
		else
		{
			previous = current;
			current = previous->next;
		}

	}

	return removed;
}

SequenceListInt::SequenceListIntItem::SequenceListIntItem()
{

}


SequenceListInt::SequenceListIntItem::~SequenceListIntItem()
{

}