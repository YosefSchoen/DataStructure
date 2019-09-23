#include "EdgeAndVertex.h"


Edge::Edge(Vertex *src, Vertex *dest) {
	source = src;
	destination = dest;
	distance = 0;
}

bool Edge::operator==(const Edge &other) {
	if (source == other.source && destination == other.destination) {
		return true;
	}

	return false;
}

Vertex::Vertex() {
	Vertex("");
}

Vertex::Vertex(string vKey) {
	key = vKey;
	d = 0;
	f = 0;
	pi = nullptr;
	color = black;
}

bool Vertex::adde(Vertex *dest) {
	if (!destinationExists(dest)) {
		Edge *newEdge = new Edge(this, dest);
		edgeList.push_back(newEdge);
		return true;
	}

	return false;
}

bool Vertex::destinationExists(Vertex *dest) {
	list<Edge *>::iterator it;
	for (it = edgeList.begin(); it != edgeList.end(); it++) {
		if ((*it)->destination == dest) {
			return true;
		}
	}

	return false;
	
}

int Vertex::numOfNeighbors() {
	int total = 0;

	list<Edge *>::iterator it;
	for (it = edgeList.begin(); it != edgeList.end(); it++) {
		total++;
	}

	return total;
}

void Vertex::removeEdges() {
	list<Edge *>::iterator it;

	for (it = edgeList.end(); it != edgeList.begin(); it--) {
		delete *it;
	}
}

void Vertex::print() {
	list<Edge *>::iterator it;
	for (it = edgeList.begin(); it != edgeList.end(); it++) {
		cout << (*it)->destination->key << " ";
	}
}