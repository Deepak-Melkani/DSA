#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums, int n) {
    int left = 0;

    for(int right=0; right<n; right++) {
        if(nums[right] != 0) swap(nums[right], nums[left++]);
    }
}

void moveZeroes1(vector<int>& nums, int n) {
    int zerocnt = 0;
    int index = 0;

    for(int i=0; i<n; i++) {
        if(nums[i] == 0) zerocnt++;
        else nums[index++] = nums[i];
    }

    while(index < n) nums[index++] = 0;
}

int main() {
    vector<int> nums = {0,1,0,3,12};
    // Input: nums = [0,1,0,3,12]
    // Output: [1,3,12,0,0]
    moveZeroes1(nums, nums.size());

    cout << "The elements after  modifications are: ";
    for(int el: nums) cout << el << ' ';

    return 0;
}