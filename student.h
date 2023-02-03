#pragma once
#include <string>
#include <iostream>
#include "degree.h"
using namespace std;

class Student {

public:

	//accessors
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setNumOfDays(int numOfDays[]);
	void setDegree(DegreeProgram degree);

	//mutators
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getNumOfDays();
	DegreeProgram getDegree();

	//var set to number of degrees in set
	const static int numOfDaysSize = 3;

	//student const
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress,
		int age, int numOfDays[], DegreeProgram degreeProgram);

	void print();

	//deconstructor
	~Student();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* numOfDays;
	DegreeProgram degreeProgram;
};


