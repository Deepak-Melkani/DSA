#include<bits/stdc++.h>
using namespace std;

int largestElement(vector<int>& nums, int n) {
    int maxi = INT_MIN;

    for(int el: nums) {
        if(el > maxi) maxi = el;
    }

    return maxi;
}

int largestElement2(vector<int>& nums, int n) {
    sort(nums.begin(), nums.end());
    return nums.back();
}

int main() {
    vector<int> nums = {1,5,9,7,12,6,0,21};
    cout << "The largest element is: " << largestElement2(nums, nums.size());

    return 0;
}