#include <iostream>
#include <vector>
using namespace std;

struct Student {
    int studentID;
    string name;
    string course;
    int gpa;
};

vector<Student> students;

string getStanding(int gpa){
    if(gpa >= 90) return "Excellent";
    else if(gpa >= 80) return "Very Good";
    else if(gpa >= 70) return "Good";
    else if(gpa >= 60) return "Passing";
    else return "Failed";
}

bool idExists(int id){
    for(int i=0;i<students.size();i++){
        if(students[i].studentID == id)
            return true;
    }
    return false;
}

void addStudent(){
    Student s;

    cout << "Enter Student ID: ";
    cin >> s.studentID;

    if(idExists(s.studentID)){
        cout << "ID already exists!\n";
        return;
    }

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Course: ";
    getline(cin, s.course);

    cout << "Enter GPA: ";
    cin >> s.gpa;

    students.push_back(s);
    cout << "Student Added Successfully!\n";
}

void displayStudents(){
    cout << "\nID\tName\tCourse\tGPA\tStanding\n";
    for(int i=0;i<students.size();i++){
        cout << students[i].studentID << "\t"
             << students[i].name << "\t"
             << students[i].course << "\t"
             << students[i].gpa << "\t"
             << getStanding(students[i].gpa) << endl;
    }
}

void deleteStudent(){
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for(int i=0;i<students.size();i++){
        if(students[i].studentID == id){
            students.erase(students.begin()+i);
            cout << "Deleted Successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

void editStudent(){
    int id;
    cout << "Enter ID to edit: ";
    cin >> id;

    for(int i=0;i<students.size();i++){
        if(students[i].studentID == id){

            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, students[i].name);

            cout << "Enter New Course: ";
            getline(cin, students[i].course);

            cout << "Enter New GPA: ";
            cin >> students[i].gpa;

            cout << "Updated Successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}

int main(){
    int choice;

    do{
        cout << "\n===== MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Edit Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display Students\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1: addStudent(); break;
            case 2: editStudent(); break;
            case 3: deleteStudent(); break;
            case 4: displayStudents(); break;
            case 5: cout<<"Goodbye!\n"; break;
            default: cout<<"Invalid choice!\n";
        }

    }while(choice != 5);

    return 0;
}