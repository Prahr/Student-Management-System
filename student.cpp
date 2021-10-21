#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>

//class constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreePlan degreeProgram){
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse = new int[3];
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
    this->degreeProgram = degreeProgram;
}

//getters
string Student::getStudentID(){
    return studentID;
}

string Student::getFirstName(){
    return firstName;
}

string Student::getLastName(){
    return lastName;
}

string Student::getEmail() {
    return emailAddress;
}

int Student::getAge() {
    return age;
}

int *Student::getDaysInCourse() {
    return daysInCourse;
}

DegreePlan Student::getDegreeProgram() {
    return degreeProgram;
}

//setters
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(string lastName) {
    this->lastName = lastName;
}

void Student::setEmail(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
    this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[]) {
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}

void Student::setDegreeProgram(DegreePlan degreeProgram) {
    this->degreeProgram = degreeProgram;
}

void Student::print() {
    cout << studentID << "\t" << "First Name: " << firstName << "\t" << "Last Name: " << lastName << "\t" << "Age: " << age << "\t" << "Days In Course: " << "{" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "} Degree Program: " << changeToString[getDegreeProgram()] << " ";
}

Student::~Student() {

}