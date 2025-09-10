#include<bits/stdc++.h>
using namespace std;

int maxSum(vector<int>& nums, int n) {
    int maxi = INT_MIN;

    for(int i=0; i<n; i++) {
        int sum = 0;
        for(int j=i; j<n; j++) {
            sum += nums[j];
            maxi = max(maxi, sum);
        }
    }
    
    return maxi;
}

int kadane(vector<int>& nums, int n) {
    int sum = 0;
    int maxi = INT_MIN;

    for(int el: nums) {
        sum += el;
        maxi = max(maxi, sum);
        if(sum < 0) sum = 0;
    }

    return maxi;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    // Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
    // Output: 6
    cout << "The maximum subarray sum is: " << maxSum(nums, nums.size()) << endl;
    cout << "The maximum subarray sum is: " << kadane(nums, nums.size()) << endl;

    return 0;
}