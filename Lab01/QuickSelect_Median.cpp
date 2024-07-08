#include <bits/stdc++.h>
#define int long long

using namespace std;

int partition(vector<int>& arr, int p, int r) {
    int i = p-1;
    int x = arr[r];

    for(int j = p; j <= r-1; j++) {
        if(arr[j] <= x) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[r]);
    return i+1;
}

int randomizedPartition(vector<int>& arr, int p, int r) {
    int idx = rand() % (r-p+1) + p;
    swap(arr[idx], arr[r]);
    return partition(arr, p, r);
}

void RQS(vector<int>& arr, int p, int r, int idx, int& element1, int& element2) 
{
    if (p <= r) {
        int partitionIndex = randomizedPartition(arr, p, r);

        if (partitionIndex == idx) {
            element2 = arr[partitionIndex];
            if(element1 != -1)
                return;
        }

        else if (partitionIndex == idx - 1) {
            element1 = arr[partitionIndex];
            if (element2 != -1)
                return;
        }
 
        if (partitionIndex >= idx)
            return RQS(arr, p, partitionIndex - 1, idx, element1, element2);
 
        else RQS(arr, partitionIndex+1, r, idx, element1, element2);
    }
}

pair<int, int> findKthSmallestElements(vector<int>& arr) 
{
    int n = arr.size();
    int ele1 = -1, ele2 = -1;

    RQS(arr, 0, n-1, n/2, ele1, ele2);

    return make_pair(ele1, ele2);
}

signed main() {
    vector<int> arr = {12, 3, 5, 7, 4, 19, 26, 500};
    int n = arr.size();

    if (n == 0) {
        cout << "Array is empty" << endl;
        return 0;
    }

    pair<int, int> result;
    result = findKthSmallestElements(arr);
    if (n % 2 == 1) {
        cout << result.second << endl;
    } 
    else {
        cout << (result.first + result.second) / 2.0 << endl;
    }

    return 0;
}
