// Given an array of integers arr[]. You have to find the Inversion Count of the array. 
// Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

#include<bits/stdc++.h>
using namespace std;

int inversionCount(vector<int> &nums) { // Brute force approach
    int n = nums.size();
    int cnt = 0;
    
    for(int i=0; i<n; i++) {
        int left = nums[i];
        for(int j=i+1; j<n; j++) {
            if(left > nums[j]) cnt++;
        }
    }
    
    return cnt;
}

int merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0;
    
    while(left <= mid && right <= high) {
        if(nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        }
        else {
            temp.push_back(nums[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    
    while(left <= mid) temp.push_back(nums[left++]);
    while(right <= high) temp.push_back(nums[right++]);
    
    for(int i=low; i<=high; i++) {
        nums[i] = temp[i-low];
    }
    
    return cnt;
}

int mergeSort(vector<int>& nums, int low, int high) { // Optimal approach
    int cnt = 0;
    if(low >= high) return cnt;
    int mid = low + (high-low)/2;
    
    cnt += mergeSort(nums, low, mid);
    cnt += mergeSort(nums, mid+1, high);
    
    cnt += merge(nums, low, mid, high);
    
    return cnt;
}

int main() {
    vector<int> nums = {2, 4, 1, 3, 5};
    cout << "The inversion count is: " << mergeSort(nums, 0, nums.size()-1); // Output: 3

    return 0;
}