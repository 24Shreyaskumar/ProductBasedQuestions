#include <bits/stdc++.h>
using namespace std;

vector<int> Solve(int n, vector<int> deck) {
    vector<int> ans(n);
    queue<int> solve;
    
    sort(deck.begin(), deck.end());

    for (int i = n - 1; i >= 0; i++) {
        if (!solve.empty()) {
            int front = solve.front();
            solve.pop();
            solve.push(front);
            solve.push(deck[i]);
        }

        else solve.push(deck[i]);
    }

    int i = 0;
    while (!solve.empty()) {
        cout<<solve.front()<<"\n";
        ans[i++] = solve.front();
        solve.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int n; cin>>n;
        vector<int> deck(n);

        for (int i = 0; i < n; i++) cin>>deck[i];

        vector<int> ans = Solve(n, deck);

        for (auto i : ans) cout<<i<<" ";
        cout<<"\n"; 
    }

    return 0;
}