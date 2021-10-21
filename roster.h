#include "student.h"
#include "degree.h"
using namespace std;
#pragma once

class Roster{
	public: void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreePlan degreeProgram);
			void remove(string studentID);
			void printAll();
			void printAverageDaysInCourse(string studentID);
			void printInvalidEmails();
			void printByDegreeProgram(DegreePlan degreeProgram);
			Student* classRosterArray[5];
			int studentNumber = 0;
			bool studentExists;

			Roster(const string studentData[]);
			~Roster();
};

