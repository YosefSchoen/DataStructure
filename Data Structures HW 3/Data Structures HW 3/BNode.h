#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <functional>
#include <string>

using namespace std;

//can be changed
//a node in the BTree
const int M = 5;

template <typename T>
struct BNode {
public:
	T Key[M - 1];
	BNode<T> *Son[M];
	int nsons;
	int nkeys;

	BNode();

	//initialize as a leaf
	BNode(T x);

	void insert(T x, T &upx, BNode<T>*& upt);
	void deleteVal(T x, bool SearchForSuccessor, T &successorFound, bool& holeSent);
	int indexValInK(T x);

	T*  searchInNode(T& x) {
		T* tmp = NULL;
		for (int i = 0; i < nkeys; i++) {
			if (Key[i] == x) tmp = Key + i;
		}

		return tmp;
	}

	int indexValGEQInK(T x);
	bool sonsUnderMinimum() { return nsons < (int)(M / 2.0 + 0.5); }
	bool sonsMoreThanMinimum() { return nsons >(int)(M / 2.0 + 0.5); }
	bool sonsMinimum() {
		int tmp = (int)(M / 2.0 + 0.5);
		return nsons <= tmp;
	}

private:
	void AddValue(T x, BNode<T> *p, T &upx, BNode<T>*& upt);

	//delete the first in the node. returns the value deleted and the first SubTree
	void DeleteFirst(T &val, BNode<T>* &firstSubTree);

	//delete the first in the node. returns the value deleted and the first SubTree
	void DeleteLast(T &val, BNode<T>* &lastSubTree);

	//delete a value from a leaf
	void DeleteValueFromLeaf(int ToDelete);

	//unify values and pointers with values and pointers of Son[brotherInd], and then delete Son[brotherInd]
	void unifyWith(int brotherInd, int holeInd);

	//move one value and one subtree from subTreeBrother to subTree 
	void moveToSubtreeFromBrother(int subTree, int subTreeBrother);
};