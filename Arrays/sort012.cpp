#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int>& nums) {
    sort(nums.begin(), nums.end());
}

void dutchFlag(vector<int>& nums) {
    int n = nums.size();
    int low = 0;
    int mid = 0;
    int high = n -1;

    while(mid <= high) {
        if(nums[mid] == 0) swap(nums[low++], nums[mid++]);
        else if(nums[mid] == 1) mid++;
        else swap(nums[mid], nums[high--]);
    }
}

int main() {
    vector<int> nums = {2,0,2,1,1,0};
    dutchFlag(nums);
    cout << "Array after sorting is: ";
    for(int el: nums) cout << el << ' ';

    return 0;
}