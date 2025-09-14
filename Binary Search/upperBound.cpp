// The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number.
// Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be the length of the array.

#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = 0;
    
    while(low <= high) {
        mid = low + (high-low)/2;
        
        if(nums[mid] <= target) low = mid + 1;
        else high = mid - 1;
    }
    
    if(nums[low] > target) return low;
    return nums.size();
}

int main() {
    vector<int> nums = {2, 3, 7, 10, 11, 11, 25}; // Output: 3
    int target = 9;

    cout << "The upper bound of " << target << " is: " << upperBound(nums, target);

    return 0;
}