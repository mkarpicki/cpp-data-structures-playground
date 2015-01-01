#pragma once

template <class QueueElement>
class Queue
{
public:
	Queue();
	Queue(int);
	~Queue();

	bool push(QueueElement *);
	QueueElement * pop();
	bool isEmpty();

private:

	class QueueItem
	{
	public:
		QueueItem();
		~QueueItem();

		QueueElement * value;
		QueueItem * next;
	};

	QueueItem * firstItem;
	QueueItem * lastItem;

	int maxSize;
	int currentSize;
};

template <class QueueElement>
Queue<QueueElement>::Queue()
{
	firstItem = NULL;
	maxSize = 0;
	currentSize = 0;
}

template <class QueueElement>
Queue<QueueElement>::Queue(int sizeDef)
{
	firstItem = NULL;
	maxSize = (sizeDef > 0) ? sizeDef : 0;
	currentSize = 0;
}

template <class QueueElement>
Queue<QueueElement>::~Queue()
{

}

template <class QueueElement>
bool Queue<QueueElement>::push(QueueElement * element)
{
	if (maxSize > 0 && currentSize == maxSize)
	{
		return false;
	}

	QueueItem * newItem = new QueueItem();

	newItem->value = element;

	if (lastItem != NULL)
	{
		lastItem->next = newItem;	
	}

	if (firstItem == NULL)
	{
		firstItem = newItem;
	}

	lastItem = newItem;

	currentSize++;

	return true;
}

template <class QueueElement>
QueueElement * Queue<QueueElement>::pop()
{

	if (firstItem == NULL)
	{
		return NULL;
	}

	QueueElement * element = firstItem->value;

	firstItem = firstItem->next;

	currentSize--;

	return element;
}

template <class QueueElement>
bool Queue<QueueElement>::isEmpty()
{
	return (firstItem == NULL) ? true : false;
}

template <class QueueElement>
Queue<QueueElement>::QueueItem::QueueItem()
{

}

template <class QueueElement>
Queue<QueueElement>::QueueItem::~QueueItem()
{

}
