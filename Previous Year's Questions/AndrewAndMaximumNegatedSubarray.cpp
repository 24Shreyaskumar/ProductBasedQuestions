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


#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

typedef vector<int> vect;


int main() {
//Step 1:
    //input1 : the size of array, n
    int n;
    cin>>n;
    
    //input2 : the array elements
    vector<int> arr;
    int i = 0;
    int j;
    while(i < n) {
        cin>>j;
        arr.push_back(j);
        i++;
    }
    

    
    


    
//Step 2:
    //storing the positions of prime numbers :
    
    vector<int> primePositions;
    
    int flag;
    for (int itr = 0; itr < n; itr++) {
        flag = 1;
        
        for (int k = 2; k < arr[itr]; k++){
            if (arr[itr] % k == 0 && arr[itr] != 1 && arr[itr] >= 0) {
                flag = 0;
                break;
            }
        }
        
        if (flag == 1 && arr[itr] != 1 && arr[itr] >= 0) {
            primePositions.push_back(itr);
        }
    }
    
    if (primePositions.empty()) return 0; //means there is no prime number in array
    
     
    

    
//Step 3:
    //calculating the freq of negative numbers in between each prime pair
    
    map<vect, int> freq;
    
    for (int i = 0; i < primePositions.size()-1; i++) {
        if (primePositions[i+1] - primePositions[i] == 1) {
            cout<<2<<"\n";
            return 0;
        }
        
        int count = 0;
        for(int j =primePositions[i]; j < primePositions[i+1]; j++) {
             if (arr[j] < 0) {
                 count++;
             }
        }
        
        freq[{primePositions[i], primePositions[i+1]}] = count;
    }
    
    




//Step 4:
    //finding out the minimum number of negative number count in between primes and finding the corrsponding size using map key-value pair
    int m = INT_MAX;
    int size = 0;
    
    for (const auto& i : freq) {
        if (i.second == m) {
            size = std::max(size, i.first[1] - i.first[0] + 1);
        }
        
        else if (i.second < m) {
            m = i.second;
            size = i.first[1] - i.first[0] + 1;
        }
    }
    
    cout<<size<<"\n";
    
    return 0;
}