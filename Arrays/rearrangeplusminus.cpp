// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.

#include<bits/stdc++.h>
using namespace std;

void rearrange(vector<int>& nums, int n) {
    vector<int> pos;
    vector<int> neg;

    for(int& el: nums) {
        if(el > 0) pos.push_back(el);
        else neg.push_back(el);
    }

    int i = 0;
    int k = 0;
    while(i < pos.size()) {
        nums[k++] = pos[i];
        nums[k++] = neg[i];
        i++;
    }
}

void rearrange1(vector<int>& nums, int n) {
    int pos = 0;
    int neg = 1;
    vector<int> ans(n);

    for(int el: nums) {
        if(el > 0) {
            ans[pos] = el;
            pos += 2;
        }
        else {
            ans[neg] = el;
            neg += 2;
        }
    }
    nums = ans;
}

int main() {
    vector<int> nums = {3,1,-2,-5,2,-4};
    // Input: nums = [3,1,-2,-5,2,-4]
    // Output: [3,-2,1,-5,2,-4]
    rearrange1(nums, nums.size());
    cout << "The array after rearrangements is: ";
    for(int el: nums) cout << el << ' ';

    return 0;
}