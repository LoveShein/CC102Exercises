#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int students, quizzes;
    char again;

    do {
        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        double scores[50][50];  
        double average[50];

        for (int i = 0; i < students; i++) {
            cout << "\nStudent " << i + 1 << " scores:\n";
            double sum = 0;

            for (int j = 0; j < quizzes; j++) {
                cin >> scores[i][j];
                sum += scores[i][j];
            }
            average[i] = sum / quizzes;
        }
        
        cout << "\nStudent\t";
        for (int q = 1; q <= quizzes; q++) {
            cout << "Q" << q << "\t";
        }
        cout << "Average\n";

        for (int i = 0; i < students; i++) {
            cout << i + 1 << "\t";
            for (int j = 0; j < quizzes; j++) {
                cout << scores[i][j] << "\t";
            }
            cout << fixed << setprecision(2) << average[i] << endl;
        }

        cout << "\nRun again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}