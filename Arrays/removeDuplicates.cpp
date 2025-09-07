// The below code arranges all the unique elements in the beginning of the array keeping the relative order of other elements same

#include<bits/stdc++.h>
using namespace std;

pair<int, vector<int>> removeDuplicates(vector<int>& nums) {
    int index = 0;
    int n = nums.size();

    for(int i=1; i<n; i++) {
        if(nums[i] != nums[index]) nums[++index] = nums[i];
    }

    return {index+1, nums};
}

int main() {
    vector<int> nums = {1,1,2};
    vector<int> nums2 = {0,0,1,1,1,2,2,3,3,4};

    // Input: nums = [1,1,2]
    // Output: 2, nums = [1,2,_]

    // Input: nums = [0,0,1,1,1,2,2,3,3,4]
    // Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]

    pair<int, vector<int>> p1 = removeDuplicates(nums);
    pair<int, vector<int>> p2 = removeDuplicates(nums2);

    cout << "Number of unique elements is: " << p1.first << endl;
    for(int el: p1.second) cout << el << ' ';
    cout << endl;


    cout << "Number of unique elements is: " << p2.first << endl;
    for(int el: p2.second) cout << el << ' ';
    cout << endl;

    return 0;

}