#pragma once
#include <iostream>
using namespace std;

class BSTNode
{
private:
	BSTNode* pLeft;
	BSTNode* pRight;
	BSTNode* pNext;
	int data;

public:
	BSTNode() { pLeft = NULL; pRight == NULL; pNext = NULL; data = 0; }
	BSTNode(int Data) { pLeft = NULL; pRight == NULL; pNext == NULL; data = Data; }
	~BSTNode() {}

	void SetLeft(BSTNode* Left) { pLeft = Left; }
	void SetRight(BSTNode* Right) { pRight = Right; }
	void SetNext(BSTNode* Next) { pNext = Next; }
	void SetData(int Data) { data = Data; }

	BSTNode* GetLeft() { return pLeft; }
	BSTNode* GetRight() { return pRight; }
	BSTNode* GetNext() { return pNext; }
	int GetData() { return data; }

};

class Queue
{
private:
	BSTNode* Head; //root node
	int size;

public:
	Queue() { size = 0; Head = NULL; }
	~Queue() {}

	bool IsEmpty()
	{
		if (size == 0) // No node
			return true;
		return false;
	} 

	bool Push(BSTNode* Node)
	{
		BSTNode* temp = Head;

		size++;
		if (Head == NULL)
		{
			Head = Node;
			return true;
		}
		while (1)
		{
			if (temp->GetData() > Node->GetData()) //Less than the key value
			{
				if (temp->GetLeft() == NULL)
				{
					temp->SetLeft(Node);
					break;
				}
				else
					temp = temp->GetLeft(); //Move left
			}
			else if (temp->GetData() < Node->GetData()) //greater than the key value
			{
				if (temp->GetRight() == NULL)
				{
					temp->SetRight(Node);
					break;
				}
				else
					temp = temp->GetRight(); //Move right
			}
			else //Not the same
				return false; 
		}
		return true;
	}

	void Pop(int n)
	{
	}

	void preorder(BSTNode* n) //root first visit
	{
		cout << n->GetData() << " "; //root first visit
		if (n->GetLeft() != NULL)
		{
			preorder(n->GetLeft()); //Move left
		}
		if (n->GetRight() != NULL)
		{
			preorder(n->GetRight()); //Move right
		}
	}// preorder

	void inorder(BSTNode* n) //Left tree first visit, after root
	{
		if (n->GetLeft() != NULL)
		{
			inorder(n->GetLeft()); //Move left
		}
		cout << n->GetData() << " ";
		if (n->GetRight() != NULL)
		{
			inorder(n->GetRight()); //Move right
		}
	}// inorder
	
	void postorder(BSTNode* n) //Left tree first visit, after right tree visit
	{
		if (n->GetLeft() != NULL)
		{
			postorder(n->GetLeft()); //Move left
		}
		if (n->GetRight() != NULL)
		{
			postorder(n->GetRight()); //Move right
		}
		cout << n->GetData() << " ";
	}// postorder

	BSTNode* Front()
	{
		BSTNode* temp = Head;
		return temp;
	}

};
