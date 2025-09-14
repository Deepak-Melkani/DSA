#include<bits/stdc++.h>
using namespace std;

int longestWith0Sum(vector<int>& nums, int n) {
    int maxi = 0;
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += nums[j];
            if(sum == 0) maxi = max(maxi, j-i+1);
        }
    }
    return maxi;
}

int longestWith0Sum2(vector<int>& nums, int n) {
    unordered_map<int, int> m;
    int preSum = 0;
    int maxi = 0;

    for(int i=0; i<n; i++) {
        preSum += nums[i];
        if(preSum == 0) maxi = i + 1;
        if(m.find(preSum) != m.end()) maxi = max(maxi, i-m[preSum]);
        if(m.find(preSum) == m.end()) m[preSum] = i;
    }

    return maxi;
}

int main() {
    vector<int> nums = {15, -2, 2, -8, 1, 7, 10, 23}; // Output: 5 (The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7])
    cout << "The length of the longest subarray with sum = 0 is: " << longestWith0Sum2(nums, nums.size());

    return 0;
}