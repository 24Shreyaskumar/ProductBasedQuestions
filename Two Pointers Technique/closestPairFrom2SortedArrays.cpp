#include <iostream>
#include <climits>
using namespace std;


void closestPair(int* arr1, int* arr2, int n, int m, int x) {
    int i = 0, j = m-1;
    int mdiff = INT_MAX;
    int i1, j1;

    while (i < n && j >= 0) {
        int diff = abs(arr1[i] + arr2[j] - x);

        if (diff == 0) {
            cout<<arr1[i]<<" and "<<arr2[j]<<"\n";
            return;
        }

        else if (diff < mdiff) {
            mdiff = diff;
            i1 = i++; j1 = j;
        }

        else j--;
    }

    cout<<arr1[i1]<<" and "<<arr2[j1]<<"have the closest value of "<<mdiff<<"to "<<x<<"\n";
    
    return;
}



int main() {
    int n, m; 
    cout<<"Enter the array1 size : "; cin>>n;
    cout<<"\nEnter the array2 size : "; cin>>m;
    cout<<"\n";

    int* arr1 = new int[n];
    int* arr2 = new int[m];

    cout<<"\nEnter array1 elements : ";
    for (int i = 0; i < n; i++) cin>>arr1[i];
    cout<<"\nEnter array2 elements : ";
    for (int i = 0; i < m; i++) cin>>arr2[i];

    int x;
    cout<<"\nEnter the value : "; cin>>x;

    closestPair(arr1, arr2, n, m, x);
}