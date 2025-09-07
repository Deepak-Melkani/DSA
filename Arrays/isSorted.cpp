#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> nums) {
    int n = nums.size();
    int cnt = 0;

    for(int i=1; i<n; i++) {
        if(nums[i] < nums[i-1]) cnt++;
    }

    if(nums[0] < nums[n-1]) cnt++;

    return cnt <= 1;
}

bool isSorted2(vector<int> nums) {
    vector<int> arr = nums;
    sort(nums.begin(), nums.end());
    return arr == nums;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6};
    vector<int> arr = {5,7,9,3,2,0};

    if(isSorted2(nums)) cout << "\"Nums\" is sorted" << endl;
    else cout << "\"Nums\" is unsorted" << endl;

    if(isSorted2(arr)) cout << "\"Arr\" is sorted" << endl;
    else cout << "\"Arr\" is unsorted" << endl;

    return 0;
}