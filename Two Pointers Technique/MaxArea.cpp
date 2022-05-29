#include <iostream>
using namespace std;


int MaxArea(int* arr, int n) {
    int i = 0;
    int j = n-1;
    int area = 0;

    while (i < j) {
        area = max(area, min(arr[i], arr[j]) * (j - i));
        if (min(arr[i], arr[j]) == arr[i]) i++;
        else j--;
    }

    return area;
}


int main() {
    int n;
    cout<<"Enter the size of the array : "; 
    cin>>n; cout<<"\n";

    cout<<"\nEnter the array elements : ";
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    cout<<"\n";

    cout<<"\nThe max area in the give array that can be obtained is : "<<MaxArea(arr, n);

    return 0;
}