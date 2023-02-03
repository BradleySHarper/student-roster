#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

//constructor with no parameters, values set to default
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->degreeProgram = DegreeProgram::SECURITY;
}

//full constructor
Student::Student(string sID, string fName, string lName, string email, int sAge, int days[], DegreeProgram degreeProgram) {
	studentID = sID;
	firstName = fName;
	lastName = lName;
	emailAddress = email;
	age = sAge;
	this->degreeProgram = degreeProgram;
	this->numOfDays = new int[numOfDaysSize];
	for (int i = 0; i < 3; i++) {
		this->numOfDays[i] = days[i];
	}
}

//accessors
void Student::setStudentID(string sID) {sID = studentID;}
void Student::setFirstName(string fName) {fName = firstName;}
void Student::setLastName(string lName) {lName = lastName;}
void Student::setEmail(string eMail) {eMail = emailAddress;}
void Student::setAge(int sAge) {sAge = age;}
void Student::setDegree(DegreeProgram degree) { degree = degreeProgram; }
void Student::setNumOfDays(int days[]) {
	for (int i = 0; i < 3; i++) {
		numOfDays[i] = days[i];
	}
}

//mutators
string Student::getStudentID() {return studentID;}
string Student::getFirstName() {return firstName;}
string Student::getLastName() {return lastName;}
string Student::getEmail() {return emailAddress; }
int Student::getAge() {return age; }
int* Student::getNumOfDays() {return numOfDays; }
DegreeProgram Student::getDegree() { return this->degreeProgram; }

//print method
void Student::print() {
	cout << getStudentID() << "\t";
	cout << getFirstName() << "\t";
	cout << getLastName() << "";
	cout << getAge() << "\t";
	cout << degreeTypes[this->getDegree()] << "\t";
	cout << "{" << getNumOfDays()[0] << "," << getNumOfDays()[1] << "," << getNumOfDays()[2] << "}" << endl;
}

//Deconstructor
Student::~Student() {}








