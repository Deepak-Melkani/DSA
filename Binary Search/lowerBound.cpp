//  The lower bound of a number is defined as the smallest index in the sorted array where the element is >= the given number.
// If all the elements in the given array are smaller than the target, the lower bound will be the length of the array. 

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;
        
        if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    if(nums[low] >= target) return low;
    return nums.size();
}

int main() {
    vector<int> nums = {2, 3, 7, 10, 11, 11, 25}; // Output: 3
    int target = 9;

    cout << "The lower bound of " << target << " is: " << lowerBound(nums, target);

    return 0;
}