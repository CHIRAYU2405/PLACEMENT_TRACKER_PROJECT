#ifndef COMPANY_CLASS_H
#define COMPANY_CLASS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Company{
    string companyName;
    double Package;
    float eligibilityCGPA;
    int cPIN;

    public:
    Company();
    Company(string companyName, double Package, float eligibilityCGPA, int cPIN);
    void DisplayCompany();
    void PrintCompany();
    friend class Placement;
    string Name();
    float CG();
};

vector<string> File1();
vector<Company> collectData1();
void addCompany();

#endif