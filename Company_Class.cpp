#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Company_Class.h"
using namespace std;

Company::Company(){
    cout<<"Enter name of Company: "<<endl;
    cin.ignore();
    getline(cin, companyName);
    cout<<"Enter package to be offered (LPA): "<<endl;
    cin>>Package;
    cout<<"Enter eligibility CGPA for placement: "<<endl;
    cin>>eligibilityCGPA;
    cout<<"Set PIN: "<<endl;
    cin>>cPIN;
}

Company::Company(string companyName, double Package, float eligibilityCGPA, int cPIN){
    this->companyName=companyName;
    this->eligibilityCGPA=eligibilityCGPA;
    this->Package=Package;
    this->cPIN=cPIN;
}

void Company::DisplayCompany(){
    cout<<"\n=== COMPANY DETAILS ==="<<endl;
    cout<<"COMPANY NAME:     "<<companyName<<endl;
    cout<<"PACKAGE OFFERED:  "<<Package<<" LPA"<<endl;
    cout<<"ELIGIBILITY CGPA: "<<eligibilityCGPA<<endl;
}

void Company::PrintCompany(){
    ofstream myFileC("Company_data.txt", ios::app);
    if(myFileC.is_open()){
        myFileC<<companyName<<endl;
        myFileC<<Package<<endl;
        myFileC<<eligibilityCGPA<<endl;
        myFileC<<cPIN<<endl;
        myFileC<<"-----------------------------------------"<<endl;
        myFileC.close();
    }
}

string Company::Name(){
    return companyName;
}

float Company::CG(){
    return eligibilityCGPA;
}

vector<string> File1(){
    ifstream myFileC("Company_data.txt");
    string str;
    vector<string> data;
    if (myFileC.is_open()){
        while (getline(myFileC, str)){
            data.push_back(str);
        }
        myFileC.close();
    }
    return data;
}

vector<Company> collectData1(){
    vector<string> data = File1();
    if(data.empty()) return vector<Company>();
    
    int total = data.size();
    string cmp_nm;
    float el_cg;
    double pckg;
    int pin;
    vector<Company> Records;
    
    for(int i=0; i < total; i+=5){
        cmp_nm = data[i];
        pckg = stod(data[i+1]);
        el_cg = stof(data[i+2]);
        pin = stoi(data[i+3]);
        Company cmp(cmp_nm, pckg, el_cg, pin);
        Records.push_back(cmp);
    }
    return Records;
}

void addCompany(){
    Company* ptr = new Company();
    ptr->PrintCompany();
    delete ptr;
    cout<<"Company added successfully!"<<endl;
}