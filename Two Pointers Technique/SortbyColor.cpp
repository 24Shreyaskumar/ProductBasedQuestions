#include <iostream>
using namespace std;

void SortByColor(int* arr, int n) {
    int i = 0;
    int j = n - 1;
    int k = 0;

    while (k <= j) {
        if  (arr[k] == 0) swap(arr[i++], arr[k]);
        else if (arr[k] == 2) {
            swap(arr[j--], arr[k]);
            continue;
        }
        k++;
    }

    return;
}


int main() {
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n; cout<<"\n";

    int* arr = new int[n];
    cout<<"Enter the array elements (only 0, 1, 2 are allowed for program to run without any problems): ";
    for (int i = 0; i < n; i++) cin>>arr[i];
    cout<<"\n";

    SortByColor(arr, n);
    cout<<"The sorted array with respect to color (0 : red, 1: white, 2 : blue) is : ";
    for (int i =0; i < n; i++) cout<<arr[i]<<" ";
    cout<<"\n";

    return 0;
}