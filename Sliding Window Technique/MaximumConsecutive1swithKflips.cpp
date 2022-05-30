#include <iostream>
#include <vector>
using namespace std;

int Solution(vector<int> &arr, int k) {
    int n = arr.size();
    int i = 0, j = 0;
    int maxConsecutive1s = 0;
    int countOfZeroes = 0;

    while (j < n) {
        if (arr[j] == 0) countOfZeroes++;
        
        if (countOfZeroes > k) {
            while (countOfZeroes > k) {
                if (arr[i] == 0) countOfZeroes--;
                i++;
            }
        }

        maxConsecutive1s = max(maxConsecutive1s, j - i + 1);
        j++;
    }

    return maxConsecutive1s;
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

    int k;
    cout<<"\nEnter the number of flips allowed : "; cin>>k;

    cout<<"\nMaximum Consecutive 1s in the given array is of length : "<<Solution(arr, k)<<"\n";

    return 0;
}