#include<bits/stdc++.h>
using namespace std;

class myMath 
{
    public:     
        myMath() {
            srand(time(NULL));
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

        // unsigned long long gcdRecursive(unsigned long long a, unsigned long long b)
        // {
        //     if(b != 0) return gcdRecursive(b, a % b);
        //     else return a;
        // }
        unsigned long long gcdIterative(unsigned long long a, unsigned long long b) {
            while(b != 0) {
                unsigned long long rem = a%b;
                a = b;
                b = rem;
            }
            return a;
        }

        bool isPrime(unsigned long long num, unsigned long long k) {
            if(num == 2 || num == 3) return true;
            if(num <= 1 || num % 2 == 0) return false;

            while(k) {
                unsigned long long a = 2 + rand()%(num-3); // 2 <= a <= num-2

                if(gcdIterative(num, a) != 1) return false;
                if(powerIterative(a, num-1, num) != 1) return false;

                k--;
            }

            return true;
        }
};

int main() {
    unsigned long long num;
    cout << "Enter the Num: ";
    cin >> num;

    myMath obj;
    if(obj.isPrime(num, 10))
        cout << num << " is Prime" << endl;
    else
        cout << num << " is not a Prime" << endl;
    return 0;
}