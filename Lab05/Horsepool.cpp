#include <bits/stdc++.h>
using namespace std;

class BoyerMooreSearch {
private:
    string text;      // Text where we are searching
    string pattern;   // Pattern to search for
    map<char, int> shift; // Shift table

    void preprocess() {
        int n2 = pattern.size();
        for (int i = 0; i < n2 - 1; i++) {
            shift[pattern[i]] = n2 - 1 - i;
        }
    }

public:
    BoyerMooreSearch(const string& text, const string& pattern) 
        : text(text), pattern(pattern) {
        preprocess(); // Build the shift table
    }

    void printShiftTable() const {
        for (auto it : shift) {
            cout << it.first << " " << it.second << endl;
        }
    }

    void search() const {
        int n1 = text.size();
        int n2 = pattern.size();
        int j = 0;

        while (j + n2 <= n1) {
            if (pattern[n2 - 1] == text[j + n2 - 1]) {
                int i = n2 - 2;
                while (i >= 0 && (pattern[i] == text[j + i])) {
                    i--;
                }
                if (i == -1) {
                    cout << "The index starts at " << j << endl;
                }
            }
            if (shift.find(text[j + n2 - 1]) != shift.end()) {
                j += shift.at(text[j + n2 - 1]);
            } else {
                j += n2;
            }
        }
    }
};

int main() {
    string s1 = "hello my name is name what is your name";
    string s2 = "name";

    BoyerMooreSearch bms(s1, s2);
    bms.printShiftTable();
    bms.search();

    return 0;
}
