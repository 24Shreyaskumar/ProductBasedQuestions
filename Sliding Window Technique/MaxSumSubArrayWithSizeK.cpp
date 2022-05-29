#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Solution(vector<int> &arr, int wSize) {
    int n = arr.size();
    int i = 0, j = 0;
    int sum = 0;
    int mSum = INT_MIN;


    while (j < n) {
        sum += arr[j];

        if (j - i + 1 < wSize) j++;
    
        else if(j - i + 1 == wSize) {
            mSum = max(mSum, sum);
            sum -= arr[i];
            i++; j++;
        }
    }

    return mSum;
}


int main() {
    int n, wSize;
    cout<<"Enter the size of the array : ";
    cin>>n; cout<<"\n";

    cout<<"Enter the array elements : ";
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"\n";

    cout<<"Enter the size of the window : ";
    cin>>wSize; cout<<"\n";

    cout<<"The maximum sum subarray with window size "<<wSize<<" is : "<<Solution(arr, wSize)<<"\n";

    return 0;
}