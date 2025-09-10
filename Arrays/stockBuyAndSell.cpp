#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& nums, int n) {
    int maxi = 0;
    int mini = nums[0];

    for(int i=1; i<n; i++) { // Starting from 1st index cuz to sell we must buy it before and there is no point in buying n selling on day 0
        maxi = max(maxi, nums[i]-mini);
        mini = min(mini, nums[i]);
    }

    return maxi;
}

int main() {
    vector<int> nums = {7,1,5,3,6,4};
    // Input: prices = [7,1,5,3,6,4]
    // Output: 5
    // Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
    // Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
    
    cout << "The max profit possible is: " << maxProfit(nums, nums.size());

    return 0;
}