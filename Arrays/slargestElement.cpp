#include<bits/stdc++.h>
using namespace std;

int slargest(vector<int>& nums, int n) {
    int maxi = INT_MIN;
    int smaxi = INT_MIN;

    for(int el: nums) {
        if(el > maxi) maxi = el;
    }

    for(int el: nums) {
        if(el > smaxi && el != maxi) smaxi= el;
    }

    return smaxi;
}

int slargest2(vector<int>& nums, int n) {
    sort(nums.begin(), nums.end());
    return nums[n-2];
}

int slargest3(vector<int>& nums, int n) {
    int maxi = INT_MIN;
    int smaxi = nums.front();

    for(int el: nums) {
        if(el > maxi) {
            smaxi = maxi;
            maxi = el;
        }
        else if(el > smaxi && el < maxi) smaxi = el;
    }
    return smaxi;
}

int main() {
    vector<int> nums = {90,69,5,0,8,3,25,89,42,68,9};
    
    cout << "The second largest element in the given array is: " << slargest2(nums, nums.size());

    return 0;
}