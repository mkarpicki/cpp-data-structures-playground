/**
* example of sequence list working on integers only
* insert new integer after lower value (to keep order)
* remove all found integers by value
*/
#pragma once
class SequenceListInt
{
public:
	SequenceListInt();
	~SequenceListInt();

	bool isEmpty();
	bool insert(int);
	int remove(int);

private:

	class SequenceListIntItem
	{
	public:
		SequenceListIntItem();
		~SequenceListIntItem();

		int value;
		SequenceListIntItem * next;
	};

	SequenceListIntItem * head;
};
