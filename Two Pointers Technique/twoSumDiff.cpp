#include <iostream>
using namespace std;

bool SubsetPairSum(int* arr, int n, int sum) {
    int i = 0;
    int j = n-1;

    while (i < j) {
        if (arr[i] + arr[j] == sum) {
            cout<<arr[i]<<" and "<<arr[j]<<" equals "<<sum<<"\n";
            return true;
        }

        else if (arr[i] + arr[j] > sum) j--;

        else i++;
    }

    return false;
}


bool SubsetPairDiff(int* arr, int n, int diff) {
    int i = 0;
    int j = i + 1;

    while (j < n){
        if (arr[j] - arr[i] == diff) {
            cout<<"yes, "<<arr[j]<<" and "<<arr[i]<<" equals "<<diff<<"\n";
            return true;
        }

        else if (arr[j] - arr[i] > diff) {
            i++;
        }

        else j++;
    }

    return false;
}


int main() {
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    cout<<"\n";

    int* arr = new int[n];
    cout<<"Enter array elements : ";
    for (int i = 0; i < n; i++) cin>>arr[i];
    cout<<"\n";

    int sum;
    cout<<"Enter the expected sum : "; cin>>sum;

    cout<<"\nis there any pair that equals the expected sum ? "<<SubsetPairSum(arr, n, sum);


    int diff;
    cout<<"\nEnter the expected diff : "; cin>>diff;

    cout<<"\nis there any pair that equals the expected difference ? "<<SubsetPairDiff(arr, n, diff);

    return 0;

}