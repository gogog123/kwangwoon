#pragma once
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Node
{
public:
	Node* nextNode;
	Node* prevNode;
	char* name;
	char* professor;
	int grade;
	//node information
};

class List
{
private:
	int count;
	Node* head = new Node;
	Node* last = new Node;

public:
	List();
	~List();
	void print();
	void insert_begginning();
	void insert_last();
	void insert_position();
	void remove();
	void update();
	void search_lecture();
	void search_professor();
	void search_grade();
	void sort();
	void reverse();
};

List::List()
{
	head->nextNode = nullptr;
	head->prevNode = nullptr;
	count = 0;
	//value initial
}

List::~List()
{
}

void List::print()
{
	Node* temp = head;
	cout << "<Display lecture list>" << endl;
	for (int i = 0; i < count; i++)
	{
		temp = temp->nextNode;
		cout << "lecture name : " << temp->name << endl;
		cout << "lecture professor : " << temp->professor << endl;
		cout << "lecture grade : " << temp->grade << endl;
	}
	//Output information by the number of nodes
}

void List::insert_begginning()
{
	char* input_name = NULL;
	char* input_professor = NULL;
	int input_grade;
	cout << "<Insert lecture at beginning>" << endl;
	cout << "-> Enter the lecture name : ";
	input_name = new char[20];
	cin.getline(input_name, 20); //possible input spaces
	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		temp = temp->nextNode;
		if (_stricmp(temp->name, input_name) == 0)
		{
			cout << "중복된 입력" << endl;
			return;
		}
	} //Duplicate input

	cout << "-> Enter the lecture professor : ";
	input_professor = new char[20]; //malloc
	cin.getline(input_professor, 20);  //possible input spaces 
	cout << "-> Enter the lecture grade : ";
	cin >> input_grade;
	cin.ignore(); // to use getline

	Node* input = new Node;
	input->name = input_name;
	input->professor = input_professor;
	input->grade = input_grade;
	//make input node

	if (head->nextNode == NULL) //linked list make start
	{
		head->nextNode = input;
		last = input;
		input->nextNode = NULL;
		input->prevNode = NULL;
	} // Do not have a node

	else if (head->nextNode->nextNode == NULL)
	{
		input->nextNode = head->nextNode;
		input->prevNode = last;
		head->nextNode = input;
		last->nextNode = input;
		last->prevNode = input;
	}//when have one node
	else
	{
		input->nextNode = head->nextNode;
		input->prevNode = last;
		input->nextNode->prevNode = input;
		head->nextNode = input;
		last->nextNode = input;
	}
	count++;
}

void List::insert_last()
{
	char* input_name = NULL;
	char* input_professor = NULL;
	int input_grade;
	cout << "<Insert lecture at last>" << endl;
	cout << "-> Enter the lecture name : ";
	input_name = new char[20];
	cin.getline(input_name, 20); //possible input spaces
	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		temp = temp->nextNode;
		if (_stricmp(temp->name, input_name) == 0)
		{
			cout << "중복된 입력" << endl;
			return;
		}
	} //Duplicate input

	cout << "-> Enter the lecture professor : ";
	input_professor = new char[20]; //malloc
	cin.getline(input_professor, 20);  //possible input spaces 
	cout << "-> Enter the lecture grade : ";
	cin >> input_grade;
	cin.ignore(); // to use getline

	Node* input = new Node;
	input->name = input_name;
	input->professor = input_professor;
	input->grade = input_grade;
	//make input node

	if (head->nextNode == NULL) //linked list make start
	{
		head->nextNode = input;
		last = input;
		input->nextNode = NULL;
		input->prevNode = NULL;
	} // Do not have a node

	else if (head->nextNode->nextNode == NULL)
	{
		input->nextNode = head->nextNode;
		input->prevNode = last;
		last->nextNode = input;
		last->prevNode = input;
		last = input;

	}//when have one node
	else
	{
		input->nextNode = head->nextNode;
		input->prevNode = last;
		head->nextNode->nextNode = input;
		last->nextNode = input;
		last = input;
	}
	count++;
}

void List::insert_position()
{
	char* input_name = NULL;
	char* input_professor = NULL;
	int input_grade;
	int position;
	cout << "<Insert lecture at position>" << endl;
	cout << "Enter the position of lecture insert : ";
	cin >> position;
	cin.ignore(); // to use getline
	cout << "-> Enter the lecture name : ";
	input_name = new char[20];
	cin.getline(input_name, 20); //possible input spaces
	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		temp = temp->nextNode;
		if (_stricmp(temp->name, input_name) == 0)
		{
			cout << "중복된 입력" << endl;
			return;
		}
	} //Duplicate input

	cout << "-> Enter the lecture professor : ";
	input_professor = new char[20]; //malloc
	cin.getline(input_professor, 20);  //possible input spaces 
	cout << "-> Enter the lecture grade : ";
	cin >> input_grade;
	cin.ignore(); // to use getline

	Node* input = new Node;
	input->name = input_name;
	input->professor = input_professor;
	input->grade = input_grade;
	//make input node
	if (count + 1 < position)
	{
		cout << "fail insert" << endl;
		return;
	}
	
	Node* temp_position = head;
	for (int i = 1; i < position; i++)
	{
		temp_position = temp_position->nextNode;
	}

	if (head->nextNode == NULL) //linked list make start
	{
		head->nextNode = input;
		last = input;
		input->nextNode = nullptr;
		input->prevNode = nullptr;
	} // Do not have a node

	else if (head->nextNode->nextNode == NULL)
	{
		if (position == 1)
		{
			input->nextNode = head->nextNode;
			input->prevNode = last;
			head->nextNode = input;
			last->nextNode = input;
			last->prevNode = input;
		} //head->nextnode insert
		else
		{
			input->nextNode = head->nextNode;
			input->prevNode = last;
			last->nextNode = input;
			last->prevNode = input;
			last = input;
		}// last->nextnode insert

	}//when have one node
	else
	{
		if (position == 1)
		{
			head->nextNode = input;
		}
		else if (position == count)
		{
			last = input;
		}
		input->nextNode = temp_position->nextNode;
		input->prevNode = temp_position;
		temp_position->nextNode->prevNode = input;
		temp_position->nextNode = input;
	}
	count++;
}

void List::remove()
{
	int position = 0; //Location deleted
	char* remove_name; //Name to be deleted

	cout << "<Delete lecture>" << endl;
	cout << "Enter the lecture of lecture Delete : ";
	remove_name = new char[20];
	cin.getline(remove_name, 20); //possible input spaces
	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		temp = temp->nextNode;
		if (_stricmp(temp->name, remove_name) == 0)
		{
			position = i + 1; //Location deleted
			break;
		}
		if (count - 1 == i)
		{
			cout << "일치하는 name이 없습니다. " << endl;
			return;
		}
	}
	if (position == 1)
		head->nextNode = temp->nextNode;
	if (position == count)
		last = temp->prevNode;
	(temp->nextNode)->prevNode = temp->prevNode; 
	(temp->prevNode)->nextNode = temp->nextNode; //temp = to be delete node
	//Linking the frontand back nodes to be deleted
	count--;
	delete temp;
	cout << "**" << remove_name << " has been deleted from position " << position << "**" << endl;

}

void List::update()
{
	char* prev_update;
	char* update_name;
	char* update_professor;
	int update_grade;

	cout << "<Update lecure>" << endl;
	cout << "-> Enter the lecture name : ";
	prev_update = new char[20];
	cin.getline(prev_update, 20); //possible input spaces

	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		temp = temp->nextNode;
		if (_stricmp(temp->name, prev_update) == 0)
			break;
		if (i == count - 1)
		{
			cout << "No information to update" << endl; // no information
			return;
		}
	} //find information to update

	cout << "-> Enter the new lecture name : ";
	update_name = new char[20];
	cin.getline(update_name, 20);
	cout << "-> Enter the new lecture professor : ";
	update_professor = new char[20]; //malloc
	cin.getline(update_professor, 20);  //possible input spaces 
	cout << "-> Enter the new lecture grade : ";
	cin >> update_grade;
	cin.ignore(); // to use getline
	
	temp->name = update_name;
	temp->professor = update_professor;
	temp->grade = update_grade;
	//information update
}

void List::search_lecture()
{
	char* search_name; //name to find
	cout << "<Search lecture>" << endl;
	cout << "-> Enter the lecture name you want to search : ";
	search_name = new char[20];
	cin.getline(search_name, 20);

	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		temp = temp->nextNode;
		if (_stricmp(temp->name, search_name) == 0) //Case - insensitive
		{
			cout << "*At position " << i + 1 << "*" << endl; //Location deleted
			cout << "lecture name: " << temp->name << endl;
			cout << "lecture professor: " << temp->professor << endl;
			cout << "lecture grade: " << temp->grade << endl;
			break;
		}

		if (i == count - 1)
			cout << "No information" << endl;
	}
}

void List::search_professor()
{
	int check = 0;
	char* search_professor;
	cout << "<Search professor>" << endl;
	cout << "-> Enter the professor name you want to search : ";
	search_professor = new char[20];
	cin.getline(search_professor, 20);

	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		temp = temp->nextNode; //Move node
		if (_stricmp(temp->professor, search_professor) == 0) //Case - insensitive
		{
			cout << "*At position " << i + 1 << "*" << endl;
			cout << "lecture name: " << temp->name << endl;
			cout << "lecture professor: " << temp->professor << endl;
			cout << "lecture grade: " << temp->grade << endl;
			check = 1; //Check if output
		}
		if (i == (count - 1) && check == 0)
			cout << "No information" << endl;
	}
}

void List::search_grade()
{
	int check = 0;
	int search_grade;
	cout << "<Search grade>" << endl;
	cout << "-> Enter the grade you want to search : ";
	cin >> search_grade;
	cin.ignore();

	Node* temp = head;
	for (int i = 0; i < count; i++)
	{
		temp = temp->nextNode; // Move node
		if (temp->grade == search_grade) //Same grade
		{
			cout << "*At position " << i + 1 << "*" << endl; //search position
			cout << "lecture name: " << temp->name << endl;
			cout << "lecture professor: " << temp->professor << endl;
			cout << "lecture grade: " << temp->grade << endl;
			check = 1; //Check if output
		}
		if (i = (count - 1) && check == 0)
			cout << "No information" << endl;
	}
}

void List::sort()
{
	
	Node* temp = new Node;
	Node* temp_i = head;
	Node* temp_j = head->nextNode;
	Node* min = head->nextNode;

	for (int i = 0; i < count; i++)
	{
		temp_i = temp_i->nextNode; // Move front node, Small node is located
		temp_j = temp_i;
		min = temp_i;
		for (int j = i; j < count-1; j++)
		{
			temp_j = temp_j->nextNode; // Move second node
			if (min->grade >= temp_j->grade)
			{
				if (min->grade == temp_j->grade)
				{
					if (_stricmp(min->name, temp_j->name) < 0) //min->name < temp->name
						continue; 
				}
				min = temp_j;
			}
		}
		temp->name = min->name;
		temp->professor = min->professor;
		temp->grade = min->grade;
		min->name = temp_i->name;
		min->professor = temp_i->professor;
		min->grade = temp_i->grade;
		temp_i->name = temp->name;
		temp_i->professor = temp->professor;
		temp_i->grade = temp->grade;
		//swap, name professor grade

	} //select sorting
	

	cout << "<Sort by grade in ascennding order>" << endl;
}

void List::reverse()
{
	Node* temp = new Node;
	Node* reverse_node = head->nextNode;
	for (int i = 0; i < count; i++)
	{
		temp = reverse_node->nextNode;
		reverse_node->nextNode = reverse_node->prevNode;
		reverse_node->prevNode = temp;
		//swap nextNode, preNode; 
		reverse_node = reverse_node->prevNode; //move nextNode;
	}
	head->nextNode = reverse_node->nextNode;
	last = reverse_node;
	//change value head->nextNode, last

	cout << "<Reverse lecture list>" << endl;
	cout << "** The product list has been reversed**" << endl;
}