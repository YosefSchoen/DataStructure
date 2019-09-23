#include "HuffmanTree.h"

//Switch case options
enum OPTIONS {Encode = 1, Decode = 2, Exit = 3};

//instructions for user
void instructions() {
	cout << "enter 1 to encode a text\n";
	cout << "enter 2 to decode a text\n";
	cout << "enter 3 to exit\n";
}

int main() {
	//Huffman Tree for program
	HuffmanTree *usersTree;

	//required user information for encode
	string word;

	//reuired user information for decode
	int numOfLeaves;
	string orderOfLetters;
	string treeStructure;
	string encodedWord;

	//switch choice to choose encode, decode or exit
	int choice;
	
	instructions();

	//looped switch case for user
	do {
		cin >> choice;
		switch (choice) {

		//case for encoding
		case Encode:
			cout << "enter the original text" << endl;
			cin >> word;
			cout << "The encoded string is:\n";
			//building a new Huffman tree based on users non Coded message "word", and encoding that message
			usersTree = new HuffmanTree(word);
			usersTree->encode(word);
			break;

		//case for decoding
		case Decode:
			cout << "enter n enter the letters enter the encoded structure enter the encoded text\n";
			
			cin >> numOfLeaves >> orderOfLetters >> treeStructure >> encodedWord;
			cout << "The decoded string is:\n";

			//building a new Huffman Tree based on the tree structure, order of the letters, and number of letters "leaves",  then decoding the message
			usersTree = new HuffmanTree(treeStructure, orderOfLetters, numOfLeaves);
			usersTree->decode(encodedWord);
			break;
		}

	} while (choice != Exit);

	return 0;
}