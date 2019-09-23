#pragma once
#include "HuffmanNode.h"

class HuffmanTree {
private:
	//build tree, frequency Table, and coded table
	void buildTreeEncode(HuffmanNode *);
	void buildTreeDecode(HuffmanNode *);
	void buildFreqTable(string);
	void buildCodeTable(HuffmanNode *, string);


	//various print methods
	void printNumOfLeaves();
	void printTreeStructureChars(HuffmanNode *);
	void printTreeStructureBits(HuffmanNode *);
	void printDecode(HuffmanNode *);

public:
	//constructors and destructors
	HuffmanTree();
	HuffmanTree(string);
	HuffmanTree(string, string, int);
	~HuffmanTree();

	//encode and print encoded result
	void encode(string);
	void printEncode(string);

	//decode
	void decode(string);
	

	int totalChars();
	void fillQueue();

private:
	HuffmanNode *root;
	string value;

	//encoding class members
	int numOfChars;
	FrequencyTable frequencies;
	CodeTable codes;
	//priority queue used to sort the elements from smallest to biggest
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNode> pQueue;

	//decoding class members
	string treeStructure;
	string leafOrder;
	int numOfLeaves;
};