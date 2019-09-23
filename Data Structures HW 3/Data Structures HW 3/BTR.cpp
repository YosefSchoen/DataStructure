#include "BTR.h"

template <typename T>
T* BTree<T>::search(BNode<T> *p, T x) {
	if (p == NULL) {
		return NULL;
	}

	int i = 0;

	while (i < p->nkeys && x > p->Key[i]) {
		i++;
	}

	if (!(x < p->Key[i]) && !(x > p->Key[i])) {
		if (x == p->Key[i]) {
			return &(p->Key[i]);
		}

		else {
			return searchDouble(p, x, i);
		}
	}

	else {
		return search(p->Son[i], x);
	}
}

template <typename T>
T* BTree<T>::searchDouble(BNode<T> *p, T x, int index) {
	for (int i = index; i < p->nkeys; i++) {
		if (x == p->Key[i]) {
			return &(p->Key[i]);
		}
	}

	T *tempOne = search(p->Son[index], x);
	T *tempTwo = search(p->Son[index + 1], x);

	if (tempOne != NULL) {
		return tempOne;
	}

	else if (tempTwo != NULL) {
		return tempTwo;
	}

	else {
		return NULL;
	}
}


template <typename T>
void BTree<T>::printAllKeys(BNode<T> *p, std::function<bool(const T&)> predicate) {
	if (p == NULL) {
		return;
	}

	else {
		for (int i = 0; i < p->nsons; i++) {
			printAllKeys(p->Son[i], predicate);

			if (i < p->nkeys && predicate(p->Key[i])) {
				cout << p->Key[i];
			}
		}
	}
}


template <typename T>
void BTree<T>::deleteSubTree(BNode<T> *t) {
	if (t == NULL) {
		return;
	}

	else {
		for (int i = 0; i < t->nsons; i++) {
			deleteSubTree(t->Son[i]);

			if (i < t->nkeys) {
				deleteVal(t->Key[i]);
			}
		}
	}
}


template <typename T>
void BTree<T>::printSubTree(BNode<T> *t) {
	if (t == NULL) {
		return;
	}

	else {
		for (int i = 0; i < t->nsons; i++) {
			printSubTree(t->Son[i]);

			if (i < t->nkeys) {
				cout << t->Key[i];
			}
		}
	}
}

//add a value to the tree
template <typename T>
void BTree<T>::insert(T x) {
	BNode<T> *tmp = NULL;
	T tx;
	if (root == NULL) {
		root = new BNode<T>(x);
	}

	else {
		root->insert(x, tx, tmp);

		//a split was done;
		if (tmp) {
			BNode<T> *newRoot = new BNode<T>(tx);
			newRoot->Son[0] = root;
			newRoot->Son[1] = tmp;
			root = newRoot;
		}
	}
}

template <typename T>
void BTree<T>::deleteVal(T x) {
	T tmp;
	bool holeSent;
	if (root == NULL) {
		return;
	}

	//and if a hole was return, the depth of all leaves reduces in one.
	root->deleteVal(x, false, tmp, holeSent);

	if (holeSent == true) {
		//the son will be the root
		if (root->nsons == 1) {
			BNode<T> *tmp = root;
			root = root->Son[0];
			delete tmp;
		}
	}
	//otherwise, the root is allowed to have less than M/2 nodes.
}