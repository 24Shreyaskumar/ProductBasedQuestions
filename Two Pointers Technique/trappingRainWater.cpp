#include <bits/stdc++.h>
using namespace std;

int Solve(vector<int> v, int n) {
    int i = 0, j = n - 1, leftMax = INT_MIN, rightMax = INT_MIN, ans = 0;

    while (i < j) {
        leftMax = max(leftMax, v[i]);
        rightMax = max(rightMax, v[j]);

        if (v[i] < v[j]) {
            ans += min(leftMax, rightMax) - v[i];
            i++;
        }

        else {
            ans += min(leftMax, rightMax) - v[j];
            j--;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int n; cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin>>v[i];

        cout<<Solve(v, n)<<"\n";
    }

    return 0;
}