#pragma once
#include <cstring>

class PatientBSTNode
{
private:
	char* Name;
	char Disease;

	PatientBSTNode* pLeft;
	PatientBSTNode* pRight;

public:
	PatientBSTNode(); //constructor
	~PatientBSTNode(); //destructor

	char* GetName();
	char GetDisease();
	PatientBSTNode* GetLeft();
	PatientBSTNode* GetRight();
	//get(return)

	void SetName(char* name);
	void SetDisease(char disease);
	void SetLeft(PatientBSTNode* node);
	void SetRight(PatientBSTNode* node);
	//set data
};
