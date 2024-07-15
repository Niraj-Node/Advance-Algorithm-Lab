#include<bits/stdc++.h>
using namespace std;

class myMath 
{
    int fLiars = 0;
    int fWitnesses = 0;

    public:     
        void setCounters() {
            fLiars = 0;
            fWitnesses = 0;
        }

        unsigned long long powerIterative(unsigned long long num, int pow, unsigned long long x) {
            unsigned long long res = 1;
            num = num % x;
            while(pow) {
                if(pow & 1) res = (res*num) % x;
                pow >>= 1;
                num = (num*num) % x;
            }
            return res;
        }

        void countLiarWitness(unsigned long long num, unsigned long long k = 2) {
            while(k <= num-2) {
                if(powerIterative(k, num-1, num) == 1) fLiars++;
                else fWitnesses++;

                k++;
            }

            cout << "F-Liars: " << fLiars << ", F-Witnesses: " << fWitnesses << endl;
            cout << "Probability of selecting Liar Randomly: " << (float)fLiars/(fLiars+fWitnesses) << endl;
        }
};

int main() {
    unsigned long long num;
    cout << "Enter the Num: ";
    cin >> num;

    myMath obj;
    obj.countLiarWitness(num);
    return 0;
}