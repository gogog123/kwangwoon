#pragma once
#include "LocationNode.h"
#include "PatientNode.h"

class LocationBST
{
private:
	LocationNode* Root;
	ofstream flog;

public:
	LocationBST();
	~LocationBST();

	LocationNode* GetRoot();
	void Insert_Location(LocationNode* node);
	bool Insert_Patient(PatientNode* node);
	int Search(char* name);
	char* Delete(char* name);
	void Print_PRE();
	void Print_IN();
	void Print_POST();
	void Print_LEVEL();
};
