// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

// If target is not found in the array, return [-1, -1].

// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

#include<bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(nums[mid] == target) {
            ans = mid;
            high = mid - 1;
        }
        else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return ans;
}

int lastOccurence(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(nums[mid] == target) {
            ans = mid;
            low = mid + 1;
        }
        else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return ans;
}

int main() {
    vector<int> nums = {5,7,7,8,8,10}; // Output: [3,4]
    int target = 8;

    int focc = firstOccurence(nums, target);

    if(focc != -1) cout << "The first and last occurence of " << target << " is: " << '{' << focc << ", " << lastOccurence(nums, target) << '}';
    else cout << "Target is not present in the array";

    return 0;
}