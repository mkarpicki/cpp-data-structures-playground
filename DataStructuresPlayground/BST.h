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
	BSTDataClass * search(int, Node *);
	void insert(int, BSTDataClass *, Node **);
};

template <class BSTDataClass>
BST<BSTDataClass>::BST()
{
	head = NULL;
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
	return search(key, head);
}

template <class BSTDataClass>
BSTDataClass * BST<BSTDataClass>::search(int key, Node * node)
{
	if (node == NULL)
	{
		return NULL;
	}

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
	insert(key, data, &head);
}

template <class BSTDataClass>
void BST<BSTDataClass>::insert(int key, BSTDataClass * data, Node ** node)
{
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