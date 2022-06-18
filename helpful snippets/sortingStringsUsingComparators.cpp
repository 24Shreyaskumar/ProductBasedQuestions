#include <bits/stdc++.h>
using namespace std;

bool compareLength(string a, string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() > b.length();
}

bool compareReverseLexi(string a, string b) {
    return a > b;
}

int main() {
    int n; cin>>n;//length of the string array

    string s[10];
    for(int i = 0; i < n; i++) getline(cin, s[i]);

    sort(s, s+n, compareLength); //sorting based on length of the strings. In case where the strings length is same then the will return in lexicographic order
    for (auto i : s) cout<<i<<" ";

    sort(s, s+n, compareReverseLexi); //sorting in reverse order
    cout<<"\n";
    for (auto j : s) cout<<j<<" ";

    return 0;
}