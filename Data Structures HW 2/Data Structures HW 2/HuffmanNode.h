#pragma once
#include "FrequncyAndCodeTables.h"

class CompareNode;

class HuffmanNode {
public:
	//constructor for empty node
	HuffmanNode() {
		character = ' ';
		ValueFreq = 0;
		leftSon = nullptr;
		rightSon = nullptr;
	}

	//constructer for non empty node with default values
	HuffmanNode(char val, int frequency = 0, HuffmanNode* left = nullptr, HuffmanNode* right = nullptr) {
		character = val;
		ValueFreq = frequency;
		leftSon = left;
		rightSon = right;
	}

	//a huffman node has a charcter frequency of that charcter, and a left and right child node
	char character;
	int ValueFreq;
	HuffmanNode *leftSon;
	HuffmanNode *rightSon;
};

//compare node is the class that will be used to min sort the priority queue
class CompareNode {
public:
	bool operator() (HuffmanNode* const &n1, HuffmanNode* const &n2) {
		return n1->ValueFreq > n2->ValueFreq;
	}
};