//Program 2: Old Prime Numbers
#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if (n < 2)
        return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int num;

    while (inFile >> num) {
        if (isPrime(num) && num % 2 != 0) {
            outFile << num << endl;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Odd prime numbers written to output.txt";
    return 0;
}