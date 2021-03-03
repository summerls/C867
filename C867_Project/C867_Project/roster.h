#ifndef ROSTER_H
#define ROSTER_H

#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"

class roster {

private:

protected:
	int rosterSize = 0;
	Student** classArrayRoster = new Student*[rosterSize];
	int rosterCounter = 0;

public:
	 void setRosterSize(int size);
	roster();
	~roster();
	int getRosterSize();
	void parseRoster(string input);
	void printByDegreeProgram(int deg);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program);
	void remove(string studentID);
	void printAll();
	void printInvalidEmails();
	void printDaysInCourse(string stuId);
	Student* getRoster(int ind);
};

#endif

