#pragma once
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class Roster {

public:

	void parse(string row);
	void addStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degree);
	void removeStudent(string studentID);
	void printAll();
	void printAvgDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	
	int lastIndex = -1;
	const static int studentDataSize = 5;
	Student* classRosterArray[studentDataSize];

	~Roster();


};
