#include <bits/stdc++.h>
using namespace std;

class BruteForceSearch {
private:
    string text;      
    string pattern;   
    int comparisons;

public:
    BruteForceSearch(const string& text, const string& pattern)
        : text(text), pattern(pattern), comparisons(0) {}

    void search() {
        int n1 = text.size();
        int n2 = pattern.size();
        int cnt = 0;

        for (int i = 0; i <= n1 - n2; i++) {
            int j = 0;
            while (j < n2 && text[j + i] == pattern[j]) {
                comparisons++;
                j++;
            }
            if (j == n2) {
                cout << "Shift occurs at " << i << endl;
            }
            if (j < n2) {
                comparisons++;
            }
        }

        cout << (n1 - n2 + 1) * n2 << endl; // Total possible comparisons
        cout << comparisons << endl; // Total comparisons made
    }
};

int main() {
    string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaapaaaaaaaaaaaaa";
    string s2 = "aaaaa";

    BruteForceSearch bfs(s1, s2);
    bfs.search();

    return 0;
}
