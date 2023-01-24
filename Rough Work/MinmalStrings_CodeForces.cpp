#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    string s;
    cin>>s;

    stack<int> t;
    vector<int> freq(26, 0);

    for (auto i : s) freq[i - 'a']++;

    string u;
    for (auto i : s) {
        t.push(i);
        freq[i - 'a']--;

        while (!t.empty()) {
            bool flag = true;
            char ele = t.top();
            for (int j = 0; j < ele - 'a'; j++) {
                if (freq[j] > 0) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                u += ele;
                t.pop();
            }

            else break;
        }
    }

    while (!t.empty()) {
        u += t.top();
        t.pop();
    }

    cout<<u<<"\n";


}