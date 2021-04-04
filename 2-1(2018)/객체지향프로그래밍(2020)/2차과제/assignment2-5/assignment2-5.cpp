#include <iostream>
#include "PatientInfo.h"
using namespace std;

int main()
{
	char* name = NULL;
	char* address = NULL;
	int rn = 0;
	int pn = 0;

	PatientInfo* p1 = NULL, * p2 = NULL, * p3 = NULL, * p4 = NULL;

	for (int i = 0; i < 4; i++)
	{
		cout << "Name: ";
		name = new char[10]; //dynamic allocation
		cin >> name;
		cout << "Address: ";
		address = new char[10];
		cin >> address;
		cout << "Registration Number: ";
		cin >> rn;
		cout << "Phone Number: ";
		cin >> pn;

		if (i == 0)
			p1 = new PatientInfo(name, address, rn, pn); // class dynamic allocation
		else if (i == 1)
			p2 = new PatientInfo(name, address, rn, pn);
		else if (i == 2)
			p3 = new PatientInfo(name, address, rn, pn);
		else
			p4 = new PatientInfo(name, address, rn, pn);
		cout << endl;
	}

	cout << p1->getName() << endl << p1->getAddress() << endl << p1->get_R_Number() << endl << p1->get_P_Number() << endl << endl;
	//print p1 information
	cout << p2->getName() << endl << p2->getAddress() << endl << p2->get_R_Number() << endl << p2->get_P_Number() << endl << endl;
	//print p2
	cout << p3->getName() << endl << p3->getAddress() << endl << p3->get_R_Number() << endl << p3->get_P_Number() << endl << endl;
	//print p3
	cout << p4->getName() << endl << p4->getAddress() << endl << p4->get_R_Number() << endl << p4->get_P_Number() << endl << endl;
	//print p4

	return 0;
}