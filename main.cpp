#include <iostream>
#include <limits>
#include "Student_Class.h"
#include "Company_Class.h"
#include "Placement_Class.h"
using namespace std;

void showMenu(){
    cout<<"\n----------- PLACEMENT TRACKER -----------\n";
    cout<<"1. Add Student\n";
    cout<<"2. Add Company\n";
    cout<<"3. View All Students\n";
    cout<<"4. View All Companies\n";
    cout<<"5. Show Eligible Students\n";
    cout<<"6. Add Placement Record\n";
    cout<<"7. Conduct Placement Drive\n";
    cout<<"8. Show Statistics\n";
    cout<<"9. Exit\n";
    cout<<"----------------------------------------\n";
    cout<<"Enter choice: ";
}

int main(){
    int choice;
    
    while(true){
        showMenu();
        cin>>choice;
        
        switch(choice){
            case 1:
                addStudent();
                Placement::StudentVector = collectData();
                break;
                
            case 2:
                addCompany();
                Placement::CompanyVector = collectData1();
                break;
                
            case 3:{
                vector<Student> students = collectData();
                if(students.empty()){
                    cout<<"No students found!"<<endl;
                } else {
                    for(auto& s : students){
                        s.DisplayStudent();
                    }
                }
                break;
            }
            
            case 4:{
                vector<Company> companies = collectData1();
                if(companies.empty()){
                    cout<<"No companies found!"<<endl;
                } else {
                    for(auto& c : companies){
                        c.DisplayCompany();
                    }
                }
                break;
            }
            
            case 5:
                Placement::printEligibleStudents();
                break;
                
            case 6:{
                vector<Student> students = collectData();
                vector<Company> companies = collectData1();
                if(students.empty() || companies.empty()){
                    cout<<"Add students and companies first!"<<endl;
                    break;
                }
                int sIdx, cIdx;
                cout<<"Select Student (1-"<<students.size()<<"): ";
                cin>>sIdx;
                cout<<"Select Company (1-"<<companies.size()<<"): ";
                cin>>cIdx;
                if(sIdx>=1 && sIdx<=students.size() && cIdx>=1 && cIdx<=companies.size()){
                    addPlacement(students[sIdx-1], companies[cIdx-1]);
                } else {
                    cout<<"Invalid selection!"<<endl;
                }
                break;
            }
            
            case 7:
                conductDrive();
                break;
                
            case 8:
                Placement::showStatistics();
                break;
                
            case 9:
                cout<<"Goodbye!"<<endl;
                return 0;
                
            default:
                cout<<"Invalid choice! Please enter 1-9."<<endl;
        }
    }
    return 0;
}