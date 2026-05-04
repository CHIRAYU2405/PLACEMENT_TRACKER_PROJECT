#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Student{
    string name;
    string branch;
    double roll_no;
    double contact_no;
    float CGPA;
    int sPIN;
    bool placed;           // ADD THIS
    string placedCompany;  // ADD THIS

    public:
    Student();
    Student(string name, double roll_no, string branch, double contact_no, float CGPA, int sPIN);
    void DisplayStudent();
    void PrintStudent();
    friend class Placement;
    string Name();
    float CG();
    
    // ADD THESE GETTERS/SETTERS
    bool isPlaced() { return placed; }
    void setPlaced(bool p) { placed = p; }
    void setPlacedCompany(string c) { placedCompany = c; }
    string getPlacedCompany() { return placedCompany; }
};

vector<string> File();
vector<Student> collectData();
void addStudent();

#endif
