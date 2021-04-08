#include <iostream>
#include <string.h>
#include "Node.h"
using namespace std;

int main()
{
	int input_number;
	cout << "***********************************" << endl << "S T S A R T" << endl << "***********************************" << endl;

	List* subject = NULL;
	subject = new List();

	while (1)
	{
		cout << "1. Insert lecture at beginning" << endl;
		cout << "2. Insert lecture at last" << endl;
		cout << "3. Insert lecture at position" << endl;
		cout << "4. Delete lecture" << endl;
		cout << "5. Update lecture" << endl;
		cout << "6. Search lecture" << endl;
		cout << "7. Search professor" << endl;
		cout << "8. Search grade" << endl;
		cout << "9. Sort by grade in ascennding order" << endl;
		cout << "10. Display lecture list" << endl;
		cout << "11. Reverse lecture list" << endl;
		cout << "12. Exit" << endl;
		cout << "Input number : ";
		cin >> input_number;
		cin.ignore(); // to use getline
		
		switch (input_number)
		{
		case 1:
		{
			subject->insert_begginning();
			break;
		}
		case 2:
			subject->insert_last();
			break;
		case 3:
			subject->insert_position();
			break;
		case 4:
			subject->remove();
			break;
		case 5:
			subject->update();
			break;
		case 6:
			subject->search_lecture();
			break;
		case 7:
			subject->search_professor();
			break;
		case 8:
			subject->search_grade();
			break;
		case 9:
			subject->sort();
			break;
		case 10:
			subject->print();
			break;
		case 11:
			subject->reverse();
			break;
		case 12:

			return 0; //end

		default:
			cout << "input number 1~12" << endl; //wrong input
			return 0;
			break;
		

		} // end switch
		cout << "-----------------------------------" << endl;
	}
	return 0; // end
}
