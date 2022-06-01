/*Limak likes programming and tries to solve as many problems as he could. One day, he came across a straightforward problem in which he was given two arrays containing N elements each and he was supposed to print the matching subsequences from the two arrays. The matching subsequences are to be printed with the smallest subsequence first followed by the next larger subsequence on the next line and so on. The subsequences from the first array are to be matched to the subsequences of the second array. Limak is busy with some other involvement. Can you help Limak with this problem?

Note 1 : In case there are no matching subsequences in the two arrays, print -1.
Note 2 : The subsequences of an array [1, 2, 3] are [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3].

Input Format

The first line of input contains an integer N which is the total number of elements in one array. The next line contains N unique space separated integers which are elements of array A. The following line contains N unique space separated integers which are elements of array B.

Constraints

1 <= N <= 10
1 <= elements in array <= 20
All elements within an array are unique

Output Format

Print the smallest matching subsequence from array A and array B first, followed by the next matching subsequence on next line arranged in ascending order of their lengths. In case there are no matching subsequences print -1. All the elements in a subsequence are space separated. Please look at the sample test case for more clarity.


Sample Input 0
3
1 2 3
1 2 3

Sample Output 0
1
2
3
1 2
1 3
2 3
1 2 3

Explanation 0
In this sample test case, the two arrays contain elements [1, 2, 3]. The subsequences of the arrays are [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]. The smallest matching subsequences are printed first on separate lines hence 1 is printed first as it is the smallest subsequence and occurs in A first. Also the subsequences are to be printed in the order in which they appear in array A. As an example [1, 3] is printed before [2, 3]. */



#include <bits/stdc++.h>
using namespace std;

void Solution(vector<int> &a, vector<int> &b){
    int n = a.size();
    int m = b.size();
    int i = 0,  j = 0;
    vector<int> result;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n == 0 || m == 0) {
        cout<<"-1";
        return;
    }
    while (i < n && j < n) {
        if (a[i] == b[j]) {
            result.push_back(a[i]);
            i++;
            j++;
        }
        
        else if (a[i] < b[j]) i++;
        
        else j++;
    }
    
    if (result.size() == 0) {
        cout<<"-1";
        return;
    }
    
    bool *c = new bool[result.size()]{0};
    
    for (int x = 0; x < result.size(); x++) {
        c[x] = 1;
        
        do{
            for (int y = 0; y < result.size(); y++) {
                if(c[y]) cout<<result[y]<<" ";
            }
            cout<<"\n";
        } while(prev_permutation(c, c + result.size()));
    }
}
int main() {
    
    int n; cin>>n;
    vector<int> a;
    vector<int> b;
    
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        a.push_back(x);
    }
    
    for (int j = 0; j < n; j++) {
        int y; cin>>y;
        b.push_back(y);
    }
    
    Solution(a, b);
    return 0;
}

