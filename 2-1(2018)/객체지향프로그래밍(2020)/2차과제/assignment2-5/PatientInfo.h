#pragma once
#include <iostream>
using namespace std;

class PatientInfo
{
private:
	char* name;
	char* address;
	int registration_number;
	int phone_number;

public:
	PatientInfo(char* name, char* address, int registration_number, int phone_number);
	~PatientInfo();

	char* getName();
	char* getAddress();
	int get_R_Number();
	int get_P_Number();
};

