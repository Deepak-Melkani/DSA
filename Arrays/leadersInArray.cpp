// You are given an array arr of positive integers. Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right. The rightmost element is always a leader.

#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& nums, int n) {
    vector<int> ans;
    ans.push_back(nums.back());
    int maxi = nums.back();
    
    for(int i=n-2; i>=0; i--) {
        if(nums[i] >= maxi) {
            maxi = nums[i];
            ans.push_back(maxi);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> nums = {10, 4, 2, 4, 1};
    // Input: arr = [10, 4, 2, 4, 1]
    // Output: [10, 4, 4, 1]

    vector<int> ans = leaders(nums, nums.size());
    cout << "The leaders array is: ";
    for(int el: ans) cout << el << ' ';

    return 0;
}