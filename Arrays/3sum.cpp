// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums, int n) { // Brute force
    set<vector<int>> st; // To get unique triplets

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end()); // To ensure that only unique triplets will be inserted into the set
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSum2(vector<int> nums, int n) { // Better
    set<vector<int>> st;

    for(int i=0; i<n; i++) {
        set<int> s;
        for(int j=i+1; j<n; j++) {
            int third = -(nums[i] + nums[j]);
            if(s.find(third) != s.end())  {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end()); // To ensure that only unique triplets will be inserted into the set
                st.insert(temp);
            }
            s.insert(nums[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> threeSum3(vector<int> nums, int n) { // Optimal
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i=0; i<n; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int j = i + 1;
        int k = n - 1;

        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) {
                j++;
            }
            else if(sum > 0) {
                k--;
            }
            else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums1 = {-1,0,1,2,-1,-4}; // Output: [[-1,-1,2],[-1,0,1]]
    vector<int> nums2 = {0,0,0}; // Output: [[0,0,0]]

    cout << "The unique triplets that sum up to 0 are: " << endl;
    vector<vector<int>> ans = threeSum3(nums1, nums1.size());
    for(auto v: ans) {
        for(int el: v) cout << el << ' ';
        cout << endl;
    }

    return 0;
}