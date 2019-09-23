#pragma once
#include <iostream>
#include <string>
#include <list>
//#define nullptr NULL
using namespace std;

class DTNode;

class ValidAnswer {
public:
	ValidAnswer(string ans, DTNode *child) {
		answer = ans;
		son = child;
	}

	string answer;
	DTNode *son;
};
