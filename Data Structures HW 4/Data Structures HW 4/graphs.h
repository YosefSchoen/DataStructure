#pragma once
#include "EdgeAndVertex.h"
using namespace std;

class Graph {
public:
	Graph();
	~Graph();

	bool addv(string);
	bool adde(string, string);

	list<Vertex*> DFS(Vertex *);
	void DFSVisit(Vertex *);
	void topologicalSort();
	void printAll();
	
private:
	list<Vertex*> verticies;
	list<Vertex*> sortedList;
	int order;
	int timer;
};