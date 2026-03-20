#include <iostream>
using namespace std;


struct Student {
    string name;
    int age;
    float grade;
};

void input(Student s[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Enter name: ";
        cin >> s[i].name;
        cout << "Enter age: ";
        cin >> s[i].age;
        cout << "Enter grade: ";
        cin >> s[i].grade;
    }
}


void display(Student s[], int n) {
    cout << "\nStudent Records:\n";
    for(int i = 0; i < n; i++) {
        cout << "Name: " << s[i].name << endl;
        cout << "Age: " << s[i].age << endl;
        cout << "Grade: " << s[i].grade << endl;
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student obj[n]; 

    input(obj, n);   
    display(obj, n); 

    return 0;
}
    