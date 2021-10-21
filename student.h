#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student{
private:	
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int *daysInCourse;
	DegreePlan degreeProgram;

public:
	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int *getDaysInCourse();
	DegreePlan getDegreeProgram();

	//setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreePlan degreeProgram);

	//constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[], DegreePlan degreeProgram);
	~Student();

	void print();
};


