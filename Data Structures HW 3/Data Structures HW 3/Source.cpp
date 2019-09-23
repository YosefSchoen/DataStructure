#include "BTR.cpp"
#include "Treatment.h"

enum OPTIONS {
	NewPhysician = 1,
	AddDate,
	NewAppointment,
	PrintPatientCalendar,
	PrintPhysicianCalendar,
	PrintDateReminders,
	Exit
};

void printInstructions() {
	cout << "\nChoose one of the following" << endl;
	cout << "1: add a new Physician" << endl;
	cout << "2: add an open date and time for a physician" << endl;
	cout << "3: add a new Appointment " << endl;
	cout << "4: print patient calendar " << endl;
	cout << "5: print physician calendar " << endl;
	cout << "6: print date reminders" << endl;
	cout << "7: exit:" << endl;
}

void main() {

	int choice;
	BTree<Treatment> bt;
	vector<string> physicians;
	Treatment tr;
	Treatment tr2;
	string str;
	string str2;
	vector<Treatment> keys;
	Treatment *p;

	printInstructions();

	do {
		cin >> choice;

		switch (choice) {
		case NewPhysician:
			cout << "Enter physician name ";
			cin >> str;
			physicians.push_back(str);
			break;

		case AddDate:
			cin >> tr;

			if (std::find(physicians.begin(), physicians.end(), tr.getPhysician()) == physicians.end())
				cout << "ERROR" << endl;

			else {
				bt.insert(tr);
			}

			break;

		case NewAppointment:
			//fix a new treatment. read treatment details.
			cin >> tr;
			p = bt.search(tr);

			if (p == NULL) {
				cout << "ERROR" << endl;
			}

			else {
				cout << "Enter patient name ";
				cin >> str;

				if (p->getPatient() != "") {
					cout << "USED" << endl;
				}

				else {
					p->setPatient(str);
					cout << "treatement for " << str << " fixed at " << p->getDate() << " time " << p->getTime() << endl;
				}
			}

			break;

		case PrintPatientCalendar:
			cout << "Enter patient name ";
			cin >> str;

			bt.printAllKeys([str](Treatment a) {return (a.getPatient() == str); });
			break;

		case PrintPhysicianCalendar:
			cout << "Enter physician name ";
			cin >> str;

			bt.printAllKeys([str](Treatment a) {return (a.getPhysician() == str && a.getPatient() != ""); });
			break;

		case PrintDateReminders:
			cout << "Enter date ";
			cin >> str;

			bt.printAllKeys([str](Treatment a) {return (a.getDate() == str && a.getPatient() != ""); });
			break;

		case Exit:
			cout << "bye ";
			break;

		default:
			cout << "error ";
			break;
		}
		//switch
	} while (choice != Exit);
}