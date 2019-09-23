#pragma once
#include "BNode.cpp"

//BTree with max degree M
template <typename T>
class BTree {
private:
	void deleteSubTree(BNode<T> *t);
	void printSubTree(BNode<T> *t);
	void printAllKeys(BNode<T> *p, std::function<bool(const T&)>);
	T* search(BNode<T> *p, T x);
	T *searchDouble(BNode<T> *p, T x, int index);

public:
	//build an empty tree
	BTree() { root = NULL; }
	~BTree() { deleteTree(); }

	//add a value to the tree
	void insert(T x);
	void deleteVal(T x);
	void deleteTree() { deleteSubTree(root); }
	void printTree() { printSubTree(root); }
	void printAllKeys(std::function<bool(const T&)> predicate) { printAllKeys(root, predicate); }
	T* search(T x) { return search(root, x); }

	BNode<T> *root;
};