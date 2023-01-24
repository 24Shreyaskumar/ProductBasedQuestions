#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll Solve(ll n, ll k) {
    ll l = 1;
    ll r = k;
    ll mx = k * (k - 1) / 2;
    ll ans = -1;

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll midSum = mid * (mid - 1) / 2;
        ll remain = mx - midSum + 1;

        if (remain >= n) {
            ans = k - mid;
            l = mid + 1;
        }

        else r = mid - 1;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    //ll t; cin>>t;

    //while (t--) {
        ll n, k;
        cin>>n>>k;

        cout<<Solve(n, k)<<"\n";
    //}

    return 0;
}