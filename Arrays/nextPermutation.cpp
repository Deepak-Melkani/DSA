#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> nums) {
    next_permutation(nums.begin(), nums.end());
    return nums;
}

void nextPermutation1(vector<int>& nums) {
    int n = nums.size();
    int ind = -1;

    for(int i=n-2; i>=0; i--) {
        if(nums[i] < nums[i+1]) {
            ind = i;
            break;
        }
    }
    
    if(ind == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    for(int i=n-1; i>ind; i--) {
        if(nums[i] > nums[ind]) {
            swap(nums[i], nums[ind]);
            break;
        }
    }
    reverse(nums.begin()+ind+1, nums.end());
}

int main() {
    vector<int> nums1 = {1,2,3};
    // Input: nums = [1,2,3]
    // Output: [1,3,2]

    vector<int> nums2 = {3,2,1};
    // Input: nums = [3,2,1]
    // Output: [1,2,3]

    vector<int> nums3 = {1,1,5};
    // Input: nums = [1,1,5]
    // Output: [1,5,1]

    cout << "The next permutation is: ";
    vector<int> ans = nextPermutation(nums1);
    for(int el: ans) cout << el << ' ';
    cout << endl;

    nextPermutation1(nums1); // The smallest or first permutation will be the sorted array since all the numbers will form the smallest arrangement
    nextPermutation1(nums2); // The largest permutation will be the sorted array in descending order
    nextPermutation1(nums3); // The next permutation for the array sorted in desc order will be the array in asc order or reverse of original array

    cout << "The next permutation of nums1 is: ";
    for(int el: nums1) cout << el << ' ';
    cout << endl;

    cout << "The next permutation of nums2 is: ";
    for(int el: nums2) cout << el << ' ';
    cout << endl;

    cout << "The next permutation of nums3 is: ";
    for(int el: nums3) cout << el << ' ';
    cout << endl;
}