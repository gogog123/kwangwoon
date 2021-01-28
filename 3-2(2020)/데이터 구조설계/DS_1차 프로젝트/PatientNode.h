#pragma once
#include <cstring>

class PatientNode
{
private:
	char* Name;
	float Temperature;
	char Cough;
	char* Location;

	PatientNode* pNext;
	PatientNode* pLeft;
	PatientNode* pRight;

public:
	PatientNode();
	~PatientNode();

	char* GetName();
	float GetTemp();
	char GetCough();
	char* GetLoc();

	void SetName(char* name);
	void SetTemp(float temp);
	void SetCough(char cough);
	void SetLoc(char* location);
};
