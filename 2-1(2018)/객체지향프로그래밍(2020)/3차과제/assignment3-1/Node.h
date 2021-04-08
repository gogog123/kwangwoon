#include <iostream>
#include <cstring>
#include <string>
#include <atlstr.h>
using namespace std;
#pragma once

class Node
{
public:
	string data;
	int price;
	Node* next_Menu;
	Node* next_Category;
};

class List
{
private:
	int count;
	Node* head = new Node;

public:
	List()
	{
		head->next_Category = nullptr;
		head->next_Menu = nullptr;
		count = 0;
	}
	~List() {}
	void add(string data); //Add category
	void add(string data, string menu, int price); // Add menu, price 
	void print(); //print
	bool search_category(string data, int i);
	void search_menu(string data);
	void remove(string data);
};

void List::add(string data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->price = 0;
	newNode->next_Category = nullptr;
	newNode->next_Menu = nullptr;
	//Initial setting

	if (head->next_Category == nullptr)
		head->next_Category = newNode; //empty node.
	else
	{
		Node* temp = head;
		while (temp->next_Category != nullptr)
			temp = temp->next_Category; 
		temp->next_Category = newNode; //add end node.
	}
	count++;

} //Add end node
//Add category

void List::add(string category, string menu, int price)
{
	Node* newNode = new Node;
	newNode->data = menu;
	newNode->price = price;
	newNode->next_Category = nullptr;
	newNode->next_Menu = nullptr;
	//Initial setting

	Node* temp = head->next_Category; // first category

	char* ch_category = (char*)category.c_str();
	char* ch_temp;

	while (1)
	{
		ch_temp = (char*)(temp->data).c_str();
		if (stricmp(ch_temp, ch_category) == 0) //Case-insensitive
			break;
		else
			temp = temp->next_Category;
	} //Find the same category

	while (1)
	{
		if (temp->next_Menu == NULL)
		{
			temp->next_Menu = newNode;
			break;
		} //No menu
		else
		{
			if ((temp->next_Menu->price) > price)
			{
				newNode->next_Menu = temp->next_Menu;
				temp->next_Menu = newNode;
				break;
			} //Is greater than the price entered

			else if ((temp->next_Menu->price) == price)
			{
				char* ch_menu = (char*)menu.c_str();
				char* ch_temp_next = (char*)(temp->next_Menu->data).c_str(); //string->char*
				if (stricmp(ch_temp_next,ch_menu)==0) //Case-insensitive
				{
					cout << menu << " already exists!\n\n"; //Existing menu
					break;
				}
				else if (stricmp(ch_temp_next, ch_menu) > 0)
				{
					newNode->next_Menu = temp->next_Menu;
					temp->next_Menu = newNode; 
					// Insert the menu
					break;
				}
			}//Same as entered price

			temp = temp->next_Menu;
		}
	}
}//Add menu, price

void List::print()
{
	int check = 0; // Check if output
	Node* temp_category = head->next_Category;
	Node* temp_menu = head->next_Category;

	while(temp_category != NULL)
	{
		temp_menu = temp_category->next_Menu;

		if (temp_category->next_Menu == NULL) //If there is no menu
			break;
		else
		{
			cout << "===============" << temp_category->data << "===============" << endl << endl;
			while (temp_menu != NULL)
			{
				cout << temp_menu->data << " " << temp_menu->price << endl;
				temp_menu = temp_menu->next_Menu;
			}//Print menus
			check++;
		}
		temp_category = temp_category->next_Category;
		cout << endl;
	}
	if (check == 0)
		cout <<"The data does not exist" << endl << endl;
}

bool List::search_category(string data, int i)
{
	int check = 0;
	Node* cur = head->next_Category;
	while (cur != NULL)
	{
		Node* cur_menu = cur;
		char* ch_cur;
		char* ch_data;
		ch_cur = (char*)(cur->data).c_str(); //string->char* 
		ch_data = (char*)data.c_str();  //string->char*
		if (stricmp(ch_cur, ch_data) == 0) //Case-insensitive
		{
			if(i ==4)
				cout << data << endl;
			while (cur_menu->next_Menu != NULL)
			{
				if(i == 4)
					cout << cur_menu->next_Menu->data << " " << cur_menu->next_Menu->price << endl;
				cur_menu = cur_menu->next_Menu;
			} //category menu print
			check++;
		}
		cur = cur->next_Category; //move category
	}
	if (check == 0)
	{
		cout << "Do not have a category" << endl;
		return false;
	}
	cout << endl;
	return true;
}

void List::search_menu(string data)
{
	int check = 0;
	Node* cur = head->next_Category;

	while (cur != NULL)
	{
		Node* cur_menu = cur;
		char* ch_cur;
		char* ch_data;
		ch_data = (char*)data.c_str();  //string->char*
		while (cur_menu->next_Menu != NULL)
		{
			ch_cur = (char*)(cur_menu->next_Menu->data).c_str(); //string->char* 
			if (stricmp(ch_cur, ch_data) == 0)   //Case-insensitive
			{
				cout << cur_menu->next_Menu->data << " " << cur_menu->next_Menu->price << endl;
				check++;
			}
			cur_menu = cur_menu->next_Menu; //move menu
		}
		cur = cur->next_Category; //move category
	}
	if (check == 0) //Not output
		cout << "Do not have a menu" << endl; 
	
	cout << endl;

}

void List::remove(string data)
{
	int check = 0;
	Node* cur = head->next_Category;

	while (cur != NULL)
	{
		Node* cur_menu = cur->next_Menu;
		Node* prev_menu = cur;

		char* ch_cur;
		char* ch_data;
		ch_cur = (char*)(cur->next_Menu->data).c_str(); //string->char* 
		ch_data = (char*)data.c_str();  //string->char*

		while (prev_menu->next_Menu != NULL)
		{
			if (stricmp(ch_cur, ch_data) == 0) //Case-insensitive
			{
				prev_menu->next_Menu = cur_menu->next_Menu;
				delete cur_menu; // delete menu
				check++;
				break;
			}
			prev_menu = prev_menu->next_Menu;
			cur_menu = cur_menu->next_Menu; 
			//Reconnect back and forth
		}
		cur = cur->next_Category;
	}

	if (check != 0)
		cout << "Delete Success!" << endl; 
	else //Not output
		cout << "Delete Fail!" << endl;

	cout << endl;
}
