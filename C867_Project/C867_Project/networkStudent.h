#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include <iostream>
using namespace std;

#include "student.h"

class networkStudent : public Student {
public:
	networkStudent();
	networkStudent(string userId, string fName, string lName, string emailAddr, int years, int daysA, int daysB, int daysC, Degree degreeType);

	Degree getDegreeProgram();
	void print();

	~networkStudent();

private:
};

#endif