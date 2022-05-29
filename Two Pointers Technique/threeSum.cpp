#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> solSet;

    if (n >= 3) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n-2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) {
                int j = i + 1;
                int k = n - 1;

                while (j < k) {
                    if (nums[j] + nums[k] == -nums[i]) {
                        solSet.push_back({nums[i], nums[j], nums[k]});

                        while (j < k && nums[j] == nums[j + 1]) j++;
                        while (j < k && nums[k] == nums[k - 1]) k--;

                        j++; k--;
                    }


                    else if (nums[j] + nums[k] < -nums[i]) j++;

                    else k--;
                }
            }
        }
    }

    return solSet;
}



int main() {
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n; cout<<"\n";

    vector<int> nums;
    int in;
    cout<<"Enter the array elements : ";
    for (int i = 0; i < n; i++) {
        cin>>in;
        nums.push_back(in);
    }

    vector<vector<int>> solution = threeSum(nums);

    for (vector<int> i : solution) {
        for (int j : i) cout<<j<<" ";
        cout<<"\n";
    }

    return 0;
}