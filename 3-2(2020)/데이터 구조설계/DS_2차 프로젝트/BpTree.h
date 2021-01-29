#ifndef _BpTree_H_
#define _BpTree_H_

#include "BpTreeDataNode.h"
#include "BpTreeIndexNode.h"
#include <fstream>
#include <iostream>

class BpTree {
private:
	BpTreeNode* root;
	int			order;		// m children
	ofstream* fout;
public:
	BpTree(ofstream* fout, int order = 3) {
		root = NULL;
		this->order = order;
		this->fout = fout;
	}
	~BpTree();
	/* essential */
	bool		Insert(int key, set<string> set); //insert
	bool		excessDataNode(BpTreeNode* pDataNode); //exceed datanode
	bool		excessIndexNode(BpTreeNode* pIndexNode); // exceed indexnode
	void		splitDataNode(BpTreeNode* pDataNode); //split datanode
	void		splitIndexNode(BpTreeNode* pIndexNode); // split indexnode
	BpTreeNode* getRoot() { return root; } //return root
	BpTreeNode* searchDataNode(int n); //search datanode

	void	printFrequentPatterns(set<string> pFrequentPattern, string item);
	bool	printFrequency(string item, int min_frequency);
	bool	printConfidence(string item, double item_frequency, int min_frequency);
	bool 	printRange(string item, int min, int max);

};

#endif
