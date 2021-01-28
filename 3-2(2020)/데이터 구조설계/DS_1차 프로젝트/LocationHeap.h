#pragma once
#include "LocationHeapNode.h"
#include <fstream>
using namespace std;

class LocationHeap
{
private:
	LocationHeapNode** Heap;
	int size;
	int location_max = 7;
	ofstream flog;

public:
	LocationHeap();
	~LocationHeap();

	bool Insert(char* location);
	void Print();
};
