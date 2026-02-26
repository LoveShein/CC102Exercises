#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    char choice;

    do {
        int students, days;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of days: ";
        cin >> days;

        vector<vector<int>> attendance(students, vector<int>(days));

        for (int i = 0; i < students; i++) {
            cout << "\nStudent " << i + 1 << " attendance: ";
            for (int j = 0; j < days; j++) {
                cin >> attendance[i][j];
            }
        }
        
        cout << "\n\nStudent ";
        for (int d = 0; d < days; d++) {
            cout << "D" << d + 1 << " ";
        }
        cout << "Total Percentage Remarks\n";

        for (int i = 0; i < students; i++) {
            int total = 0;

            cout << setw(7) << i + 1 << " ";

            for (int j = 0; j < days; j++) {
                cout << setw(2) << attendance[i][j] << " ";
                total += attendance[i][j];
            }

            double percentage = (double)total / days * 100;

            string remark = (percentage < 50) ? "DRP" : "OK";

            cout << setw(5) << total << " ";
            cout << setw(9) << percentage << "% ";
            cout << remark << endl;
        }

        cout << "\nDo you want to run the program again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nProgram terminated.";

    return 0;
}