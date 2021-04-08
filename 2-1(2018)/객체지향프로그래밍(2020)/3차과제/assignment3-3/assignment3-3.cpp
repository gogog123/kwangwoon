#include<iostream>
#include<string>
#include<cstring>
#include "BSTNode.h"

using namespace std;

int main()
{
	int size;
	int arr[100];
	char* array = { 0, };

	cout << "Enter Input Size : ";
	cin >> size;
	cin.ignore();
	cout << "Enter a number : ";
	array = new char[100];
	cin.getline(array, 100);
	char* ptr = strtok(array, " ");
	int i = 0;
	while (ptr != NULL)
	{
		arr[i] = atoi(ptr);  //form integer
		ptr = strtok(NULL, " ");
		i++;
	}
	if (i < size) //less i than input size
	{
		cout << "input wrong" << endl;
		return 0;
	}
	cout << endl;

	BSTNode* input_node = NULL;
	input_node = new BSTNode();
	Queue* tree = NULL;
	tree = new Queue();

	for (int i = 0; i < size; i++)
	{
		input_node = new BSTNode();
		input_node->SetData(arr[i]);
		input_node->SetLeft(NULL);
		input_node->SetRight(NULL);
		input_node->SetNext(NULL); //create node
		if (tree->Push(input_node) == false)
		{
			cout << "error" << endl;
			return 0;
		}
	}

	int num;
	while (1)
	{
		cout << "1. Preorder" << endl;
		cout << "2. Inorder" << endl;
		cout << "3. Postorder" << endl;
		cout << "4. Exit" << endl;
		cout << "Select Number: ";
		cin >> num;
		cout << endl;

		switch (num)
		{
		case 1: //preorder
			tree->preorder(tree->Front());
			//tree->Pop(num);
			break;
		case 2: //inorder
			tree->inorder(tree->Front());
			break;
		case 3: //postorder
			tree->postorder(tree->Front());
			break;
		case 4://end
			return 0;
			break;
		default: //other
			cout << "select number 1~4" << endl;
			break;
		}
		cout << endl << endl;
	}

	return 0;
}