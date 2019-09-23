#include "graphs.h"

Graph::Graph() {
	int order = 0;
	int timer = 0;
}

Graph::~Graph() {

}

bool Graph::addv(string newKey) {
	list<Vertex*>::iterator it;
	for (it = verticies.begin(); it != verticies.end(); it++) {
		if ((*it)->getKey() == newKey) {
			return false;
		}
	}

	Vertex *newVertex = new Vertex(newKey);
	verticies.push_back(newVertex);
	return true;
}

bool Graph::adde(string src, string dest) {
	Vertex *tempSrc = nullptr;
	Vertex *tempDest = nullptr;

	list<Vertex*>::iterator it;
	for (it = verticies.begin(); it != verticies.end(); it++) {
		if ((*it)->getKey() == src) {
			tempSrc = *it;
		}

		if ((*it)->getKey() == dest) {
			tempDest = *it;
		}
	}

	if (tempSrc == nullptr || tempDest == nullptr) {
		return false;
	}

	else {
		return (*tempSrc).adde(tempDest);
	}
	
}

list<Vertex*> Graph::DFS(Vertex *u) {
	list<Vertex*>::iterator it;
	for (it = verticies.begin(); it != verticies.end(); it++) {
		(*it)->setColor(white);
		(*it)->setPI(nullptr);
		timer = 0;
	}

	sortedList.clear();
	for (it = verticies.begin(); it != verticies.end(); it++) {
		if ((*it)->getColor() == white) {
			DFSVisit(*it);
		}
	}

	return sortedList;
}

void Graph::DFSVisit(Vertex *u) {
	u->setColor(gray);
	timer++;
	u->setD(timer);

	list<Edge *>::iterator it;
	for(it = u->getEdgeList().begin(); it != u->getEdgeList().end(); it++) {
		if ((*it)->getDestination()->getColor() == white) {
			(*it)->getDestination()->setColor(black);
			DFSVisit((*it)->getDestination());
		}
	}

	u->setColor(black);
	timer++;
	u->setF(timer);
	sortedList.push_front(u);
}

void Graph::topologicalSort() {
	cout << "order:\n";

	DFS(verticies.front());

	list<Vertex*>::iterator it;
	for (it = sortedList.begin(); it != sortedList.end(); it++) {
		cout << (*it)->getKey() << " ";
	}

	cout << endl;
}

void Graph::printAll() {
	list<Vertex*>::iterator it;
	for (it = verticies.begin(); it != verticies.end(); it++) {
		cout << (*it)->getKey() << ": ";
		(*it)->print();
		cout << endl;
	}
}


