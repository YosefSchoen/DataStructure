#include "DecisionTree.h"

DecisionTree::DecisionTree() {
	root = new DTNode;
}

DecisionTree::DecisionTree(string newQ) {
	root = new DTNode(newQ);
}

DecisionTree::~DecisionTree() {
	deleteSubTreePrivate(root);
}

DTNode* DecisionTree::questionPrivate(string Q, DTNode* searchNode) {

	if (searchNode->value == Q) {
		return searchNode;
	}

	else if (!searchNode->isLeaf) {
		list<ValidAnswer*>::iterator it;

		for (it = searchNode->answers.begin(); it != searchNode->answers.end(); it++) {
			return questionPrivate(Q, (*it)->son);
		}
	}

	return nullptr;
}

void DecisionTree::addRoot(string newQ) {
	delete root;
	root = new DTNode(newQ);
	root->isLeaf = true;
}

bool DecisionTree::addSon(string Q, string A, string newQ) {
	DTNode *addToNode = question(Q);

	if (addToNode != nullptr) {
		DTNode *newSon = new DTNode(newQ);
		ValidAnswer *newAns = new ValidAnswer(A, newSon);

		addToNode->answers.push_back(newAns);
		addToNode->isLeaf = false;

		return true;
	}

	else {
		return false;
	}
}

void DecisionTree::deleteSubTreePrivate(DTNode *delNode) {

	list<ValidAnswer*>::iterator it;

	for (it = delNode->answers.begin(); it != delNode->answers.end(); it++) {
		if (!delNode->isLeaf) {
			deleteSubTreePrivate((*it)->son);
		}
	}
	delete delNode;
}

void DecisionTree::printAllTreePrivate(DTNode *searchNode) {
	cout << searchNode->value << endl;

	list<ValidAnswer*>::iterator it;
	for (it = searchNode->answers.begin(); it != searchNode->answers.end(); it++) {
		cout << (*it)->answer << endl;
		if (!searchNode->isLeaf) {
			printAllTreePrivate((*it)->son);
		}

	}
}

bool DecisionTree::searchAndPrintPrivate(DTNode *searchNode, string val) {
	if (searchNode->value == val) {
		cout << searchNode->value;
		return true;
	}

	if (searchNode->answers.size() == 0) {
		return false;
	}

	list<ValidAnswer*>::iterator it;

	for (it = searchNode->answers.begin(); it != searchNode->answers.end(); it++) {
		if (searchAndPrintPrivate((*it)->son, val)) {
			cout << "=>" << searchNode->value;
			return true;
		}
	}

	return false;
}

void DecisionTree::proccessPrivate(DTNode* proccessNode) {
	string ans;

	cout << proccessNode->value << endl;

	if (proccessNode->isLeaf) {
		return;
	}

	cin >> ans;

	list<ValidAnswer*>::iterator it;
	for (it = proccessNode->answers.begin(); it != proccessNode->answers.end(); it++) {
		if (ans == (*it)->answer) {
			proccessPrivate((*it)->son);
		}
	}
}

