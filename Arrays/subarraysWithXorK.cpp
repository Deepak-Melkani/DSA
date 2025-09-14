// Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

#include<bits/stdc++.h>
using namespace std;

int subarrayXor(vector<int>& nums, int k) {
    int n = nums.size();
    int cnt = 0;

    for(int i=0; i<n; i++) {
        int XOR = 0;
        for(int j=i; j<n ;j++) {
            XOR ^= nums[j];
            if(XOR == k) cnt++;
        }
    }

    return cnt;
}

int subarrayXor2(vector<int> &nums, int k) {
    long cnt = 0;
    int n = nums.size();
    unordered_map<int, int> m;
    int XOR = 0;
    m[0] = 1;
    
    for(int i=0; i<n; i++) {
        XOR ^= nums[i];
        if(m.find(XOR^k) != m.end()) cnt += m[XOR^k];
        m[XOR]++;
    }
    
    return cnt;
}

int main() {
    vector<int> nums = {4, 2, 2, 6, 4}; // Output: 4
    int k = 6;

    cout << "The number of subarrays having XOR of their elements as " << k << " are: " << subarrayXor2(nums, k);

    return 0;
}