
#include <iostream>
using namespace std;

#include "student.h" 

void Student::SetStudentId(string studentId) {
	id = studentId;

	return;
}

void Student::SetFirstName(string fName) {
	firstName = fName;

	return;
}

void Student::SetLastName(string lName) {
	lastName = lName;

	return;
}

void Student::SetEmail(string eAddress) {
	email = eAddress;

	return;
}

void Student::SetAge(int years) {
	age = years;

	return;
}

void Student::SetDays(int daysA, int daysB, int daysC) {
	days[0] = daysA;
	days[1] = daysB;
	days[2] = daysC;

	return;
}


string  Student::GetStudentId() const {
	return id;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmail() const {
	return email;
}

int  Student::GetAge() const {
	return age;
}



int  Student::GetDaysA() const {
	return days[0];
}

int  Student::GetDaysB() const {
	return days[1];
}

int  Student::GetDaysC() const {
	return days[2];
}








//default constructor
Student::Student() {
	firstName = "None";
	lastName = "None";
	email = "None";
	age = 0;
	days[0] = 0;
	days[1] = 0;
	days[2] = 0;

	return;
}

//CONSTRUCTOR

Student::Student(string uId, string fName, string lName, string emailAddr, int years, int daysA, int daysB, int daysC) {
	id = uId;
	firstName = fName;
	lastName = lName;
	email = emailAddr;
	age = years;
	days[0] = daysA;
	days[1] = daysB;
	days[2] = daysC;

	return;
}

//DECONSTRUCTOR
Student::~Student() {
}

void Student::print()
{
	cout << "Student Id: " <<  GetStudentId() << "\tFirst Name: " << GetFirstName() <<  "\tLastName: " << GetLastName() <<  "\tAge: " << GetAge() << "\tdaysInCourse: {" << GetDaysA() << ", " << GetDaysB() << ", " << GetDaysC() << "}" << "\tDegree Program: ";
	
	return;
}

Degree Student::getDegreeProgram() const
{
	return degree;
}

