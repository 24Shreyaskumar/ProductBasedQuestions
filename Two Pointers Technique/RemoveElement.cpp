/*
Problem Statement : 
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.


Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).


Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).


Constraints:
0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100
*/


#include <bits/stdc++.h>
using namespace std;

int Solution(vector<int>& nums, int val) {
    int i = 0, j = 1;
    int temp;
    
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) {
        if (nums[0] == val) return 0;
        return 1;
    }
    if (find(nums.begin(), nums.end(), val) == nums.end()) return nums.size();

    while (j < nums.size()) {
        if (nums[i] == val && nums[j] != val) {
            temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;

            i++; j++;
        }

        else if (nums[i] != val && nums[j] == val) i = j++;

        else j++;
    }

    return i;
}

int main() {
    int n; 
    cout<<"Enter the size of the array : "; cin>>n;

    vector<int> nums;
    cout<<"Enter the array elements : ";
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        nums.push_back(x);
    }

    int val;
    cout<<"Enter the value : "; cin>>val;

    int k = Solution(nums, val);

    cout<<"The modified array is : ";
    for (int j = 0; j < k; j++) cout<<nums[j]<<" ";
    cout<<endl;

    return 0;
}
 