#include <iostream>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"
#include <vector>
using namespace std;

void Roster::parse(string studentData) {

	//creating string stream to pull data
	string studentInfo = studentData;
	vector<string> varData;
	stringstream sLine(studentInfo);

	//takes data points from input line  
	//delimeted with commas
	while (sLine.good()) {
		string data;
		getline(sLine, data, ',');
		varData.push_back(data);
	}

	//assinging variables to strings
	string studentID = varData[0];
	string firstName = varData[1];
	string lastName = varData[2];
	string email = varData[3];

	//using string to int for numbers in studentData
	int age = stoi(varData[4]);
	int daysInCourse1 = stoi(varData[5]);
	int daysInCourse2 = stoi(varData[6]);
	int daysInCourse3 = stoi(varData[7]);

	//assigning degree based on student's Program
	DegreeProgram degree;
	if (varData[8] == "SECURITY") {
		degree = SECURITY;
	}
	else if (varData[8] == "NETWORK") {
		degree = NETWORK;
	}
	else degree = SOFTWARE;

	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
	
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree)
{
	int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, days, degree);
	
}

void Roster::remove(string studentID) {

	for (int i = 0; i < numStudents; i++) {

		if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentID() == studentID)) {

			classRosterArray[i] = nullptr;

			cout << studentID << " has been removed." << endl;
		}
		else if (classRosterArray[i] == nullptr) {

			cout << studentID << " was not found." << endl;
		}
	}
	cout << endl;
}

void Roster::printAll() {

	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	int sumDays;
	double avgDays;
	cout << "Average days in course for Student: " << studentID << endl;
	for (int i = 0; i < numStudents; i++) {
		
		if (classRosterArray[i]->getStudentID() == studentID) {
			sumDays = (classRosterArray[i]->getDaysToComplete()[0]) + (classRosterArray[i]->getDaysToComplete()[1]) + (classRosterArray[i]->getDaysToComplete()[2]);
			avgDays = sumDays / 3.0;
			cout << studentID << ": " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName()
				<< " - " << avgDays << endl;
		}
	}
	cout << endl;
}

void Roster::printInvalidEmails() {

	bool valid = true;
	for (int i = 0; i < numStudents; i++) {
		string email = classRosterArray[i]->getEmail();

		if (email.find('@') == string::npos) {
			cout << email << " : missing '@' symbol" << endl;
			valid = false;
		}
		if (email.find('.') == string::npos) {
			cout << email << " : missing a period" << endl;
			valid = false;
		}
		if (email.find(' ') != string::npos) {
			cout << email << " : cannot contain a space" << endl;
			valid = false;
		}
	}
	if (valid == true) {
		cout << "All emails are valid" << endl;
	}
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degree) {

	cout << "Students in " << degreeStrings[degree] << " Program:" << endl;

	for (int i = 0; i < numStudents; i++) {
		if (Roster::classRosterArray[i]->getDegree() == degree) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

Roster::~Roster()
{
	cout << "Initiating destructor" << endl;

	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}


