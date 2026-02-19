#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int PRODUCTS = 5;
    const int SALESPEOPLE = 4;
    double sales[PRODUCTS][SALESPEOPLE] = {0};

    int salesperson, product;
    double amount;
    char again;

    do {
        cout << "\nEnter salesperson number (1-4, 0 to stop): ";
        cin >> salesperson;

        while (salesperson != 0) {
            cout << "Enter product number (1-5): ";
            cin >> product;

            cout << "Enter dollar amount sold: ";
            cin >> amount;

            sales[product - 1][salesperson - 1] += amount;

            cout << "\nEnter salesperson number (1-4, 0 to stop): ";
            cin >> salesperson;
        }
        
        cout << "\nProduct\t";
        for (int s = 1; s <= SALESPEOPLE; s++) {
            cout << s << "\t";
        }
        cout << "Total\n";

        double grandTotal = 0;

        for (int i = 0; i < PRODUCTS; i++) {
            double rowTotal = 0;
            cout << i + 1 << "\t";

            for (int j = 0; j < SALESPEOPLE; j++) {
                cout << fixed << setprecision(2) << sales[i][j] << "\t";
                rowTotal += sales[i][j];
            }

            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "Total\t";
        for (int j = 0; j < SALESPEOPLE; j++) {
            double colTotal = 0;
            for (int i = 0; i < PRODUCTS; i++) {
                colTotal += sales[i][j];
            }
            cout << colTotal << "\t";
        }
        cout << grandTotal << endl;

        cout << "\nRun program again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}