#include <iostream>
using namespace std; 
#include "softwareStudent.h"

softwareStudent::softwareStudent()
	:Student(){
	degree = SECURITY;
	return;
}

softwareStudent::softwareStudent(string sId, string fName, string lName, string emailAddr, int years, int daysA, int daysB, int daysC, Degree degreeProgram)
	:Student(sId, fName, lName, emailAddr, years, daysA, daysB, daysC) {
	degree = degreeProgram;
	return;
}

Degree softwareStudent::getDegreeProgram() {
	return SOFTWARE;
}

void softwareStudent::print() {
	this->Student::print();
	cout << "SOFTWARE" << endl;
	return;
}

softwareStudent::~softwareStudent() {
	Student::~Student();
	return;
}