#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> Solution(vector<int> &arr, int k) {
    int n = arr.size();
    int i = 0, j = 0;
    deque<int> negatives;
    vector<int> firstNegatives;

    while (j < n) {
        if (arr[j] < 0) negatives.push_back(arr[j]);

        if (j - i + 1 < k) j++;

        else if (j - i + 1 == k) {
            if (negatives.empty()) firstNegatives.push_back(0);

            else {
                firstNegatives.push_back(negatives.front());

                if (arr[i] < 0) negatives.pop_front();
            }

            i++; j++;
        }
    }

    return firstNegatives;
}



int main() {
    int n, k;
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
    cin>>k; cout<<"\n";

    vector<int> firstNegatives = Solution(arr, k);

    cout<<"The first negatives in each window of size "<<k<<" are : ";
    for (int i : firstNegatives) {
        cout<<i<<" ";
    }
    cout<<"\n";

    return 0;
}