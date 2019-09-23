#pragma once
#include <iostream>
#include <list>
#include <string>
#include "ValidAnswer.h"
using namespace std;

class DTNode {
public:
	DTNode() {
		value = "";
		isLeaf = true;
	}

	DTNode(string val) {
		value = val;
		isLeaf = true;
	}

	string value;
	list<ValidAnswer*> answers;
	bool isLeaf;
};