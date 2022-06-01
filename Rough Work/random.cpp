#include <bits/stdc++.h>
using namespace std;

int Solution(vector<int> &arr) {
    int n = arr.size();
    int i = 0, j = 1;

    if (n == 0) return 0;
    if (n == 1) return 0;
    
    while (j < n) {
        if ((arr[i] + arr[j]) % 2 != 0) {
            return 1;
        }

        i++; j++;
    }
    
    return 0;
}

int main() {
    int t; cin>>t;
    
    while (t--) {
        int n; cin>>n;
        vector<int> arr;
        for (int j = 0; j < n; j++) {
            int x; cin>>x;
            arr.push_back(x);
        }
        cout<<Solution(arr)<<endl;
    }
    
    return 0;
}