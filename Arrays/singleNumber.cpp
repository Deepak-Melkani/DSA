#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums, int n) {
    int x = 0;
    for(int el: nums) x ^= el;

    return x;
}

int singleNumber2(vector<int>& nums, int n) {
    unordered_map<int, int> m;
    for(int el: nums) m[el]++;

    for(auto it: m) {
        cout << it.first << ' ' << it.second << "\t";
        if(it.second == 1) return it.first;
    }
    return -1;
}

int main() {
    vector<int> nums = {4,1,2,1,2}; // Every number occurs twice except one, return the number with single occurence
    // Input: nums = [4,1,2,1,2]
    // Output: 4
    cout << "The number with single occurence is: "  << singleNumber(nums, nums.size());

    return 0;
}