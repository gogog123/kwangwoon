#include "PatientInfo.h"
using namespace std;

PatientInfo::PatientInfo(char* name, char* address, int registration_number, int phone_number)
{
	this->name = name;
	this->address = address;
	this->registration_number = registration_number;
	this->phone_number = phone_number; // this-> : private variable
}

PatientInfo::~PatientInfo()
{
}

char* PatientInfo::getName()
{
	return name; //return name pointer
}

char* PatientInfo::getAddress()
{
	return address; //return address pointer
}

int PatientInfo::get_R_Number()
{
	return registration_number; //return rn
}

int PatientInfo::get_P_Number()
{
	return phone_number; // return pn
}