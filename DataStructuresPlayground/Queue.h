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
		QueueItem(QueueElement *);
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
	while (!isEmpty())
	{
		pop();
	}
}

template <class QueueElement>
bool Queue<QueueElement>::push(QueueElement * element)
{
	/* check if there was max size defined (during construction)
	* if so check if current size is not big enough before adding new item
	*/
	if (maxSize > 0 && currentSize == maxSize)
	{
		return false;
	}

	/* create new item with delivered value */
	QueueItem * newItem = new QueueItem(element);

	/* if there was last item already (not empty case)
	* point it's next value to new item
	*/
	if (lastItem != NULL)
	{
		lastItem->next = newItem;	
	}

	/* if queue was empty 
	* remember new item as fisrt
	*/
	if (firstItem == NULL)
	{
		firstItem = newItem;
	}

	/* remember new element as last one */
	lastItem = newItem;

	/* increment size of queue */
	currentSize++;

	return true;
}

template <class QueueElement>
QueueElement * Queue<QueueElement>::pop()
{
	/* if queue is empty, return */
	if (firstItem == NULL)
	{
		return NULL;
	}

	/* get value of first item */
	QueueElement * element = new QueueElement(); 
	*element = *(firstItem->value);

	QueueItem * next = firstItem->next;

	delete firstItem;

	/* remember next one as new first item*/
	firstItem = next;

	/* decrease size */
	currentSize--;

	/* return value kept in element that was first */
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
Queue<QueueElement>::QueueItem::QueueItem(QueueElement * element)
{
	value = new QueueElement();
	*value = *element;
}


template <class QueueElement>
Queue<QueueElement>::QueueItem::~QueueItem()
{
	delete value;
}
