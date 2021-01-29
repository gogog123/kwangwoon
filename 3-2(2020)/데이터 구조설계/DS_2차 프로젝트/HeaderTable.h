#pragma once
#include "FPNode.h"
#include <list>
#include <string>

class HeaderTable
{
private:
	list<pair<int, string> > indexTable;
	map<string, FPNode*> dataTable;
public:
	HeaderTable() { 
		list<pair<int, string> >* indexTable = new list<pair<int, string>>;
		map<string, FPNode*>* dataTable = new map<string, FPNode*>; // ???
	}
	~HeaderTable();
	void insertTable(char* item, int frequency);
	void insertTable_map(int threshold);
	list<pair<int, string>> getindexTable() { return indexTable; }

	map<string, FPNode*> getdataTable() { return dataTable; }
	FPNode* getNode(string item) { return dataTable.find(item)->second; }
	void descendingIndexTable() { indexTable.sort(greater<pair<int, string>>()); }
	void ascendingIndexTable() { indexTable.sort(); }
	int find_frequency(string item);
	void setData(string item, FPNode* node) {
		dataTable.find(item)->second = node;
	}
};


