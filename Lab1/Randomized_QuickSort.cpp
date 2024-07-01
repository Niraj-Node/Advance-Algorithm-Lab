#include <bits/stdc++.h>
#define int long long

using namespace std;

int comparisons = 0;
int swaps = 0;

int partition(vector<int>& arr, int p, int r)
{
    int i = p-1;
    int x = arr[r];

    for(int j = p; j <= r-1; j++) 
    {
        comparisons++;
        if(arr[j] <= x)
        {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }

    swap(arr[i+1], arr[r]);
    return i+1;
}

int randomizedPartition(vector<int>& arr, int p, int r)
{
    int idx = rand()%(r-p+1) + p;
    swap(arr[idx], arr[r]);
    return partition(arr, p, r);
}

void RQS(vector<int>& arr, int p, int r)
{
    if(p < r)
    {
        int partition_index = randomizedPartition(arr, p ,r);

        RQS(arr, p, partition_index-1);
        RQS(arr, partition_index+1, r);
    }
}

signed main() {

    int n = 1000;
    vector<int> arr(n);

    for(int i=0; i<n; i++)
        arr[i] = i+1;

    srand(time(NULL));

    int ans = 0;
    for(int i=0; i<10e6; i++)
    {
        RQS(arr, 0, n-1);

        // for(auto it : arr)
        //     cout << it << " ";
        // cout << endl;

        ans += comparisons;
        comparisons = 0;
    }

    cout << "Comparisons: " << ans/10e6 << endl;
    // cout << "Swaps: " << swaps << endl;

    return 0;
}