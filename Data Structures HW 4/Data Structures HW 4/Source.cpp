#include "graphs.h"


enum Options {
	AddTask = 1,
	AddPriorityRule,
	PrintGraph,
	PrintRecommendedOrder,
	Exit
};

void printInstructions() {
	cout << "Choose one of the following:\n";
	cout << "1-to add a task\n";
	cout << "2 - to add a priority rule\n";
	cout << "3 - to print all the graph\n";
	cout << "4 - print a recommended task order\n";
	cout << "5 - exit\n";
}

int main() {
	Graph g;
	try {
		string v1;
		string v2;
		string name;
		int choice;

		printInstructions();

		do {
			cin >> choice;
			switch (choice) {
			case AddTask:
				cout << "Enter the task you want to add\n";
				cin >> v1;
				if (!g.addv(v1)) cout << "ERROR\n";
				break;

			case AddPriorityRule:
				cout << "Enter earlier task and the later task\n";
				cin >> v1 >> v2;
				if (!g.adde(v1, v2)) cout << "ERROR\n";
				break;

			case PrintGraph:
				cout << "The graph:\n";
				g.printAll();
				cout << endl;
				break;

			case PrintRecommendedOrder:
				cout << "The recommended order:\n";
				g.topologicalSort();
				cout << endl;
				break;

			case Exit:
				cout << "byebye";  
				break;

			default:
				cout << "ERROR\n";
			}

		} while (choice != 5);
	}

	catch (string s) {
		cout << s << endl;
	}

	return 0;
}