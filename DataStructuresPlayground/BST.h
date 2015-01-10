/*****************************************
* Example of Binary Search Tree
* Currently implemented for integers only
* 
* @todo - consider adding support for samy key?
*****************************************/
#pragma once

template <class BSTDataClass>
class BST
{
public:
	BST();
	~BST();

	void insert(int, BSTDataClass *);
	BSTDataClass * remove(int);
	BSTDataClass * search(int);
	bool isEmpty();

	int countLastSearchSteps();
	int countLastInsertSteps();

private:
	class Node
	{
	public:
		Node();
		Node(int, BSTDataClass *);
		~Node();

		Node * left;
		Node * right;
		int key;
		BSTDataClass * data;
	};

	Node * head;
	int lastSearchStepsNumber;
	int lastInsertStepsNumber;

	BSTDataClass * search(int, Node *);
	void insert(int, BSTDataClass *, Node **);
};

template <class BSTDataClass>
BST<BSTDataClass>::BST()
{
	head = NULL;
	lastSearchStepsNumber = 0;
	lastInsertStepsNumber = 0;
}

template <class BSTDataClass>
BST<BSTDataClass>::~BST()
{
	/*
	* @todo - go thru whole tree and release memory
	*/
}

template <class BSTDataClass>
bool BST<BSTDataClass>::isEmpty()
{
	return (head == NULL) ? true : false;
}

template <class BSTDataClass>
BSTDataClass * BST<BSTDataClass>::search(int key)
{
	lastSearchStepsNumber = 0;

	return search(key, head);
}

template <class BSTDataClass>
BSTDataClass * BST<BSTDataClass>::search(int key, Node * node)
{
	if (node == NULL)
	{
		return NULL;
	}

	lastSearchStepsNumber++;

	if (key == node->key)
	{
		return node->data;
	}
	else if (key < node->key)
	{
		return search(key, node->left);
	}
	else if (key > node->key)
	{
		return search(key, node->right);
	}

	return NULL;
}


template <class BSTDataClass>
void BST<BSTDataClass>::insert(int key, BSTDataClass * data)
{
	lastInsertStepsNumber = 0;
	insert(key, data, &head);
}

template <class BSTDataClass>
void BST<BSTDataClass>::insert(int key, BSTDataClass * data, Node ** node)
{
	lastInsertStepsNumber++;

	if (*node == NULL)
	{
		*node = new Node(key, data);
		return;
	}

	if ((*node)->key > key)
	{
		insert(key, data, &((*node)->left));
	}
	else if ((*node)->key < key)
	{
		insert(key, data, &((*node)->right));
	}

	return;

}

template <class BSTDataClass>
int BST<BSTDataClass>::countLastSearchSteps()
{
	return lastSearchStepsNumber;
}

template <class BSTDataClass>
int BST<BSTDataClass>::countLastInsertSteps()
{
	return lastInsertStepsNumber;
}

template <class BSTDataClass>
BST<BSTDataClass>::Node::Node()
{
	left = NULL;
	right = NULL;

}

template <class BSTDataClass>
BST<BSTDataClass>::Node::Node(int key, BSTDataClass * data)
{
	left = NULL;
	right = NULL;

	this->key = key;
	
	this->data = new BSTDataClass();
	*(this->data) = *data;

}

template <class BSTDataClass>
BST<BSTDataClass>::Node::~Node()
{
	left = NULL;
	right = NULL;

	key = NULL;
	delete data;
}