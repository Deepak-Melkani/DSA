// Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements. 

// Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
// Output: a[] = [2, 2, 3, 4], b[] = [7, 10]
// Explanation: After merging the two non-decreasing arrays, we get, [2, 2, 3, 4, 7, 10]

#include<bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int>& a, vector<int>& b) { // Brute force (Using extra space)
    int n = a.size();
    int m = b.size();
    vector<int> ans;
    int i = 0;
    int j = 0;
    int k = 0;
    
    
    while(i < n && j < m) {
        if(a[i] <= b[j]) ans.push_back(a[i++]);
        else ans.push_back(b[j++]);
    }
    
    while(i < n) ans.push_back(a[i++]);
    while(j < m) ans.push_back(b[j++]);
    
    i = 0, j = 0;
    while(i < n) a[i++] = ans[k++];
    while(j < m) b[j++] = ans[k++];
}

void mergeArrays2(vector<int>& a, vector<int>& b) { // Optimal, The other optimal way is using the gap method that uses the concept of shell sort
    int n = a.size();
    int m = b.size();
    
    int left = n-1;
    int right  = 0;
    
    while(left >= 0 && right < m) {
        if(a[left] > b[right]) swap(a[left--], b[right++]);
        else break;
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

int main() {
    vector<int> nums1 = {2, 4, 7, 10}; // Output: a[] = [2, 2, 3, 4]
    vector<int> nums2 = {2, 3}; // Output: b[] = [7, 10]
    mergeArrays(nums1, nums2);
    
    cout << "nums1: ";
    for(int el: nums1) cout << el << ' ';
    cout << endl;

    cout << "nums2: ";
    for(int el: nums2) cout << el << ' ';

    return 0;
}