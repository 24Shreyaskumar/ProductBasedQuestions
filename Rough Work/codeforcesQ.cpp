#include <bits/stdc++.h>
#define ll long long int
#define vll vector<long long>
using namespace std;

// bool Solve(vll& c, ll mid, ll k) {
//     vector<pair<float, float>> check(c.size());

//     for (int i = 0; i < c.size(); i++) {
//         check[i] = {(float) c[i] - (float) mid / 2, (float) c[i] + (float) mid / 2};
//     }

//     for (int i = 0; i < c.size() - 1; i++) {
//         if (c[0] != 0 && check[0].first > 0 || c[c.size() - 1] != k && check[c.size()-1].second < k) return false;
//         if (check[i].second < check[i + 1].first) return false;
//     }

//     return true;
// }

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    ll n, k;
    cin>>n>>k;
    vll c(n);

    for (int i = 0; i < n; i++) cin>>c[i];
    sort(c.begin(), c.end());


    float maxDiff = INT_MIN;
    for (ll i = 1; i < n; i++) {
        maxDiff = max(maxDiff, (float) (c[i] - c[i-1]) / 2);
    }

    if (c[0]) maxDiff = max(maxDiff, (float) c[0]);
    if (c[n-1] != k) maxDiff = max(maxDiff, (float) (k - c[n-1])); 

    cout<<fixed<<setprecision(10)<<maxDiff<<"\n";

    return 0;
}