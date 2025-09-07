#include<bits/stdc++.h>
using namespace std;

vector<int> rotate(vector<int> nums, int k) {
    int n = nums.size();
    vector<int> ans(n);

    for(int i=0; i<n; i++) {
        ans[(i+k)%n] = nums[i];
    }

    return ans;
}

void rotate2(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;

    reverse(nums.begin(), nums.begin()+(nums.size()-k));
    reverse(nums.begin()+(nums.size()-k), nums.end());
    reverse(nums.begin(), nums.end());
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;

    // Input: nums = [1,2,3,4,5,6,7], k = 3
    // Output: [5,6,7,1,2,3,4]

    vector<int> ans = rotate(nums, k);
    cout << "Array after " << k << " rotations is: ";
    for(int el: ans) cout << el << ' ';
    cout << endl;

    cout << "Nums after rotation in-place is: ";
    rotate2(nums, k);
    for(int el: nums) cout << el << ' ';

    return 0;
}