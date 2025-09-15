#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums, int n) {
    int maxi = INT_MIN;
    
    for(int i=0; i<n; i++) {
        int pro = 1;
        for(int j=i; j<n; j++) {
            pro *= nums[j];
            maxi = max(maxi, pro);
        }
    }

    return maxi;
}

int maxProduct2(vector<int>& nums, int n) {
    int maxi = INT_MIN;
    int pre = 1;
    int suf = 1;

    for(int i=0; i<n; i++) {
        if(pre == 0) pre = 1;
        if(suf == 0) suf = 1;

        pre *= nums[i];
        suf *= nums[n-i-1];

        maxi = max(maxi, max(pre, suf));
    }
    return maxi;
}

int main() {
    vector<int> nums = {2,3,-2,4}; // Output: 6

    // Observations to solve optimally: 
    // If all the elements are positive the answer is product of entire array
    // If there are even number of negatives then the answer is product of entire array
    // If there are odd number of negatives then we need to find the answer by ignoring one -ve value
    // If there are zeros, we need to check the product before and after zero's positions

    cout << "The maximum product is: " << maxProduct2(nums, nums.size());

    return 0;
}