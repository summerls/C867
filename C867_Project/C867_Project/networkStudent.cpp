#include <iostream>
using namespace std;

#include "networkStudent.h"

networkStudent::networkStudent() 
	:Student() {
	degree = NETWORK;
	return;
}

networkStudent::networkStudent(string uId, string fName, string lName, string emailAddr, int years, int daysA, int daysB, int daysC, Degree degreeProgram)
	:Student(uId, fName, lName, emailAddr, years, daysA, daysB, daysC) {
	degree = degreeProgram;
	return;
}

Degree networkStudent::getDegreeProgram() {
	return NETWORK;
}

void networkStudent::print() {
	this->Student::print();
	cout << "NETWORK" << endl;
	return;
}

networkStudent::~networkStudent() {
	Student::~Student();
	return;
}