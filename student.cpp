#include <iostream>
#include "student.h"
using namespace std;

Student::Student() { 
    
    //Default Constructor Values
    this->studentID = "Student ID";
    this->firstName = "First Name";
    this->lastName = "Last Name";
    this->email = "Email Address";
    this->age = 0;
    this->daysToComplete[0] = 0;
    this->daysToComplete[1] = 0;
    this->daysToComplete[2] = 0;
    this->degree = DegreeProgram::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string email,
	int age, int daysToComplete[], DegreeProgram degree) {
    
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->degree = degree;

    //Filling daysToComplete array
    for (int i = 0; i < classes; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
        
  
}

Student::~Student() {}

string Student::getStudentID() {
    return this->studentID;
}
string Student::getFirstName() {
    return this->firstName;
}
string Student::getLastName() {
    return this->lastName;
}
string Student::getEmail() {
    return this->email;
}
int Student::getAge() {
    return this->age;
}
int* Student::getDaysToComplete() {
    return this->daysToComplete;
}
DegreeProgram Student::getDegree() {
    return this->degree;
}


void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setEmail(string email) {
    this->email = email;
}
void Student::setAge(int age) {
    this->age = age;
}
void Student::setDegree(DegreeProgram degree) {
    this->degree = degree;
}

void Student::setDaysToComplete(int daysToComplete[]) {
    
    //Filling daysToComplete array
    for (int i = 0; i < classes; i++) {
        this->daysToComplete[i] = daysToComplete[i];
    }
    
}

//Print format
void Student::print() {
    cout << this->getStudentID() ;
    cout << '\t' << this->getFirstName();
    cout << ' ' << this->getLastName();
    cout << '\t' << this->getEmail();
    cout << '\t' << this->getAge();
    cout << '\t' << this->getDaysToComplete()[0] << ',';
    cout << this->getDaysToComplete()[1] << ',';
    cout << this->getDaysToComplete()[2];
    cout << '\t' << degreeStrings[this->getDegree()] << endl;
}