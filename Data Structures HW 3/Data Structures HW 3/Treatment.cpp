#include "Treatment.h"

Treatment::Treatment() {
	physician = "";
	patient = "";
	date = "";
	time = "";
}

/*
Treatment::Treatment(string _physician, string _patient, string _date, string _time) {
	physician = _physician;
	patient = _patient;
	date = _date;
	time = _time;
}
*/

bool Treatment::operator==(Treatment &other) {
	if (physician == other.physician && date == other.date && time == other.time) {
		return true;
	}

	return false;
}

bool Treatment::operator<=(Treatment &other) {
	if (*this < other || *this == other) {
		return true;
	}

	return false;
}

bool Treatment::operator>=(Treatment &other) {
	if (*this > other || *this == other) {
		return true;
	}

	return false;
}

bool Treatment::operator<(Treatment &other) {
	if (date < other.date) {
		return true;
	}

	else if (date == other.date){
		if (time < other.time) {
			return true;
		}
	}

	return false;
}

bool Treatment::operator>(Treatment &other) {
	if (date > other.date) {
		return true;
	}

	else if (date == other.date) {
		if (time > other.time) {
			return true;
		}
	}
	
	return false;
}

istream& operator>>(istream& is, Treatment& t) {
	cout << "enter physician year-month-day hour ";
	is >> t.physician >> t.date >> t.time;
	t.patient = string("");
	return is;
}

ostream& operator<<(ostream& os, Treatment& t) {
	os << "Treatement details: physician: " << t.physician << " patient: " << t.patient << " date: " << t.date << "," << t.time << endl;
	return os;
}