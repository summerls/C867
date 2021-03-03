#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <iostream>
using namespace std;

#include "student.h" 

class securityStudent : public Student {
public:
	securityStudent();
	securityStudent(string sId, string fName, string lName, string emailAddr, int years, int daysA, int daysB, int daysC, Degree degreeType);

	Degree getDegreeProgram();
	void print();

	~securityStudent();
private:
};

#endif