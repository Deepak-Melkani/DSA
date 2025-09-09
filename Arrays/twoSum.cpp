#include<bits/stdc++.h>
using namespace std;

pair<int, int> twoSum(vector<int>& nums, int n, int target) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(nums[i]+nums[j] == target) return {i, j};
        }
    }
    return {-1, -1};
}

pair<int, int> twoSum2(vector<int>& nums, int n, int target) {
    unordered_map<int, int> m;

    for(int i=0; i<n; i++) {
        if(m.find(target-nums[i]) != m.end()) return {i, m[target-nums[i]]};
        m[nums[i]] =i;
    }

    return {-1, -1};
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    // Input: nums = [2,7,11,15], target = 9
    // Output: [0,1]
    pair<int, int> p = twoSum2(nums, nums.size(), target);
    cout << "The indexes to produce " << target << " are: " << '[' << p.first << ", " << p.second << ']';

    return 0;
}