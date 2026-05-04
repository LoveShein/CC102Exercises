//Program 3:Even Perfect Square
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool isEvenPerfectSquare(int n) {
    int root = sqrt(n);

    return (root * root == n) && (n % 2 == 0);
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int num;

    while (inFile >> num) {
        if (isEvenPerfectSquare(num)) {
            outFile << num << endl;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Even perfect squares written to output.txt";
    return 0;
}