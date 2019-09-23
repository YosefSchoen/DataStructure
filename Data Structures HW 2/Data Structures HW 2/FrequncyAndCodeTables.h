#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cmath>
#define MAXCHARS 256
//#define nullptr NULL
using namespace std;

//FrequencyTable will store the values of the frequency of each charcter in a source text
class FrequencyTable {
public:
	//initializing everything to 0
	FrequencyTable() {
		for (int i = 0; i < MAXCHARS; i++) {
			frequency[i] = 0;
		}
	}

	//overriding [] operator 
	int &operator[](int index) {
		return frequency[index];
	}

private:
	//the frequencies will be stored in an array where each index is the character int value
	int frequency[MAXCHARS];
};	

//CodeTable will store the coded values for each character in the text
class CodeTable {
public:
	//intializing everything to empty
	CodeTable() {
		for (int i = 0; i < MAXCHARS; i++) {
			code[i] = "";
		}
	}

	//overloading the [] operator
	string &operator[](int index) {
		return code[index];
	}

private:
	//the codes will be stored in an array of strings where each index is the characters int value
	string code[MAXCHARS];
};