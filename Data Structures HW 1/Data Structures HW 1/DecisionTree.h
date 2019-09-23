#pragma once
#include "DTNode.h"


class DecisionTree {
private:
	DecisionTree(string);
	DTNode *questionPrivate(string, DTNode*);
	void printAllTreePrivate(DTNode*);
	bool searchAndPrintPrivate(DTNode*, string);
	void proccessPrivate(DTNode*);
	void deleteSubTreePrivate(DTNode*);

public:
	DecisionTree();
	~DecisionTree();
	DTNode *question(string Q) { return questionPrivate(Q, root); }
	bool addSon(string, string, string);
	void addRoot(string newQ);
	void deleteSubTree(string Q) { deleteSubTreePrivate(question(Q)); }
	void printAllTree() { printAllTreePrivate(root); }
	void searchAndPrint(string Q) { (root, Q); }
	void process() { proccessPrivate(root); }

private:
	DTNode *root;
};