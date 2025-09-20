#include<bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(nums[mid] == target) {
            ans = mid;
            high = mid - 1;
        }
        else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return ans;
}
    
int lastOccurence(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(nums[mid] == target) {
            ans = mid;
            low = mid + 1;
        }
        else if(nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 2, 2, 3}; // Output: 4 (If the target is not present return 0)
    int target = 2;

    int focc = firstOccurence(nums, target);
    if(focc != -1) cout << target << " occurs " << lastOccurence(nums, target) - focc + 1 << " times in the array";
    else cout << "The given target value is not present in the array";
    return 0;
}