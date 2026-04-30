//1. Count and display the number of lines not starting with alphabet 'A'
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void countLines() {
    ifstream file("STORY.TXT");
    string line;
    int count = 0;

    while(getline(file, line)) {
        if(line[0] != 'A' && line[0] != 'a') {
            count++;
        }
    }

    cout << "Number of lines not starting with A: " << count;
}

int main() {
    countLines();
    return 0;
}

//2. Count uppercase and lowercase letters in TEXT.TXT
C++
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream file("TEXT.TXT");
    char ch;
    int upper = 0, lower = 0;

    while(file.get(ch)) {
        if(isupper(ch))
            upper++;
        else if(islower(ch))
            lower++;
    }

    cout << "Uppercase letters: " << upper << endl;
    cout << "Lowercase letters: " << lower << endl;

    return 0;
}

//3. Display the longest word in WORDS.TXT
C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("WORDS.TXT");
    string word, longest = "";

    while(file >> word) {
        if(word.length() > longest.length()) {
            longest = word;
        }
    }

    cout << "Longest word: " << longest;

    return 0;
}

//4. Count frequency of each character in a file
C++
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("TEXT.TXT");
    char ch;
    int freq[256] = {0};

    while(file.get(ch)) {
        freq[(int)ch]++;
    }

    for(int i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            cout << (char)i << " = " << freq[i] << endl;
        }
    }

    return 0;
}


//5. Remove duplicate words from a file and store in another file
C++
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

int main() {
    ifstream infile("INPUT.TXT");
    ofstream outfile("OUTPUT.TXT");

    set<string> words;
    string word;

    while(infile >> word) {
        words.insert(word);
    }

    for(string w : words) {
        outfile << w << " ";
    }

    cout << "Duplicate words removed.";

    return 0;
}

//6. Count palindrome words in WORDS.TXT
C++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isPalindrome(string word) {
    int start = 0;
    int end = word.length() - 1;

    while(start < end) {
        if(word[start] != word[end]) {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

void countPalindrome() {
    ifstream file("WORDS.TXT");
    string word;
    int count = 0;

    while(file >> word) {
        if(isPalindrome(word)) {
            count++;
        }
    }

    cout << "Number of palindrome words: " << count;
}

int main() {
    countPalindrome();
    return 0;
}