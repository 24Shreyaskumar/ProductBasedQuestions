/*Limak the little polar bear was sitting in a contest which was important to him. He came across a problem where he was given two integers namely N the number of elements and another integer K. He was also given N integers and he was supposed to report the elements which has the largest number of ones in the binary representation of elements in each subarray of size K which can be formed using the given array. Limak can solve this problem quickly, can you also write code for this problem?

Note: In case two elements have the same number of ones in their binary representation, then the element which comes later in the sequence should be reported. Eg out of 1, 2 since both have the same number of ones in their binary representation, 2 should be reported as the answer.

Input Format

The first line of input contains two space separated integers N and K denoting the number of elements and size of the subarray respectively. The next line contains N space separated integers denoting the elements of the array.

Constraints

1 <= N <= K <= 100000
1 <= elements <= 100000

Output Format

Print the elements which have the largest number of ones in the binary representation of elements present in each sub array of size K which can formed from the given array.

Note: In case two elements have the same number of ones in their binary representation, then the element which comes later in the sequence should be reported. Eg out of 1, 2 since both have the same number of ones in their binary representation, 2 should be reported as the answer.


Sample Input 0 : 
5 2
1 2 3 4 5

Sample Output 0
2 3 3 5

Explanation 0
In this sample test case, the number of elements are 5 and K is 2. All subarrays of length 2 are [1, 2], [2, 3], [3, 4], [4, 5] and the answer with the maximum number of ones in the binary representation of the numbers is being reported. Out of 1 and 2 since both of them have the same number of ones in the binary representation, we report 2 as the answer as it comes later. */


#include <bits/stdc++.h>
using namespace std;

int decimalToBinary(int decimal) {
    long long int binary, product = 1, remainder, size;
    
    while (decimal != 0) {
        remainder = decimal % 2;
        binary += remainder * product;
        decimal /= 2;
        product *= 10;
    }
    
    string binaryStr;
    binaryStr = to_string(binary);
    
    int count = 0;
    size = binaryStr.size();
    for (int i = 0; i < size; i++) {
        if (binaryStr[i] == '1') count++;
    }
    
    return count;
}

vector<int> Solution(vector<int> &arr, int k) {
    int n = arr.size();
    int i = 0, j = 0;
    int countOfOnes = 0;
    int maxCount = INT_MIN;
    map<int, int> max;
    vector<int> result;
    
    if (n == 0) {
        result.push_back(0);
        return result;
    }

    if (n == 1) {
        result.push_back(arr[0]);
        return result;
    }
    
    while (j < n) {
        countOfOnes = decimalToBinary(arr[j]);
        max[countOfOnes] = j;
        if (countOfOnes > maxCount) {
            maxCount = countOfOnes;
            cout<<arr[maxCount]<<"\n";
        }

        if (j - i + 1 < k) j++;

        else if (j - i + 1 == k) {
            result.push_back(arr[max[maxCount]]);

            if (i == max[maxCount]) {
                max.erase(i);
                maxCount = INT_MIN;
            }

            i++; j++;
        }
    }

    return result;
}

int main() {
    int n; cin>>n;
    int k; cin>>k;
        
    vector<int> a;
    for (int i= 0; i < n; i++) {
        int x; cin >>x;
        a.push_back(x);
    }
    
    vector<int> r = Solution(a, k);
    for (auto i : r) cout<<i<<" ";

    return 0;
}