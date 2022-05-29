#include <iostream>
#include <vector>
#include <deque>

using namespace std;

bool isPrime(int x) {
    if (x > 1) {
        if (x == 2) return true;

        for (int i = 2; i <= x/2; i++) {
            if (x % i == 0) return false;
        }

        return true;
    }

    return false;
}


//2 3 4 5 6 7 8 9 -1 11 -4 14 17 23 31
int Solution (vector<int> &arr) {
    int n = arr.size();
    int i = 0, j = 0, k, x, y, z;
    int l = -1; 
    int nc = INT_MAX, c = 0;
    deque<int> primeLoc;
    vector<int> negativeLoc;

    for (x = 0; x < n; x++) {if (isPrime(arr[x])) primeLoc.push_back(x); }
    for (y = 0; y < n; y++) {if (arr[y] < 0) negativeLoc.push_back(y); }
    

    if (primeLoc.size() == 0) return l;
    if (primeLoc.size() == 1) return 1;
    if (negativeLoc.size() == 0) {
        return primeLoc[primeLoc.size() - 1] - primeLoc[0] + 1;
    }

    x = 0, y = x + 1;
    j = primeLoc[y++]; i = primeLoc[x++]; 
    k = 0; z = 0;
    while (x < primeLoc.size() - 1) {
        while (negativeLoc[k] > i && negativeLoc[k] < j && k < negativeLoc.size()) {
            c++;
            k++;
            
        }

        if (c == 0 || c == nc) {
            nc = c;
            l = max(l, j - i + 1);
            if (c == 0 && k < negativeLoc.size() && negativeLoc[k] > j && negativeLoc[k] < primeLoc[y]) {
                if (x < primeLoc.size() - 1) i = primeLoc[x++];
            }

            if (y < primeLoc.size()) j = primeLoc[y++];
        }

        /*if (c == nc) {
            l = max(l, j - i + 1);
            if (y < primeLoc.size()) j = primeLoc[y++];
        }*/
        

        else if (c < nc) {
            nc = c;
            l = j - i + 1;
            if (y < primeLoc.size()) j = primeLoc[y++];
        }

        else if (c > nc) {
            while (negativeLoc[z] > i && negativeLoc[z] < primeLoc[x]){
                c--;
                z++;
            }
            i = primeLoc[x++];
        }

    }

    if (c == nc) l = max(l, j - i + 1);

    else if (c < nc) {
        nc = c;
        l = j - i + 1;
    }

    return l;
}


int main() {
    int n;
    cout<<"Enter the size of the array : "; cin>>n;

    vector<int> arr;
    cout<<"\nEnter the array elements : ";
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        arr.push_back(x);
    }

    int maxLen = Solution(arr);
    cout<<"\nLength of maximum negated subarray : "<<maxLen;
}


/*while (k < j) {
            if (arr[k] < 0) c++;
            k++;
        }

        if (c == nc) l = max(l, j - i + 1);

        if (c < nc) {
            nc = c;
            l = j - i + 1;
        }

        //c = 0;
        //i = j;
        j = primeLoc[y++];
        k = j;

        if (y == primeLoc.size())*/


/*#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if(n <= 1) return false;
    if(n == 2 || n == 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 5; i * i <= n; i += 6) {
        if(n %i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n; 
    cin >> n;
    int a[n] = {0};
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // int n = 6;
    // int a[n] = {1,2,-3,4,5,7};
    if(n <= 1) { cout << 0;  return 0; }
    if(n == 2) {
        if(isPrime(a[0]) && isPrime(a[1])) {
            cout << 2; 
        } else {
            cout << 0;
        }
        return 0;
    }
    
    int start = -1, end = -1;
    // map<int, int> mpp;
    vector<int> first;
    vector<int> second;
    vector<int> vc;
    int countOfNeg = 0;
    
    for(int i = 0; i < n; ++i) {
        
        bool res = isPrime(a[i]);       // if num < 0 return false 
        
        if(res && start == -1) {
            start = i;  countOfNeg = 0;
            continue;
        }
        
        if(a[i] < 0) {
            countOfNeg++;
            continue;
        }
        
        if(res && start != -1 && end == -1) {
            end = i;
            // mpp.insert({start, end});
            first.push_back(start);
            second.push_back(end);
            vc.push_back(countOfNeg);

            
            start = end, end = -1, countOfNeg = 0;
            continue;
        }
    }
    if(first.size() == 0) return 0;
    
    // find the min Negatives subset
    int mini = INT_MAX -1;
    
    for(int i = 0; i < vc.size(); ++i) {
        if(vc[i] < mini) {
            mini = vc[i];
        }
    }
    // cout << mini << " ";
    
    // now find the max length subset (with min negatives)
    int maxLen = -1;
    int maxIndx = -1;
    for(int i = 0; i < vc.size(); ++i) {
        if(vc[i] == mini) {
            if(maxLen < (second[i]  - first[i])) {
                maxLen = second[i] - first[i];
                maxIndx = i;
            }
        }
    }
    
    cout << (second[maxIndx] - first[maxIndx] + 1);
    
    return 0;
}*/