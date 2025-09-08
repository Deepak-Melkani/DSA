#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int>& nums, int n) {
    int cnt = 0;
    int maxi = 0;
    for(int i=0; i<n; i++) {
        if(nums[i] == 1) cnt++;
        else cnt = 0;
        maxi = max(maxi, cnt);
    }
    maxi = max(maxi, cnt);
    return maxi;
}

int main() {
    vector<int> nums = {1,1,0,1,1,1};
    // Input: nums = [1,1,0,1,1,1]
    // Output: 3

    cout << "Max consecutive ones: " << maxConsecutiveOnes(nums, nums.size());

    return 0;
}