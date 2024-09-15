#include <bits/stdc++.h>
using namespace std;

class Shuffler {
private:
    vector<int> data;
    int size;

public:
    // Constructor to initialize vector with values from 0 to n-1
    Shuffler(int n) : size(n) {
        data.resize(size);
        for (int i = 0; i < size; i++) {
            data[i] = i;
        }
    }

    // Function to shuffle the vector using Fisher-Yates algorithm
    void shuffle() {
        random_device rd;
        default_random_engine rng(rd());
        uniform_int_distribution<int> dist(0, size - 1);

        for (int i = size - 1; i > 0; i--) {
            int j = dist(rng) % (i + 1);
            swap(data[i], data[j]);
        }
    }

    // Function to count the number of elements that increase
    int countIncreasing() const {
        int best = 0;
        int ttl = 0;
        for (int i = 0; i < size; i++) {
            if (best < data[i]) {
                best = data[i];
                ttl++;
            }
        }
        return ttl;
    }

    // Function to print the contents of the vector
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n = 100000000;
    Shuffler shuffler(n);

    shuffler.shuffle();

    int ttl = shuffler.countIncreasing();
    cout << ttl << endl;

    return 0;
}
