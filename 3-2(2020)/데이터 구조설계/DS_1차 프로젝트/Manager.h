//다른 클래스들의 동작을 관리하여 프로그램을 전체적으로 조정하는 역할을 수행
#pragma once
#include "PatientNode.h"
#include "LocationBST.h"
#include "LocationHeap.h"
#include <queue>

class Manager
{
private:
	queue <PatientNode*>* ds_queue; 
	LocationBST* ds_bst;
	LocationHeap* ds_heap;
	ifstream fin;
	ofstream flog;

public:
	Manager();
	~Manager();

	void run(const char* command);
	bool LOAD(queue<PatientNode*>* Patient_Queue);
	bool ADD(char* name, float temperature, char* cough, char* location, queue<PatientNode*>* ds_queue);
	bool QPOP(LocationBST* DS_BST, int size);
	bool SEARCH(LocationBST* DS_BST, char* name);
	bool PRINT(LocationBST* DS_BST, char* BH, char* traverse);
	bool BPOP(LocationBST* DS_BST, char* name);

	void PrintErrorCode(int num); //error
	void PrintSuccess(const char* act); //success
	void AddSuccess(const char* act, char* name, float temperature, char* cough, char* location); //Add success
};
