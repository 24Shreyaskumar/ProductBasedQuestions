// #include <bits/stdc++.h>
// using namespace std;

// int Solution(vector<int> &arr) {
//     int n = arr.size();
//     int i = 0, j = 1;

//     if (n == 0) return 0;
//     if (n == 1) return 0;
    
//     while (j < n) {
//         if ((arr[i] + arr[j]) % 2 != 0) {
//             return 1;
//         }

//         i++; j++;
//     }
    
//     return 0;
// }

// int main() {
//     int t; cin>>t;
    
//     while (t--) {
//         int n; cin>>n;
//         vector<int> arr;
//         for (int j = 0; j < n; j++) {
//             int x; cin>>x;
//             arr.push_back(x);
//         }
//         cout<<Solution(arr)<<endl;
//     }
    
//     return 0;
// }

/*
#include <bits/stdc++.h>
using namespace std;

int Solution(vector<int> arr, int m) {
    int n = arr.size();
    int diffSum(int n,int m,int arr[])
{
    vector<int> result;
    long long int sum = 0;
    int maxDiff = 0;
    int flag = 0;
    
    if (n < m) return 0; 
    
    for (int i = 0; i < n; i++) {
        result.push_back(arr[i]);
    }
    
    if (result.size() == 1) return result.front();
    
    for (int x = 0; x < n-1; x++) {
        if (result[x] > result[x+1]) {
            flag = 1;
            break;
        }
    }
    
    if (flag == 1) sort(result.begin(), result.end());
    
    for (int k = n - m; k < n; k++) sum += result[k];
    
    maxDiff = sum;
    sum = 0;
    
    for (int j = 0; j < m; j++) sum += result[j];
    
    maxDiff -= sum;
    
    return maxDiff;
}
}


int main() {
    int n; cin>>n;
    int m; cin>>m;

    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        arr.push_back(x);
    }

    cout<<Solution(arr, m);
}
*/

//maximum of all subarrays of size k (fixed window size)
#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

void Solution() {
    int n, k; 
    cin>>n>>k;
    vi v(n), ans;
    for (int i = 0; i < n; i++) cin>>v[i];

    deque<int> mx;
    int i = 0, j = 0;

    while (j < n) {
        while (!mx.empty() && mx.back() < v[j]) mx.pop_back();
        mx.push_back(v[j]);

        if (j - i + 1 < k) j++;

        else if (j - i + 1 == k) {
            if (!mx.empty()) ans.push_back(mx.front());

            if (mx.back() == v[i]) mx.pop_front();

            i++; j++;
        }
    }

    for (auto i : ans) {
        cout<<i<<" ";
    }

    cout<<"\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        Solution();
    }

    return 0;
}