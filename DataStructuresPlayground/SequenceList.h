#pragma once

template <class SequenceListElement>
class SequenceList
{
public:
	SequenceList();
	~SequenceList();

	bool isEmpty();
	void insert(SequenceListElement *);
	bool delete((SequenceListElement *);

private:
	class SequenceListItem
	{
		SequenceListItem();
		~SequenceListItem();
	};
};

template <class SequenceListElement>
SequenceList<SequenceListElement>::SequenceList()
{
}

template <class SequenceListElement>
SequenceList<SequenceListElement>::~SequenceList()
{
}

template <class SequenceListElement>
bool SequenceList<SequenceListElement>::isEmpty()
{
	return true;
}

template <class SequenceListElement>
void SequenceList<SequenceListElement>::insert(SequenceListElement * element)
{
	return;
}

template <class SequenceListElement>
bool SequenceList<SequenceListElement>::delete(SequenceListElement * element)
{
	return true;
}