#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> Solution(vector<int> &arr, int k) {
    int n = arr.size();
    int i = 0, j = 0;
    //int mx = INT_MIN;
    vector<int> sol;
    deque<int> mx;
    //mx.push_front(INT_MIN);


    if (n == 1) {
        sol.push_back(arr[0]);
        return sol;
    }

    while (j < n) {
        while (!mx.empty() && mx.back() < arr[j]) {mx.pop_back(); }
        mx.push_back(arr[j]);

        if (j - i + 1 < k) j++;

        else if (j - i + 1 == k) {
            if(!mx.empty()) {
                sol.push_back(mx.front());

                if (arr[i] == mx.front()) mx.pop_front();
            }
        
            i++; j++;
        } 
        
    }

    return sol;
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
    cout<<"\nEnter the size of the subarray : "; cin>>k;

    cout<<"\nThe maximum in each subarray of size "<<k<<" is ";
    vector<int> sol = Solution(arr, k);
    for (auto i : sol) cout<<i<<" ";

    return 0;
}