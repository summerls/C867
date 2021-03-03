#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <iostream>
using namespace std;

#include "student.h" 



class softwareStudent : public Student {
public:
	softwareStudent();
	softwareStudent(string sId, string fName, string lName, string emailAddr, int years, int daysA, int daysB, int daysC, Degree degreeType);

	Degree getDegreeProgram();
	void print();

	~softwareStudent();
private:
};

#endif