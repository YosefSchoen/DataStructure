#pragma once
#include <iostream>
#include <string>
#include <list>

//#define nullptr NULL
using namespace std;

enum Color {
	black,
	gray,
	white
};

class Vertex;

class Edge {
public:
	Edge(Vertex *, Vertex *);
	bool operator==(const Edge &);

	Vertex *getSource() { return source; }
	Vertex *getDestination() { return destination; }

	void setSource(Vertex *newSrc) { source = newSrc; }
	void setDestination(Vertex *newDest) { destination = newDest; }

	friend class Vertex;

private:
	Vertex *source;
	Vertex *destination;
	int distance;
};

class Vertex {
public:
	Vertex();
	Vertex(string);

	string getKey() { return key; }
	list<Edge *>& getEdgeList() { return edgeList; }
	double getD() { return d; }
	double getF() { return f; }
	Vertex *getPi() { return pi; }
	Color getColor() { return color; }

	void setD(double newD) { d = newD; }
	void setF(double newF) { f = newF; }
	void setPI(Vertex *newPi) { pi = newPi; }
	void setColor(Color newColor) { color = newColor; }

	void operator=(const Vertex &other) {
		key = other.key;
		edgeList = other.edgeList;
		d = other.d;
		f = other.f;
		pi = other.pi;
		color = other.color;
	}

	bool adde(Vertex *);
	bool destinationExists(Vertex *);
	int numOfNeighbors();
	void removeEdges();
	void print();

private:
	string key;
	list<Edge *>edgeList;
	double d;
	double f;
	Vertex *pi;
	Color color;
};
