#include <iostream>
using namespace std; 
#include <sstream>

#include "roster.h"



roster::~roster() {
    for (int z = getRosterSize()-1; z >= 0; z--) {
        classArrayRoster[z] = nullptr;
        delete classArrayRoster[z];
    }
}

roster::roster()
{
    for (int i = 0; i < rosterSize; i++) classArrayRoster[i] = nullptr;
    return;
}

void roster::parseRoster(string input) {
    string firstName = "";
    string lastName = "";
    string emailAddress = "";
    string ageString = "";
    string days1String = "";
    string days2String = "";
    string days3String = "";
    string deg = "";
    string usrId;

    int sectionOfString = 0;

    for (int traverseCounter = 0; traverseCounter < input.length(); traverseCounter++) {

        if (traverseCounter == input.length()-1) {
            if (input.back() == 'Y')  add(usrId, firstName, lastName, emailAddress, stoi(ageString), stoi(days1String), stoi(days2String), stoi(days3String), SECURITY);
            else if (input.back() == 'E') add(usrId, firstName, lastName, emailAddress, stoi(ageString), stoi(days1String), stoi(days2String), stoi(days3String), SOFTWARE);
            else if (input.back() == 'K') add(usrId, firstName, lastName, emailAddress, stoi(ageString), stoi(days1String), stoi(days2String), stoi(days3String), NETWORK);
        }
        else {
            switch (input[traverseCounter]) {
            case ',':
                sectionOfString++;
                traverseCounter++;

            default:
                if ((sectionOfString == 0) && (input[traverseCounter] != ',')){
                    usrId.append(input.substr(traverseCounter,1));
                }
                if ((sectionOfString == 1) && (input[traverseCounter] != ',')) {
                    firstName.append(input.substr(traverseCounter, 1));
                }
                if (sectionOfString == 2) {
                    lastName.append(input.substr(traverseCounter, 1));
                }
                if (sectionOfString == 3) {
                    int tcounter = traverseCounter + 1;
                    emailAddress.append(input.substr(tcounter, 1));
                }
                if (sectionOfString == 4) {
                    ageString.append(input.substr(traverseCounter, 1));
                }
                if (sectionOfString == 5) {
                    days1String.append(input.substr(traverseCounter, 1));
                }
                if (sectionOfString == 6) {
                    days2String.append(input.substr(traverseCounter, 1));
                }
                if (sectionOfString == 7) {
                    days3String.append(input.substr(traverseCounter, 1));
                }    
            }
        }
    }

    return;
    
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program) {
    if (program == SECURITY) {
        classArrayRoster[rosterCounter] = new securityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, SECURITY);
        rosterCounter++;
    }
    else if (program == SOFTWARE) {
        classArrayRoster[rosterCounter] = new softwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, SOFTWARE);
        rosterCounter++;
    }
    else if (program == NETWORK) {
        classArrayRoster[rosterCounter] = new networkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, NETWORK);
        rosterCounter++;
    }

    return;
}

void roster::printAll() {
    for (int n = 0; n < rosterSize; n++) {
        this->classArrayRoster[n]->print();
    }
    return;
}

Student* roster::getRoster(int ind) {
    return classArrayRoster[ind];
}

void roster::setRosterSize(int size) {
    rosterSize = size;
    return;
}

int roster::getRosterSize() {
    return rosterSize;
}

void roster::remove(string id) {
    bool found = false;
    for (int x = 0; x < getRosterSize(); x++) {
        //Loop if id matches
        if (classArrayRoster[x]->GetStudentId() == id) {
            found = true;
            for (int y = x; y < getRosterSize()-1; y++) {
                classArrayRoster[y] = classArrayRoster[y + 1];
                classArrayRoster[getRosterSize()] = nullptr;
                delete classArrayRoster[getRosterSize()];
            }
            setRosterSize(rosterSize - 1);
            break;
        }
        //End of loop

    }
        if (found == 0) cout << "A student with the specified id was not found." << endl;  
        return;
}

void roster::printDaysInCourse(string studentID) {
    for (int x = 0; x < rosterSize; x++) {
        if (classArrayRoster[x]->GetStudentId() == studentID) {
            int total = classArrayRoster[x]->GetDaysA() + classArrayRoster[x]->GetDaysB() + classArrayRoster[x]->GetDaysC();
            double average = total/3;
            cout << " Average of days in course: " << average << "." << endl;
        }
    }
    return;
}

void roster::printByDegreeProgram(int degreeProgram) {
    for (int x = 0; x < rosterSize; x++) {
        if (classArrayRoster[x]->getDegreeProgram() == degreeTypes[degreeProgram]) {
            classArrayRoster[x]->print();
        }
    }
    return;
}

void roster::printInvalidEmails() {
    
    for (int x = 0; x < rosterSize; x++) {
        bool hasDot = false;
        bool hasAt = false;
        bool hasSpace = false;
        string email = classArrayRoster[x]->GetEmail();

        for (int y = 0; y < email.length(); y++) {
            if (email[y] == '.') hasDot = true;
            if (email[y] == '@') hasAt = true;
            if (email[y] == ' ') hasSpace = true;
        }
        if ((hasSpace == 1 )|| (hasAt == 0) || (hasDot == 0)) cout << email << " is an invalid email address" << endl;
    }
    return;
}

int main() {
    cout << "Course Title: Scripting and Programming - Applications\tProgramming Language: C++\tStudent Id: A5\tName: Summer Schinagl" << endl;

    roster classRoster;
    int const rosterS = 5;
    classRoster.setRosterSize(rosterS);

    string studentOne[rosterS] = {
        "AB, John, Smith, John1989@gm ail.com, 20, 30, 35, 40, SECURITY",
        "A2, Suzane, Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORK",
        "A3, Jack, Napoli, The_lawyer99yahoo.com, 19, 20, 40, 33, SOFTWARE",
        "A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
        "A5, Summer, Schinagl, summerschinagl@gmail.com, 31, 25, 30, 35, SOFTWARE"
};

    cout << "Parsing in progress..." << endl;
    for (int x = 0; x < rosterS; x++) {
        classRoster.parseRoster(studentOne[x]);
    }   
    cout << endl;

    cout << "PRINT ALL: " << endl;
    classRoster.printAll();
    cout << endl;

    cout << "INVALID EMAILS: " << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "PRINTING DAYS IN COURSE..." << endl;
    for (int z = 0; z < rosterS; z++) {
        string id = classRoster.getRoster(z)->GetStudentId();
        cout << "For Student Id: " << id << endl;
        classRoster.printDaysInCourse(id);
    }
    cout << endl;
    
    cout << "PRINT BY DEGREE PROGRAM SOFTWARE: " << endl;
    classRoster.printByDegreeProgram(2);
    cout << endl;
    cout << "REMOVE STUDENT WITH ID OF A3: " << endl;
    classRoster.remove("A3");
    classRoster.printAll();
    cout << endl;
    cout << "REMOVE STUDENT WITH ID OF A3: " << endl;
    classRoster.remove("A3");
  
  return 0;
}
