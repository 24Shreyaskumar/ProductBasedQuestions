/*#include<iostream>
#include<climits>
using namespace std;

int Solution (int A[], int B[], int N, int M, int X) {
    int C[N + M];
    int i = 0, j = 0, k = 0;
    
    while(i < N && j < M) {
        if (A[i] <= B[i]) {
            C[k++] = A[i++];
        }

        else {
            C[k++] = B[j++];
        }
    } 

    while (i < N) {
        C[k++] = A[i++];
    }

    while (j < M) {
        C[k++] = B[j++];
    }

    
    i = 0;
    j = N + M - 1;
    int diff = INT_MAX;
    int res[2];

    while(i < j) {
        if ((C[i] + C[j]) == X) {
            cout<<C[i]<<" and "<<C[j]<<endl;
            return 0;
        }

        if (abs((C[i] + C[j]) - X) < diff ) {
            diff = abs((C[i] + C[j]) - X);
            res[0] = C[i];
            res[1] = C[j]; 
            j--;
        }

        else if (abs((C[i] + C[j]) - X) > diff) {
            i++;
        }
    }
    
    cout<<res[0]<<" and "<<res[1]<<endl;
    return diff;
}


int main() {
    int N = 4, M= 5;
    int A[] = {1, 4, 5, 7};
    int B[] = {10, 20, 30, 40, 32};
    int X = 32;

    Solution(A, B, N, M, X);

    return 0;
}*/

#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

int Solution(string s){
    int n = s.length();
    unordered_map<char, int> freq;
    int countOfcovid = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'c' || s[i] == 'o' || s[i] == 'v' || s[i] == 'i' || s[i] == 'd') freq[s[i]]++;
    }
        
    if (freq.size() == 5){ 
        for (const auto &itr : freq) countOfcovid = min(countOfcovid, itr.second);
        return countOfcovid;
    }
    
    else return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    getline(cin, s);
    
    cout<<Solution(s);
    return 0;
}