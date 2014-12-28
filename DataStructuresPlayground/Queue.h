#pragma once

template <class QueueElement>
class Queue
{
public:
	Queue();
	~Queue();

	void push(QueueElement *);
	QueueElement * pop();

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
};

template <class QueueElement>
Queue<QueueElement>::Queue()
{
	firstItem = NULL;
}

template <class QueueElement>
Queue<QueueElement>::~Queue()
{

}

template <class QueueElement>
void Queue<QueueElement>::push(QueueElement * element)
{
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

	return element;
}

template <class QueueElement>
Queue<QueueElement>::QueueItem::QueueItem()
{

}

template <class QueueElement>
Queue<QueueElement>::QueueItem::~QueueItem()
{

}
