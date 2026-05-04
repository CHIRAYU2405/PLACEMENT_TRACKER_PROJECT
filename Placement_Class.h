#ifndef PLACEMENT_CLASS_H
#define PLACEMENT_CLASS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Student_Class.h"
#include "Company_Class.h"
using namespace std;

class Placement{
    string studentName;
    string companyName;
    bool Placed;

    public:
    static vector<Student> StudentVector;
    static vector<Company> CompanyVector;

    Placement();
    Placement(string studentName, string companyName, bool Placed);
    void DisplayPlacement();
    void PrintPlacement();
    bool eligibilty(Student s, Company c);
    static void printEligibleStudents();
    static void showStatistics();
};

vector<string> File2();
vector<Placement> collectData2();
void addPlacement(Student s, Company c);
void conductDrive();

#endif
