#include <iostream>
using namespace std;

int main() {
    int parking[5][10] = {0}; 
    int choice;
    int row, col;
    float totalCollection = 0;

    do {
        cout << "\n===== CAR PARKING SYSTEM =====\n";
        cout << "Total Collection: P" << totalCollection << endl;
        cout << "1. View Parking Layout\n";
        cout << "2. Park a Car\n";
        cout << "3. Leave Parking\n";
        cout << "4. Reset Parking Area\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            cout << "\n   1 2 3 4 5 6 7 8 9 10\n";
            char rowLabel = 'A';

            for(int i = 0; i < 5; i++) {
                cout << rowLabel++ << " ";
                for(int j = 0; j < 10; j++) {
                    cout << parking[i][j] << " ";
                }
                cout << endl;
            }
        }

        else if(choice == 2) {
            bool full = true;

            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 10; j++) {
                    if(parking[i][j] == 0) {
                        full = false;
                        break;
                    }
                }
            }

            if(full) {
                cout << "Parking area is fully booked! No available slot.\n";
                continue;
            }

            cout << "Enter row (1-5): ";
            cin >> row;
            cout << "Enter column (1-10): ";
            cin >> col;

            if(row < 1 || row > 5 || col < 1 || col > 10) {
                cout << "Invalid slot selection!\n";
            }
            else if(parking[row-1][col-1] == 1) {
                cout << "Slot already occupied!\n";
            }
            else {
                parking[row-1][col-1] = 1;
                char letter = 'A' + (row - 1);
                cout << "Car successfully parked at " << letter << col << endl;
            }
        }

        else if(choice == 3) {
            cout << "Enter row (1-5): ";
            cin >> row;
            cout << "Enter column (1-10): ";
            cin >> col;

            if(row < 1 || row > 5 || col < 1 || col > 10) {
                cout << "Invalid slot selection!\n";
            }
            else if(parking[row-1][col-1] == 0) {
                cout << "Slot is already empty!\n";
            }
            else {
                parking[row-1][col-1] = 0;
                totalCollection += 12.00;
                char letter = 'A' + (row - 1);

                cout << "Car at " << letter << col << " has left the parking area.\n";
                cout << "Parking fee collected: P12.00\n";
                cout << "Updated Total Collection: P" << totalCollection << endl;
            }
        }

        else if(choice == 4) {
            for(int i = 0; i < 5; i++) {
                for(int j = 0; j < 10; j++) {
                    parking[i][j] = 0;
                }
            }

            cout << "Parking area reset successfully!\n";
        }

    } while(choice != 5);

    cout << "Program exited.\n";

    return 0;
}