#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

int isAP(vector<pair<int, int>>& ind, int d) {
	int del = 0;
	
	for ()
}

int Solve() {
	int n; cin>>n;
	vi v(n);
	for (int i = 0; i < n; i++) cin>>v[i];

	vector<pair<int, int>> ind(n);
	for (int i = 0; i < n; i++) {
		ind[i] = {v[i], i};
	} 

	sort(ind.begin(), ind.end());


}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cout<<Solve()<<"\n";
	return 0;
}