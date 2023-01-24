// sort neg numbers in 

#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int, int>
using namespace std;

static bool comp(int& a, int& b) {
	if (a < 0 && b < 0) return a > b;
	return a < b;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	//int n; cin>>n;
	vi v = {3, 1, -1, -5, 4, -6};
	
	sort(v.begin(), v.end(), comp);

	for (auto i : v) cout<<i<<"\n";
}
