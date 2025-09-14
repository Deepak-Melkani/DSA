//  If target exists, then return its index. Otherwise, return -1.

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while(low <= high) {
        int mid = low + (high-low)/2; 
        
        if(nums[mid] == target) return mid;
        else if(target < nums[mid]) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

int main() {
    vector<int> nums = {-1,0,3,5,9,12}; // Output: 4
    int target = 9; 

    cout << "The index of " << target << " is: " << binarySearch(nums, target);

    return 0;
}