#include <iostream>
#include "roster.h"
using namespace std;

int main()
{
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Justin,Guzman,jguzm28@my.wgu.edu,31,11,22,35,SOFTWARE"
	};

	const int numStudents = 5;

	cout << "Course: C867 Scripting and Programming- Applications" << endl;
	cout << "Programming Language: C++ compiled in Visual Studio" << endl;
	cout << "WGU ID: 812901" << endl;
	cout << "Justin Guzman" << endl;

	cout << endl;

	Roster classRoster;

	//adding all students to roster
	for (int i = 0; i < numStudents; i++) {
		classRoster.parse(studentData[i]);
	}

	cout << "Student Data: " << endl;
	classRoster.printAll();

	cout << "Invalid emails in Student Data: " << endl;
	classRoster.printInvalidEmails();

	//looping through students to output all avgDays
	string studentID;
	for (int i = 0; i < numStudents; i++) {
		studentID = "A" + to_string(i+1);
		cout << studentID << endl;
		classRoster.printAverageDaysInCourse(studentID);
	}
	
	classRoster.printByDegreeProgram(SOFTWARE);

	//removing student A3 and verifying that the student was removed
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	
	return 0;
}