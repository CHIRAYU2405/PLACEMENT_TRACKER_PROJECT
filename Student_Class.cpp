#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Student_Class.h"
using namespace std;

Student::Student(){
    string f, l;
    cout<<"Enter First Name: ";
    cin>>f;
    cout<<"Enter Last Name: ";
    cin>>l;
    name = f + " " + l;
    cout<<"Enter Roll no: ";
    cin>>roll_no;
    cout<<"Enter Branch: ";
    cin>>branch;
    cout<<"Enter CGPA: ";
    cin>>CGPA;
    cout<<"Enter Contact no: ";
    cin>>contact_no;
    cout<<"Set PIN: ";
    cin>>sPIN;
    placed = false;           // ADD THIS
    placedCompany = "None";   // ADD THIS
}

Student::Student(string name, double roll_no, string branch, double contact_no, float CGPA, int sPIN){
    this->name = name;
    this->branch = branch;
    this->roll_no = roll_no;
    this->contact_no = contact_no;
    this->CGPA = CGPA;
    this->sPIN = sPIN;
    this->placed = false;           // ADD THIS
    this->placedCompany = "None";   // ADD THIS
}

void Student::DisplayStudent(){
    cout<<"\n=== STUDENT DETAILS ==="<<endl;
    cout<<"NAME:      "<<name<<endl;
    cout<<"ROLL NO:   "<<roll_no<<endl;
    cout<<"BRANCH:    "<<branch<<endl;
    cout<<"CONTACT:   "<<contact_no<<endl;
    cout<<"CGPA:      "<<CGPA<<endl;
    cout<<"STATUS:    "<<(placed ? "PLACED" : "NOT PLACED");  // ADD THIS
    if(placed) cout<<" at "<<placedCompany;
    cout<<endl;
}

void Student::PrintStudent(){
    ofstream myFileS("Student_data.txt", ios::app);
    if(myFileS.is_open()){
        myFileS<<name<<endl;
        myFileS<<roll_no<<endl;
        myFileS<<branch<<endl;
        myFileS<<contact_no<<endl;
        myFileS<<CGPA<<endl;
        myFileS<<sPIN<<endl;
        myFileS<<placed<<endl;           // ADD THIS
        myFileS<<placedCompany<<endl;    // ADD THIS
        myFileS<<"-----------------------------------------"<<endl;
        myFileS.close();
    }
}

string Student::Name(){
    return name;
}

float Student::CG(){
    return CGPA;
}

vector<string> File(){
    ifstream myFileS("Student_data.txt");
    string str;
    vector<string> data;
    if (myFileS.is_open()){
        while (getline(myFileS, str)){
            data.push_back(str);
        }
        myFileS.close();
    }
    return data;
}

vector<Student> collectData(){
    vector<string> data = File();
    if(data.empty()) return vector<Student>();
    
    int total = data.size();
    string nm, br, placedComp;
    float cg;
    double rn, cn;
    int pin;
    bool placedStatus;
    vector<Student> Records;
    
    for(int i=0; i < total; i+=9){  // CHANGED from 7 to 9
        if(i+8 >= total) break;
        nm = data[i];
        rn = stod(data[i+1]);
        br = data[i+2];
        cn = stod(data[i+3]);
        cg = stof(data[i+4]);
        pin = stoi(data[i+5]);
        placedStatus = (data[i+6] == "1");
        placedComp = data[i+7];
        
        Student st(nm, rn, br, cn, cg, pin);
        st.setPlaced(placedStatus);
        st.setPlacedCompany(placedComp);
        Records.push_back(st);
    }
    return Records;
}

void addStudent(){
    Student* ptr = new Student();
    ptr->PrintStudent();
    delete ptr;
    cout<<"Student added successfully!"<<endl;
}
