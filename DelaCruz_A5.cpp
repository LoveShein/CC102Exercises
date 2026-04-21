#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ofstream outFile("original.txt");

    if (!outFile) {
        cout << "Error: Cannot create original.txt" << endl;
        return 1;
    }

    outFile << "One" << endl;
    outFile << "Two" << endl;
    outFile << "Three" << endl;
    outFile << "Four" << endl;
    outFile << "Five" << endl;
    outFile << "Six" << endl;

    outFile.close();
    
    ifstream inFile("original.txt");

    if (!inFile) {
        cout << "Error: Cannot open original.txt" << endl;
        return 1;
    }

    vector<string> lines;
    string line;

    while (getline(inFile, line)) {
        lines.push_back(line);
    }

    inFile.close();

    sort(lines.begin(), lines.end());

    ofstream sortedFile("sorted.txt");

    if (!sortedFile) {
        cout << "Error: Cannot create sorted.txt" << endl;
        return 1;
    }

    for (int i = 0; i < lines.size(); i++) {
        sortedFile << lines[i] << endl;
    }

    sortedFile.close();

    cout << "Sorting completed. Check sorted.txt" << endl;

    return 0;
}