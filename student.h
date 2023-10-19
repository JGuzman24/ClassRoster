#pragma once
#include "degree.h"
#include <iomanip>
#include <iostream>
using namespace std;

class Student
{
public:
	const static int classes = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToComplete[classes] = { 0,0,0 };
	DegreeProgram degree;

public:
	void print();

	//empty constructor
	Student();

	//full constructor
	Student(string studentID, string firstName, string lastName, string email,
		int age, int daysToComplete[], DegreeProgram degree);

	~Student();

	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToComplete();
	DegreeProgram getDegree();

	//setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int daysToComplete[]);
	void setDegree(DegreeProgram degree);




};
