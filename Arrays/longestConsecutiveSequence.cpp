#include<bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& nums, int k) {
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] == k) return true;
    }
    return false;
}
int lcs(vector<int>& nums) {
    int n = nums.size();
    
    for(int i=0; i<n; i++) {
        int x = nums[i];
        int cnt = 1;
        while(linearSearch(nums, x+1)) {
            cnt++;
            x++;
        }
    }
}

int lcs2(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int cnt = 0;
    int last = INT_MIN;
    int maxi = 1;

    for(int i=0; i<n; i++) {
        if(nums[i] == last+1) {
            last++;
            cnt++;
        }
        else if(nums[i] != last) {
            cnt = 1;
            last = nums[i];
        }
        maxi = max(maxi, cnt);
    }

    return maxi;
}

int lcs3(vector<int> nums) {
    int n = nums.size();
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st(nums.begin(), nums.end());

    for(auto it: st) {
        if(st.find(it-1) == st.end()) {
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
}

int main() {
    vector<int> nums1 = {100,4,200,1,3,2};
    // Input: nums = [100,4,200,1,3,2]
    // Output: 4
    // Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
    cout << "The length of longest consecutive sequence is: " << lcs2(nums1);
    cout << endl;

    vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    // Input: nums = [0,3,7,2,5,8,4,6,0,1]
    // Output: 9
    cout << "The length of longest consecutive sequence is: " << lcs3(nums2);

    return 0;
}