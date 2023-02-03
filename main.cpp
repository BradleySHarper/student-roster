/*
* C867PA
* Author:  Bradley Harper
*/

#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
using namespace std;

//creates instance of Roster class
Roster classRoster;

int main() {

	cout << "C867-Scripting and Programming Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 001547272" << endl;
	cout << "Name: Bradley Harper" << endl;
	cout << "---------------------------------------------" << endl;
	cout << endl;

	//arrray of strings for parsing (extra spaces for proper print view)
	const string studentData[] = {
		"A1,John,Smith    ,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson ,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli   ,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black    ,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Bradley,Harper   ,bharp47@wgu.edu,40,23,46,71,SOFTWARE"
	};

	//var setting studentData array size
	const int studentDataSize = 5;

	//takes Roster object uses parse() then prints all()
	Roster roster;
	for (int i = 0; i < studentDataSize; i++) roster.parse(studentData[i]);
	cout << "Displaying all students: " << endl;
	cout << endl;
	roster.printAll();
	cout << endl;

	//prints out invalid emails
	cout << "Displaying invalid emails:" << std::endl;
	cout << endl;
	roster.printInvalidEmails();
	cout << std::endl;

	//prints average days in 3 courses for each Student, using getStudentID() mutator as parameter
	cout << "Average days for all students:" << std::endl;
	cout << endl;
	for (int i = 0; i < studentDataSize; i++) {
		string sID = roster.classRosterArray[i]->getStudentID();
		roster.printAvgDaysInCourse(sID);
	}
	cout << endl;

	//prints by degree program, specifically SOFTWARE here as required by rubric
	cout << "Showing students in degree program: SOFTWARE";
	cout << endl;
	cout << endl;
	roster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	//Removes student A3, then prints all
	cout << "Remove student A3: " << endl;
	cout << endl;
	roster.removeStudent("A3");
	roster.printAll();
	cout << endl;

	//Attempting to remove student A3 again, which will fail and display message defined in method
	cout << "Removing student A3 again: " << std::endl;
	cout << endl;
	roster.removeStudent("A3");
	cout << endl;

	//deconstruct
	cout << "Done";

	return 0;

}