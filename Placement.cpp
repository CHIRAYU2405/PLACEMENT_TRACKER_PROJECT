#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include "Student_Class.h"
#include "Company_Class.h"
#include "Placement_Class.h"
using namespace std;

vector<Student> Placement::StudentVector = collectData();
vector<Company> Placement::CompanyVector = collectData1();

Placement::Placement(){}

Placement::Placement(string studentName, string companyName, bool Placed){
    this->studentName = studentName;
    this->companyName = companyName;
    this->Placed = Placed;
}

void Placement::DisplayPlacement(){
    cout<<"\n=== PLACEMENT RECORD ==="<<endl;
    cout<<"STUDENT: "<<studentName<<endl;
    cout<<"COMPANY: "<<companyName<<endl;
    cout<<"STATUS:  "<<(Placed ? "PLACED" : "NOT PLACED")<<endl;
}

void Placement::PrintPlacement(){
    ofstream myFileP("PlacementRecords.txt", ios::app);
    if(myFileP.is_open()){
        myFileP<<studentName<<endl;
        myFileP<<companyName<<endl;
        myFileP<<(Placed ? "PLACED" : "NOT PLACED")<<endl;
        myFileP<<"-----------------------------------------"<<endl;
        myFileP.close();
    }
}

bool Placement::eligibilty(Student s, Company c){
    return s.CGPA >= c.eligibilityCGPA;
}

vector<string> File2(){
    ifstream myFileP("PlacementRecords.txt");
    string str;
    vector<string> data;
    if (myFileP.is_open()){
        while (getline(myFileP, str)){
            data.push_back(str);
        }
        myFileP.close();
    }
    return data;
}

vector<Placement> collectData2(){
    vector<string> data = File2();
    if(data.empty()) return vector<Placement>();
    
    int total = data.size();
    string st_nm, cmp_nm;
    bool k;
    vector<Placement> Records;
    
    for(int i=0; i < total; i+=4){
        st_nm = data[i];
        cmp_nm = data[i+1];
        k = (data[i+2] == "PLACED");
        Placement p(st_nm, cmp_nm, k);
        Records.push_back(p);
    }
    return Records;
}

void addPlacement(Student s, Company c){
    Placement temp;
    if(temp.eligibilty(s, c)){
        bool k;
        cout<<"Is "<<s.Name()<<" placed? (1 for YES, 0 for NO): ";
        cin>>k;
        Placement* p = new Placement(s.Name(), c.Name(), k);
        p->PrintPlacement();
        delete p;
        cout<<"Placement record saved!"<<endl;
    } else {
        cout<<"Student ineligible! CGPA "<<s.CG()<<" < "<<c.CG()<<endl;
    }
}

void Placement::printEligibleStudents(){
    cout<<"\n=== ELIGIBLE STUDENTS PER COMPANY ==="<<endl;
    
    for(int i=0; i < CompanyVector.size(); i++){
        cout<<"\nCOMPANY: "<<CompanyVector[i].Name()<<endl;
        cout<<"Min CGPA Required: "<<CompanyVector[i].CG()<<endl;
        cout<<"-----------------------------------"<<endl;
        
        int count = 0;
        for(int j=0; j < StudentVector.size(); j++){
            if(StudentVector[j].CG() >= CompanyVector[i].CG() && !StudentVector[j].isPlaced()){
                cout<<"- "<<StudentVector[j].Name()<<" (CGPA: "<<StudentVector[j].CG()<<")"<<endl;
                count++;
            }
        }
        if(count == 0) cout<<"No eligible students"<<endl;
        cout<<"Total: "<<count<<" students"<<endl;
    }
}

void Placement::showStatistics(){
    cout<<"\n=== PLACEMENT STATISTICS ==="<<endl;
    
    int totalStudents = StudentVector.size();
    int placed = 0;
    double totalPackage = 0;
    
    for(int j=0; j < StudentVector.size(); j++){
        if(StudentVector[j].isPlaced()){
            placed++;
            for(int i=0; i < CompanyVector.size(); i++){
                if(CompanyVector[i].Name() == StudentVector[j].getPlacedCompany()){
                    totalPackage += CompanyVector[i].Package;
                    break;
                }
            }
        }
    }
    
    cout<<"Total Students: "<<totalStudents<<endl;
    cout<<"Students Placed: "<<placed<<endl;
    cout<<"Placement Rate: "<<fixed<<setprecision(2)<<(totalStudents>0?placed*100.0/totalStudents:0)<<"%"<<endl;
    cout<<"Average Package: "<<(placed>0?totalPackage/placed:0)<<" LPA"<<endl;
}

void conductDrive(){
    cout<<"\n=== PLACEMENT DRIVE ==="<<endl;
    
    vector<Student> students = collectData();
    vector<Company> companies = collectData1();
    
    int totalPlaced = 0;
    
    for(auto& company : companies){
        cout<<"\n"<<company.Name()<<" is hiring (Min CGPA: "<<company.CG()<<")"<<endl;
        int hired = 0;
        
        for(auto& student : students){
            if(student.CG() >= company.CG() && !student.isPlaced()){
                cout<<"  - "<<student.Name()<<" selected!"<<endl;
                totalPlaced++;
                hired++;
            }
        }
        if(hired == 0) cout<<"  No eligible students found!"<<endl;
        else cout<<"  Total hired: "<<hired<<endl;
    }
    
    cout<<"\n=== DRIVE COMPLETE ==="<<endl;
    cout<<"Total Placed: "<<totalPlaced<<endl;
}
