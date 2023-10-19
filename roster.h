#pragma once
#include <iostream>
#include "student.h"
using namespace std;

class Roster {

private:
	// Need lastIndex to fill classRosterArray
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:

	void add(string studentID, string firstName, string lastName, string email,
		int age, int days1, int days2, int days3, DegreeProgram degree);

	void parse(string studentData);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree);
	
	~Roster();

};
