#include "HuffmanTree.h"

//constructor for an empty tree
HuffmanTree::HuffmanTree() {
	root = nullptr;
	numOfChars = 0;

	//pushing the empty node into the priority queue
	pQueue.push(root);

	//these members are for decoding so all set to 0 or null
	treeStructure = "";
	leafOrder = "";
	numOfLeaves = 0;
}

//constructor for a non empty tree to encode
HuffmanTree::HuffmanTree(string val) {
	root = nullptr;
	//calling method to build the frequencies based on user inputted value
	buildFreqTable(val);

	//calling method to find total number of chars
	numOfChars = totalChars();

	//filling the priority queue
	fillQueue();

	//these members are for decoding so all set to 0 or null
	treeStructure = "";
	leafOrder = "";
	numOfLeaves = 0;
}

//constructor for a non empty tree to decode
HuffmanTree::HuffmanTree(string structure, string order, int leaves) {
	//these members are for encoding so all set to 0 or null
	root = new HuffmanNode;
	numOfChars = 0;
	value = "";
	
	//members to build and decode a tree
	treeStructure = structure;
	leafOrder = order;
	numOfLeaves = leaves;
}

//destructor
HuffmanTree::~HuffmanTree() {

}

//method to encode a tree calls the methods to build the tree and the coded table and then prints it
void HuffmanTree::encode(string source) {
	buildTreeEncode(root);
	buildCodeTable(root, "");
	printEncode(source);
}

//method build a tree to encode text
void HuffmanTree::buildTreeEncode(HuffmanNode *nodePtr) {

	//stopping condition is if there is only one node in the priority queue
	while (pQueue.size() > 1) {
		//creating the left and right nodes of a node, assigning them from the top of the queue
		HuffmanNode *left = pQueue.top();
		pQueue.pop();
		HuffmanNode *right = pQueue.top();
		pQueue.pop();

		char newChar = ' ';

		//the parents frequency will be the sum of its children
		int newValueFreq = left->ValueFreq + right->ValueFreq;

		//creating a new non leaf node with the left and right son being the nodes above
		HuffmanNode *newNode = new HuffmanNode(newChar, newValueFreq, left, right);

		//pusing the node into the priority queue it will be placed based on its frequeny
		pQueue.push(newNode);
	}

	//setting the root to the top of the tree which is the only thing in the queue
	root = pQueue.top();
}

void HuffmanTree::printEncode(string source) {
	//format to print the encoded tree calling various things to print
	printNumOfLeaves();
	printTreeStructureChars(root);
	cout << endl;
	printTreeStructureBits(root);
	cout << endl;

	//printing the actual encoded message
	for (int i = 0; i < source.length(); i++) {
		int current = source[i];
		cout << codes[current];
	}

	cout << endl;
}

//decode will build a tree and print the result
void HuffmanTree::decode(string source) {
	buildTreeDecode(root);
	value = source;
	while (value.length() > 0) {
		printDecode(root);
	}

	cout << endl;
}

//method to build a tree to decode
void HuffmanTree::buildTreeDecode(HuffmanNode *nodePtr) {

	//if there are no more leaf values recursion will stop
	if (leafOrder.size() > 0) {

		//if the structures first bit is a zero the the node is not a leaf
		if (treeStructure[0] == '0') {

			//give the node two sons
			nodePtr->leftSon = new HuffmanNode;
			nodePtr->rightSon = new HuffmanNode;

			//erase the first bit from the structure and call method on left son
			treeStructure.erase(0,1);
			buildTreeDecode(nodePtr->leftSon);

			//do the same but now on the right son
			treeStructure.erase(0,1);
			buildTreeDecode(nodePtr->rightSon);

		}

		//if the bit is a one this node is a leaf with a character value
		else if (treeStructure[0] = '1') {
			//the value will be the first char in the string order
			nodePtr->character = leafOrder[0];
			nodePtr->leftSon = nullptr;
			nodePtr->rightSon = nullptr;
			//erase tht char from the string order
			leafOrder.erase(0,1);
		}
	}
}

//method to print the decoded result
void HuffmanTree::printDecode(HuffmanNode *nodePtr) {
	
	//if node is a leaf print its character value
	if (nodePtr->leftSon == nullptr) {
		cout << nodePtr->character;
	}

	//if not call print on its sons
	else {
		//if the forst bit of value is a zero go left
		if (value[0] == '0') {
			value.erase(0,1);
			printDecode(nodePtr->leftSon);
		}

		//if its a one go right
		else if (value[0] == '1') {
			value.erase(0,1);
			printDecode(nodePtr->rightSon);
		}
	}
}

//method to build a code table for encoding
void HuffmanTree::buildCodeTable(HuffmanNode *nodeptr, string result) {
	if (nodeptr->leftSon == nullptr) {
		codes[nodeptr->character] = result;
		return;
	}

	else {
		//appending a "0" to the left and a "1" to the right
		buildCodeTable(nodeptr->leftSon, result + "0");
		buildCodeTable(nodeptr->rightSon, result + "1");
	}
}

//method to assign values to the frequency table of the characters in the text
void HuffmanTree::buildFreqTable(string val) {
	for (int i = 0; i < val.length(); i++) {
		frequencies[val[i]]++;
	}
}

//method to find the total number of characters in a method
int HuffmanTree::totalChars() {
	int total = 0;
	for (int i = 0; i < MAXCHARS; i++) {
		//add the frequency of each character to the total
		total += frequencies[i];
	}

	//return the total number of characters
	return total;
}


//method to fill the queue with nodes
void HuffmanTree::fillQueue() {
	for (int i = 0; i < MAXCHARS; i++) {

		//dont fill it with nodes of a character tht doesn't exist in the text
		if (frequencies[i] > 0) {
			//the nodes character will be i casted as a char, and its corresponding frequency
			pQueue.push(new HuffmanNode((char)i, frequencies[i]));
		}
	}
}

//method to print the number of leaves in a tree
void HuffmanTree::printNumOfLeaves() {
	int numOfLeaves = 0;
	//if the frequency of a character is greater then zero then there must be a leaf node with that character
	for (int i = 0; i < MAXCHARS; i++) {
		if (frequencies[i] > 0) {
			numOfLeaves++;
		}
	}

	cout << numOfLeaves << endl;
}

//method to print the chars used in a tree using a preorder traversal
void HuffmanTree::printTreeStructureChars(HuffmanNode *nodePtr) {
	if (nodePtr->leftSon == nullptr) {
		cout << nodePtr->character;
		return;
	}

	printTreeStructureChars(nodePtr->leftSon);
	printTreeStructureChars(nodePtr->rightSon);
}

//method to print the structure in a tree using a preorder traversal
void HuffmanTree::printTreeStructureBits(HuffmanNode *nodePtr) {
	if (nodePtr->leftSon == nullptr) {
		cout << '1';
		return;
	}
	else {
		cout << '0';
	}

	printTreeStructureBits(nodePtr->leftSon);
	printTreeStructureBits(nodePtr->rightSon);
}