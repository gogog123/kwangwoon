#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "Node.h"

using namespace std;

int main()
{
	ifstream fin("input.txt");

	if (!fin.is_open())
	{
		cout << "No, file!" << endl;
		return 0;
	}

	List cafe;
	
	cafe.add("COFFEE");
	cafe.add("SMOOTHIE");
	cafe.add("TEA");
	cafe.add("ADE");
	cafe.add("DESSERT");

	int num;
	char* category_add = 0;
	char* menu_add = 0;
	char* price_add = 0;
	char category_search[20] = { 0, };
	char category_menu[20] = { 0, };
	char delete_menu[20] = { 0, };

	while (1)
	{
		cout << "1. LOAD" << endl;
		cout << "2. PRINT" << endl;
		cout << "3. INSERT" << endl;
		cout << "4. Category SEARCH" << endl;
		cout << "5. Menu SEARCH" << endl;
		cout << "6. DELETE" << endl;
		cout << "7. End of Program!" << endl;
		cout << "Select Number : ";
		cin >> num;
		cin.ignore(); //to use getline
		cout << endl;

		switch (num)
		{
		case 1:
		{
			char str[100];
			char* category;
			char* menu;
			char* price_s;
			int price;

			for (int i = 0; i < 100; i++)
			{
				if (!fin.eof())
				{
					fin.getline(str, 100);
					if (i == 0)
						continue; // except first line 
				}
				else
					break;

				category = strtok(str, "	");
				menu = strtok(NULL, "	");
				price_s = strtok(NULL, "	"); //Cut by tab
				if (price_s != NULL)
					price = atoi(price_s); //char -> int change
				else
				{
					cout << menu << " invalid input!\n\n";
					continue;
				}//Wrong input
				cafe.add(category, menu, price); //Add to list
			}

			cout << "LOAD Success!\n" << endl; //load success
			fin.close();
		}
			break;

		case 2:
			cafe.print(); //print list
			break;

		case 3:
			cout << "Enter Category, Menu and Price :" << endl;

			char adder[100];
			cin.getline(adder, 100);

			category_add = strtok(adder, " ");
			menu_add = strtok(NULL, " ");
			price_add = strtok(NULL, "\n");

			if (cafe.search_category(category_add, num) == false)
			{
				cafe.add(category_add);
			} //Add category, when no category

			if (category_add != NULL && menu_add != NULL && price_add != NULL)
			{
				cafe.add(category_add, menu_add, atoi(price_add));
				cout << "Insert Success!" << endl << endl;
			}
			else
			{
				cout << "error input!" << endl;
				break;
			}
			break;

		case 4:
			cout << "Enter Cateory which you want to find : ";
			cin >> category_search;

			cafe.search_category(category_search, num);

			break;

		case 5:
			cout << "Enter Menu which you want to find : ";
			cin >> category_menu;
			
			cafe.search_menu(category_menu);

			break;


		case 6:
			cout << "Enter Menu which you want to delete : ";
			cin >> delete_menu;

			cafe.remove(delete_menu);
			break;
			
		case 7:
			return 0;

		default:
			cout << "select 1~7\n\n";
			break;
		}

	}
	
	return 0;
}