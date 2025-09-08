#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> ans;
    int i = 0;
    int j = 0;
    int m = a.size();
    int n = b.size();
    
    while(i < m && j < n) {
        if(a[i] == b[j]) {
            if(ans.empty() || ans.back() != a[i])
            ans.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i] < b[j]) {
            if(ans.empty() || ans.back() != a[i])
            ans.push_back(a[i]);
            i++;
        }
        else if(b[j] < a[i]) {
            if(ans.empty() || ans.back() != b[j])
            ans.push_back(b[j]);
            j++;
        }
    }
    
    while(i < m) {
        if(ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
        i++;
    }
    
    while(j < n) {
        if(ans.empty() || ans.back() != b[j]) ans.push_back(b[j]);
        j++;
    }
    
    return ans;
    
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3, 6, 7};

    vector<int> ans = findUnion(a, b);
    // Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
    // Output: [1, 2, 3, 4, 5, 6, 7]

    cout << "The union of the given arrays is: " ;
    for(int el: ans) cout << el << ' ';

    return 0;
}