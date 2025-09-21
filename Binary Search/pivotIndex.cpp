// Pivot element is element in a rotated sorted array that breaks the flow of the sorted behaviour in the array

#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    while(low < high) {
        int mid = (low + high) / 2;

        if(nums[mid] >= nums[0]) low = mid + 1;
        else high = mid;
    }

    return low;
}

int main() {
    vector<int> nums = {7, 9, 1, 2, 3};

    cout << "The pivot index is: " << getPivot(nums);

    return 0;
}