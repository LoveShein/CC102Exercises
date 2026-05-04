//Program 1: Perfect Numbers
#include <iostream>
#include <fstream>
using namespace std;

bool isPerfect(int n) {
    int sum = 0;

    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum == n;
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int num;

    while (inFile >> num) {
        if (isPerfect(num)) {
            outFile << num << endl;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Perfect numbers written to output.txt";
    return 0;
}