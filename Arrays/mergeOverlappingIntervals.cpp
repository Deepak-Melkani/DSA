// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) { // Brute Force
    int n = intervals.size();
    vector<vector<int>> ans;

    sort(intervals.begin(), intervals.end());

    for(int i=0; i<n; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if(!ans.empty() && end <= ans.back()[1]) continue;

        for(int j=i+1; j<n; j++) {
            if(intervals[j][0] <= end) end = max(end, intervals[j][1]);
            else break;
        }

        ans.push_back({start, end});
    }

    return ans;
}

vector<vector<int>> merge2(vector<vector<int>>& intervals) { // Optimal
    int n = intervals.size();
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    
    ans.push_back(intervals.front());

    for(int i=1; i<n; i++) {
        if(intervals[i][0] <= ans.back()[1]) {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else ans.push_back(intervals[i]);
    }

    return ans;
}

int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}}; // Output: [[1,6],[8,10],[15,18]]
    vector<vector<int>> ans = merge2(intervals);

    cout << "The intervals after merging are: " << endl;
    for(auto v: ans) {
        for(int el: v) cout << el << ' ';
        cout << endl;
    }

    return 0;
}