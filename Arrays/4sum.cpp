#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> nums, int target) { // Brute Force
    int n = nums.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                for(int l=k+1; k<n; k++) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSum2(vector<int> nums, int target) { // Better
    int n = nums.size();
    set<vector<int>> st;

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            set<int> s;
            for(int k=j+1; k<n; k++) {
                int fourth = target - (nums[i] + nums[j] + nums[k]);
                if(s.find(fourth) != s.end()) {
                    vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                s.insert(nums[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> fourSum3(vector<int> nums, int target) { // Optimal
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        for(int j=i+1; j<n; j++) {
            if(j > i+1 && nums[j] == nums[j-1]) continue; 
            int k = j + 1;
            int l = n - 1;

            while(k < l) {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if(sum < target) k++;
                else if(sum > target) l--;
                else {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while(k < l && nums[k] == nums[k-1]) k++;
                    while(k < l && nums[l] == nums[l+1]) l--;
                }
            }
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {1,0,-1,0,-2,2}; // Output: [[-2,-1,1,2], [-2,0,0,2], [-1,0,0,1]]
    int target = 0;

    cout << "The unique quadruplets are: " << endl;
    vector<vector<int>> ans = fourSum3(nums, target);
    for(auto v: ans) {
        for(int el: v) cout << el << ' ';
        cout << endl;
    }

    return 0;
}