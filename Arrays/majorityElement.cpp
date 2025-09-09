#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums, int n) {
    unordered_map<int, int> m;
    for(int el: nums) m[el]++;

    for(auto it: m) if(it.second > n/2) return it.first;

    return -1;
}

int mooreVoting(vector<int>& nums, int n) {
    int maxi = nums[0];
    int cnt = 1;

    for(int i=1; i<n; i++) {
        if(cnt == 0) {
            maxi = nums[i];
            cnt = 1;
        }
        else if(nums[i] == maxi) cnt++;
        else cnt--;
    }

    // If it's not given that there surely exists a number that occurs more than n/2 times, only then the below code is useful
    cnt = 0;
    for(int el: nums) if(el == maxi) cnt++;
    
    return (cnt > n/2) ? maxi : -1;
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2}; // Find the element that occurs > n/2 times
    // Input: nums = [2,2,1,1,1,2,2]
    // Output: 2
    cout << "The majority element is: " << majorityElement(nums, nums.size()) << endl;
    cout << "The majority element using mooreVoting algo is: " << mooreVoting(nums, nums.size());

    return 0;
}