#include<bits/stdc++.h>
using namespace std;

int missingElement(vector<int>& nums) {
    int n = nums.size();
    long tSum = (n*(n+1)) / 2;
    long sum = accumulate(nums.begin(), nums.end(), 0);

    return tSum - sum;
}

int main() {
    vector<int> nums = {9,6,4,2,3,5,7,0,1}; // The numbers are in the range [0,n] and a number among them is missing
    // Input: nums = [9,6,4,2,3,5,7,0,1]
    // Output: 8
    cout << "The missing element is: " << missingElement(nums);

    return 0;
}