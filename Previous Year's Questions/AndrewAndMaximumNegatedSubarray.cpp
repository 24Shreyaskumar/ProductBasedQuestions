//PROBLEM STATEMENT: 

/*Andrew likes solving problems and dealing with prime numbers. He recently came across a problem in which he was given a list of numbers and he was supposed to find out a subarray from this list which starts and ends in a prime number and which has minimum count of negative numbers in it. In case two or more such subarrays have the same minimum count of negative numbers then please report an array which has the maximum length from the two.

Note: The length of the subarray is inclusive of both the starting and ending prime numbers.

Input Format

The first line of input contains an integer n which is the total elements in the list. The following line contains space separated n integers.

Constraints

1 <= N <= 10000
-10000 <= element <= 1000000

Output Format

Print a single integer which is the length of the subarray which starts and ends with a prime number and has the least count of negative numbers. In case two or more subarrays have the same count of negative numbers, then print the length of the bigger array.

Sample Input 0:
6
1 2 -3 4 5 7


Sample Output 0:
2


Explanation 0:
In this sample test case, the subset between 2 and 5 has one negative number whereas the subset between 5 and 7 has no negative number hence the length of subset from 5 and 7 with both of them as inclusive is 2.
*/


#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
 
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
 
    return true;
}


int Solution(vector<int> &arr) {
    int n = arr.size();
    int i = -1, j = -1, k = 0;
    int countOfNegative = 0;
    int minNegative = INT_MAX;
    int maxLen = 0;
    
    for (int x = 0; x < n; x++) {
        if (isPrime(arr[x])) {
            i = x;
            break;
        }
    }
    
    for (int y = n - 1; y >= 0; y--) {
        if (isPrime(arr[y])) {
            j = y;
            break;
        }
    }
    
    if (i == -1 || j == -1) { 
        return 0;
    } 
    
    if (i != -1 && j != -1 && i == j) return 1;
    
    k = i + 1;
    
    while (k <= j) {
        if (k == j) {
            while (i < k) {
                if (arr[i] < 0) countOfNegative--;
                
                if (isPrime(arr[i])) {
                    if (countOfNegative == minNegative) {
                        maxLen = max(maxLen, k - i + 1);
                    }
                    
                    if (countOfNegative < minNegative) {
                        maxLen = k - i + 1;
                    }
                }
                
                
                i++;
            }
            k++;
        }
        
        else if (arr[k] < 0) countOfNegative++;
        
        else if (isPrime(arr[k])) {
            if (countOfNegative == minNegative) {
                maxLen = max(maxLen, k - i + 1);
            }
            
            else if (countOfNegative < minNegative) {
                minNegative = countOfNegative;
                maxLen = k - i + 1;
            }
        }
        
        k++;
    }
    
    return maxLen;
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