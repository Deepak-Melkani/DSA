#include<bits/stdc++.h>
using namespace std;

int subarrayCount(vector<int>& nums, int n, int k) { // Brute Force
    int cnt = 0;
    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += nums[j];
            if(sum == k) cnt++;
        }
    }
    return cnt;
}

int subarrayCount1(vector<int>& nums, int n, int k) { // Optimal
    unordered_map<int, int> m;
    m[0] = 1;
    int sum = 0;
    int cnt = 0;

    for(int i=0; i<n; i++) {
        sum += nums[i];
        cnt += m[sum-k];
        m[sum]++;
    }
    return cnt;
}

int main() {
    vector<int> nums = {1,2,3,-3,1,1,1,4,2,-3}; // Output: 8
    int k = 3;
    // Input: nums = [1,1,1], k = 2
    // Output: 2
    cout << "The number of subarrays with sum " << k << " are: " << subarrayCount1(nums, nums.size(), k);

    return 0;
}