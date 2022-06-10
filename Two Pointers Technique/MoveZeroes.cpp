/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]


Example 2:
Input: nums = [0]
Output: [0]
 

Constraints:

1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 

Follow up: Could you minimize the total number of operations done?
*/


// SOLUTION : 


#include <bits/stdc++.h>
using namespace std;

void Solution(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 1;

    while (j < n) {
        if (nums[i] == 0 && nums[j] != 0) {
            nums[i] = nums[j];
            nums[j] = 0;
            i++; j++;
        }

        else if (nums[i] != 0 && nums[j] == 0) i = j++;

        else j++;
    }

    return;
}


int main() {
    int n;
    cout<<"Enter the size of the array : "; cin>>n; 

    vector<int> nums;
    cout<<"\nEnter the array elements : ";
    for (int i = 0; i < n; i++) {
        int x; cin>>x;
        nums.push_back(x);
    }

    cout<<"\nArray after moving the 0s to the right end : ";
    Solution(nums);
    
    for (auto x : nums) cout<<x<<" ";
    cout<<"\n";
    
    return 0;
}