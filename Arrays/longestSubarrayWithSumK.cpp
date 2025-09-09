#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int>& nums, int n, int k) {
    int maxi = INT_MIN;

    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += nums[j];
            if(sum == k) maxi = max(maxi, j-i+1);
        }
        cout << endl;
    }
    return maxi;
}

int longestSubarrayWithSumK2(vector<int>& nums, int n, int k) { // Helpful if negatives are also present
    unordered_map<int, int> m;
    int preSum = 0;
    int maxi = INT_MIN;

    for(int i=0; i<n; i++) {
        preSum += nums[i];
        if(preSum == k) maxi = i + 1;
        else if(m.find(preSum - k) != m.end()) {
            maxi = max(maxi, i - m[preSum-k]);
        }
        if(m.find(preSum) == m.end()) // This condition helps in getting the longest subarray by selecting the leftmost index that gives (preSum-k)
        m[preSum] = i;
    }

    return maxi;
}

int longestSubarrayWithSumK3(vector<int>& nums, int n, int k) { //Works for cases where all elements are positive since dec. window means red. sum
    int len = 0;
    int sum = 0;
    int n = nums.size();
    int left = 0;
    int right = 0;
    
    while(right < n) {
        sum += nums[right];
        while(sum > k) {
            sum -= nums[left];
            left++;
        }
        if(sum == k) len = max(len, right-left+1);
        right++;
    }
    
    return len;
}

int main() {
    vector<int> nums = {-5, 8, -14, 2, 4, 12};
    int k = -5;

    // Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
    // Output: 6
    // Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.

    // Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
    // Output: 5
    // Explanation: Only subarray with sum = -5 is [-5, 8, -14, 2, 4] of length 5.

    cout << "The longest subarray with a sum of " << k << " is of length: " << longestSubarrayWithSumK2(nums, nums.size(), k);

    return 0;
}