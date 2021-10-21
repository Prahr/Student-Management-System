#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"
#include "degree.h"

int main()
{
	cout << "Scripting and Programming Applications \n";
	cout << "Programming Language: C++ \n";
	cout << "Student ID: 003936554 \n";
	cout << "Ryan Wachter \n";

	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Ryan,Wachter,rwacht4@wgu.edu,28,20,25,23,SOFTWARE"
	};

	Roster* classRoster = new Roster(studentData);

	classRoster->printAll();
	classRoster->printInvalidEmails();
	for (int i = 0; i < classRoster->studentNumber; i++) {
		classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentID());
	}
	classRoster->printByDegreeProgram(SOFTWARE);
	classRoster->remove("A3");
	classRoster->printAll();
	classRoster->remove("A3");
	classRoster->~Roster();
}

