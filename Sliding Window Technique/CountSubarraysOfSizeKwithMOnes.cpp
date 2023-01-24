#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int Solution() {
    int n, k, m; cin>>n>>k>>m;
    vi v(n);
    for (int i = 0; i < n; i++) cin>>v[i];

    int i = 0, j = 0, countOnes = 0, countSubarrays = 0;

    while (j < n) {
        if (v[j] == 1) countOnes++;

        if (j - i + 1 < k) j++;

        else if (j - i + 1 == k) {
            if (countOnes == m) countSubarrays++;
            if (v[i] == 1) countOnes--;
            i++; j++;
        }
    }

    return countSubarrays;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        cout<<Solution()<<"\n";
    }

    return 0;
}