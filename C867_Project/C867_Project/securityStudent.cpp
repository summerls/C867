#include <iostream>
using namespace std;

#include "securityStudent.h"

securityStudent::securityStudent() 
	:Student() {
	degree = SECURITY;
	return;
}

securityStudent::securityStudent(string sId, string fName, string lName, string emailAddr, int years, int daysA, int daysB, int daysC, Degree degreeProgram) 
	:Student(sId, fName, lName, emailAddr, years, daysA, daysB, daysC){
	degree = degreeProgram;
	return;
}

Degree securityStudent::getDegreeProgram() {
	return SECURITY;
}

void securityStudent::print() {
	this->Student::print();
	cout << "SECURITY" << endl;
	return;
}

securityStudent::~securityStudent() {
	Student::~Student();
	return;
}