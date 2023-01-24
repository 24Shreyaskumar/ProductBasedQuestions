#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

int BS_FO(int n, int k, vi v) {
    int s = 0, e = n-1, res = -1, mid;

    while (s <= e) {
        mid = s + (e - s) / 2;

        if (v[mid] == k) {
            res = mid;
            e = mid - 1;
        }

        else if (v[mid] > k) e = mid - 1;

        else s = mid + 1;
    }

    return res;
}

int BS_LO(int n, int k, vi v) {
    int s = 0, e = n-1, res = -1, mid;

    while (s <= e) {
        mid = s + (e - s) / 2;

        if (v[mid] == k) {
            res = mid;
            s = mid + 1;
        }

        else if (v[mid] > k) e = mid - 1;

        else s = mid + 1;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int n, k; cin>>n>>k;
        vi v(n);
        for (int i = 0; i < n; i++) cin>>v[i];
        cout<<"First Occurence : "<<BS_FO(n, k, v);
        cout<<"\nLast Occurence : "<<BS_LO(n, k, v);
    }

    return 0;
}