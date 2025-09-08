#include<bits/stdc++.h>
using namespace std;

vector<int> unionArray(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    unordered_map<int, int> mp;
    vector<int> ans;
    for(int i=0; i<m; i++) {
        if(mp.find(arr1[i]) == mp.end()) {
            ans.push_back(arr1[i]);
            mp[arr1[i]] = i;
        }
    }

    for(int j=0; j<n; j++) {
        if(mp.find(arr2[j]) == mp.end()) {
            ans.push_back(arr2[j]);
            mp[arr2[j]] = j;
        }
    }
    return ans;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 2, 1};
    vector<int> arr2 = {3, 2, 2, 3, 3, 2};

    // Input: a[] = [1, 2, 3, 2, 1], b[] = [3, 2, 2, 3, 3, 2]
    // Output: [1, 2, 3] 
    vector<int> ans = unionArray(arr1, arr2, arr1.size(), arr2.size());
    
    cout << "The union of the given arrays is: " ;
    for(int el: ans) cout << el << ' ';

    return 0;
}