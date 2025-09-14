// Given a sorted array of distinct integers and a target value, return the index if the target is found. 
// If not, return the index where it would be if it were inserted in order.

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;

    while(low <= high) {
        mid = low + (high-low)/2;

        if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return low;
}

int main() {
    vector<int> nums = {1,3,5,6};
    
    cout << "Insert position for 5 is: " << lowerBound(nums, 5) << endl;
    cout << "Insert position for 2 is: " << lowerBound(nums, 2) << endl; 

    return 0;
}