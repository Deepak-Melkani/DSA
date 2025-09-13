// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. => min elements = 0 and max = n/3, for 8 => 2

#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> nums, int n) {
    unordered_map<int, int> m;
    vector<int> ans;
    for(int el: nums) m[el]++;

    for(auto it: m) {
        if(it.second > n/3) ans.push_back(it.first);
    }
    return ans;
}

vector<int> majorityElement2(vector<int> nums, int n) { // Moore Voting 
    vector<int> ans;
    int el1 = INT_MIN, cnt1 = 0;
    int el2 = INT_MIN, cnt2 = 0;

    for(int i=0; i<n; i++) {
        if(cnt1 == 0 && nums[i] != el2) {
            el1 = nums[i];
            cnt1++;
        }
        else if(cnt2 == 0 && nums[i] != el1) {
            el2 = nums[i];
            cnt2++;
        }
        else if(nums[i] == el1) cnt1++;
        else if(nums[i] == el2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = 0, cnt2 = 0;
    for(int el: nums) {
        if(el == el1) cnt1++;
        else if(el == el2) cnt2++;
    }
    if(cnt1 > n/3) ans.push_back(el1);
    if(cnt2 > n/3) ans.push_back(el2);

    return ans;
}

int main() {
    vector<int> nums1 = {3,2,3}; // Output: [3]
    vector<int> nums2 = {1,2}; // Output: [1,2]
    
    cout << "The majority elements in nums1 are: ";
    vector<int> ans = majorityElement2(nums1, nums1.size());
    for(int el: ans) cout << el << ' ';
    cout << endl;

    cout << "The majority elements in nums2 are: ";
    vector<int> res = majorityElement2(nums2, nums2.size());
    for(int el: res) cout << el << ' ';
    cout << endl;
}