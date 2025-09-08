#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& nums, int k) {
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] == k) return i;
    }
    return -1;
}

int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    int k = 11;
    int index = linearSearch(nums, k);

    (index != -1) ? cout << k << " is present at index: " << index : cout << k << " is not present in the given array";

    return 0;
}