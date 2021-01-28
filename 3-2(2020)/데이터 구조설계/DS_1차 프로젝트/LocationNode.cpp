#include "LocationNode.h"

LocationNode::LocationNode()
{
	Location = NULL;
	BST = NULL;
	pLeft = NULL;
	pRight = NULL; 
}//constructor

LocationNode::~LocationNode()
{
	Location = NULL;
	BST = NULL;
	pLeft = NULL;
	pRight = NULL;
}//destructor

char* LocationNode::GetLoc()
{
	return Location;
}

PatientBST* LocationNode::GetBST()
{
	return BST;
}

LocationNode* LocationNode::GetLeft()
{
	return pLeft;
}

LocationNode* LocationNode::GetRight()
{
	return pRight;
}

void LocationNode::SetBST(PatientBST* bst)
{
	BST = bst;
}

void LocationNode::SetLoc(char* location)
{
	Location = location;
}

void LocationNode::SetLeft(LocationNode* node)
{
	pLeft = node;
}

void LocationNode::SetRight(LocationNode* node)
{
	pRight = node;
}
