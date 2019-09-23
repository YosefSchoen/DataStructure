#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <functional>
#include <string>

using namespace std;

class Treatment {
public:
	//constructors
	Treatment();
	//Treatment(string, string, string, string);

	//getters
	string getPhysician() { return physician; }
	string getPatient() { return patient; }
	string getDate() { return date; }
	string getTime() { return time; }

	//setters
	void setPhysician(string _physician) { physician = _physician; }
	void setPatient(string _patient) { patient = _patient; }
	void setDate(string _date) { date = _date; }
	void setTime(string _time) { time = _time; }

	//comparison operators
	bool operator==(Treatment &);
	bool operator<=(Treatment &);
	bool operator>=(Treatment &);
	bool operator<(Treatment &);
	bool operator>(Treatment &);

	//input and output friend functions
	friend istream& operator>>(istream& is, Treatment& t);
	friend ostream& operator<<(ostream& os, Treatment& t);

private:
	//memebers of a treatment
	string physician;
	string patient;
	string date;
	string time;
};
