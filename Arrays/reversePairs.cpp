// Given an integer array nums, return the number of reverse pairs in the array.
// A reverse pair is a pair (i, j) where:
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

// Input: nums = [2,4,3,5,1]
// Output: 3
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
// (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1

#include<bits/stdc++.h>
using namespace std;

int reversePairs(vector<int>& nums) { // Brute force
    int n = nums.size();
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int a = nums[i];
            long long b = nums[j];
            b += nums[j];
            if(a > b)
            ans++;
        }
    }
    return ans;
}

void merge(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    }

    while(left <= mid) temp.push_back(arr[left++]);
    while(right <= high) temp.push_back(arr[right++]);

    for(int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }
}

int countPairs(vector<int>& arr, int low, int mid, int high) {
    int right = mid + 1;
    int cnt = 0;
    
    for(int i=low; i<=mid; i++) {
        while(right <= high && (long long)arr[i] > 2LL*arr[right]) right++;
        cnt += (right - (mid + 1));
    }

    return cnt;
}  

int mergeSort(vector<int>& arr, int low, int high) { // Optimal
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = (low + high) / 2;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += countPairs(arr, low, mid, high);

    merge(arr, low, mid, high);

    return cnt;
}

int main() {
    vector<int> nums = {2,4,3,5,1}; // Output: 3
    cout << "The number of reverse pairs is: " << reversePairs(nums) << endl;

    cout << "The number of reverse pairs using merge sort is: " << mergeSort(nums, 0, nums.size()-1);

    return 0;
}