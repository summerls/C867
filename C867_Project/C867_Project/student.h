#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "degree.h" 

using namespace std;

class Student {

public:
	//MUTATORS
	void SetStudentId(string studentId); //
	void SetFirstName(string fName);
	void SetLastName(string lName);
	void SetEmail(string eAddress);
	void SetAge(int years);
	void SetDays(int daysA, int daysB, int daysC);

	//ACCESSORS
	string  GetStudentId() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmail() const;
	int GetAge() const;
	int GetDaysA() const;
	int GetDaysB() const;
	int GetDaysC() const;




	//CONSTRUCTOR
	Student();
	Student(string uId, string fName, string lName, string emailAddr, int years, int daysA, int daysB, int daysC);

	//DECONSTRUCTOR
	~Student();

	//VIRTUAL PRINT
	virtual void print();

	//GET DEGREE
	virtual Degree getDegreeProgram() const;

protected:
	Degree degree;

private:
	string id;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[3];
};

#endif
