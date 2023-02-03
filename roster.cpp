#include <iostream>
#include <string>
#include "roster.h"
using namespace std;


//parses each row, using commas as delineators
void Roster::parse(string row) {

	size_t rhs = row.find(",");
	string studentID = row.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string firstName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(',', lhs);
	string lastName = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string email = row.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int age = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int day1 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int day2 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int day3 = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	string studentDegree = row.substr(lhs, rhs - lhs);

	DegreeProgram degree = DegreeProgram::SECURITY;

	if (studentDegree == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	}
	if (studentDegree == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}
	if (studentDegree == "SOFTWARE") {
		degree = DegreeProgram::SOFTWARE;
	}

	//creates student object, using parsed strings from above.
	addStudent(studentID, firstName, lastName, email, age, day1, day2, day3, degree);


}
//method for creating student object, used in parse(string row).
void Roster::addStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degree) {
	
	//converts days1/2/3 into array object 
	int numOfDaysConv[3] = { days1, days2, days3 };

	//adds Student object to classRosterArray
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, numOfDaysConv, degree);

}
//Method to remove student from classRosterArray
void Roster::removeStudent(string studentID) {

	bool found = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			delete classRosterArray[i];
			classRosterArray[i] = classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	if (!found) {
		cout << "Student with ID: " << studentID << "  was not found!" << endl;
	}
}

//Prints all Student objects in roster
void Roster::printAll() {

	for (int i = 0; i < Roster::lastIndex + 1; i++) {
		classRosterArray[i]->print();
	}
}

//Prints an average of days in all 3 courses.
void Roster::printAvgDaysInCourse(string studentID) {

	for (int i = 0; i < Roster::lastIndex + 1; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			//found = true;
			int* days = classRosterArray[i]->getNumOfDays();
			int avg = (days[0] + days[1] + days[2]) / 3;
			cout << "Student ID: " << studentID << ", average days in course is: " << avg << endl;
		}
	}

}

//Prints out all invalid emails, based on criteria defined in rubric
void Roster::printInvalidEmails() {
	bool found = false;
	for (int i = 0; i < Roster::lastIndex+1; i++) {
		std::string emailToCheck = (classRosterArray[i]->getEmail());
		if (emailToCheck.find(' ') != string::npos || emailToCheck.find('@') == string::npos || emailToCheck.find('.') == string::npos) {

			found = true;
			cout << emailToCheck << " - is invalid. " << std::endl;
		}
	}
}

//Prints Students in specified degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < Roster::lastIndex + 1; i++) {
		if (classRosterArray[i]->getDegree() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

//Deconstructor
Roster::~Roster() {
	for (int i = 0; i < lastIndex +1; i++) {
		delete classRosterArray[i];
	}
}





