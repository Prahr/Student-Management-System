#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "roster.h"
#include "degree.h"
#include "student.h"
using namespace std;

Roster::Roster(const string studentData[]) {
	int arraySize = 5;

	for (int i = 0; i < arraySize; i++) {
		//parse studentData
		string holderStr = studentData[i];
		vector<string> result;
		stringstream stringStream(holderStr);

		while (stringStream.good()) {
			string substr;
			getline(stringStream, substr, ',');
			result.push_back(substr);
		}

		//assign vectors
		string holdStudentID = result.at(0);
		string holdFirstName = result.at(1);
		string holdLastName = result.at(2);
		string holdEmail = result.at(3);
		int holdAge = stoi(result.at(4));
		int holdDaysInCourse[3];
		for (int h = 0; h < 3; h++) {
			int holdDays = stoi(result.at(h + 5));
			holdDaysInCourse[h] = holdDays;
		}
		DegreePlan holdDegree;
		if (result[8].compare("NETWORK") == 0){
			holdDegree = NETWORK;
		}
		else if (result[8].compare("SECURITY") == 0){
			holdDegree = SECURITY;
		}
		else if (result[8].compare("SOFTWARE") == 0){
			holdDegree = SOFTWARE;
		}

		Roster::add(holdStudentID, holdFirstName, holdLastName, holdEmail, holdAge, holdDaysInCourse[0], holdDaysInCourse[1], holdDaysInCourse[2], holdDegree);
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreePlan degreeProgram) {
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[studentNumber] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
	studentNumber++;
}

void Roster::remove(string studentID) {
	studentExists = false;
	for (int i = 0; i <= studentNumber; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			classRosterArray[i] = classRosterArray[studentNumber - 1];
			studentNumber--;
			studentExists = true;
		}
	}
	if (studentExists) {
		cout << studentID << " removed. ";
	}
	else if (!studentExists) {
		cout << "Error, student not found. ";
	}
}

void Roster::printAll() {
	for (int i = 0; i < studentNumber; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < studentNumber; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			int* holderArray = classRosterArray[i]->getDaysInCourse();
			int averageDaysInCourse = (holderArray[0] + holderArray[1] + holderArray[2]) / 3;
			cout << " Average days in course: " << averageDaysInCourse;
		}
	}
}

void Roster::printInvalidEmails() {
	bool emailFound = false;
	cout << "List of bad emails: ";
	for (int i = 0; i < studentNumber; i++) {
		string holderString = classRosterArray[i]->getEmail();

		if (holderString.find("@") == string::npos || holderString.find(".") == string::npos || !holderString.find(" ") == string::npos) {
			cout << holderString;
			emailFound = true;
		}
	}

	if (!emailFound) {
		cout << "None";
	}
}

void Roster::printByDegreeProgram(DegreePlan degreeProgram) {
	for (int i = 0; i < studentNumber; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {
	delete []classRosterArray;
}