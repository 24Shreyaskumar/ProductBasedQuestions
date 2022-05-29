#include <iostream>
#include <vector>
using namespace std;

int LargestSubarray(vector<int> &arr, long long k) {
    int n = arr.size();
    int i = 0, j = 0;
    int mx = 0;
    long long sum = 0;

    while (j < n) {
        sum += arr[j];

        if (sum == k) {
            mx = max(mx, (j - i + 1));
            j++;
        } 

        else if (sum > k) {
            sum -= (arr[i] + arr[j]);
            i++;
        }

        else j++;
    }

    return mx;
}


int main() {
    int n;
    cout<<"Enter the size of the array : "; cin>>n;

    vector<int> arr;
    cout<<"\nEnter the array elements : ";
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        arr.push_back(x);
    }

    long long k;
    cout<<"\nEnter the sum : "; cin>>k;

    cout<<"\nThe largest subarray giving sum "<<k<<" is of size : "<<LargestSubarray(arr, k);

    return 0;
}