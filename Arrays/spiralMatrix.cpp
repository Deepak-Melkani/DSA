#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& matrix, int n, int m) {
    int strow = 0;
    int stcol = 0;
    int endrow = n-1;
    int endcol = m-1;
    int cnt = 0;
    int total = n * m;
    vector<int> ans;

    while(cnt < total) {
        for(int j=stcol; j<=endcol && cnt < total; j++) {
            ans.push_back(matrix[strow][j]);
            cnt++;
        }
        strow++;

        for(int i=strow; i<=endrow && cnt < total; i++) {
            ans.push_back(matrix[i][endcol]);
            cnt++;
        }
        endcol--;

        for(int j=endcol; j>=stcol && cnt < total; j--) {
            ans.push_back(matrix[endrow][j]);
            cnt++;
        }
        endrow--;

        for(int i=endrow; i>=strow && cnt < total; i--) {
            ans.push_back(matrix[i][stcol]);
            cnt++;
        }
        stcol++;
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix1 = {{1,2,3}, {4,5,6}, {7,8,9}}; // Output: [1,2,3,6,9,8,7,4,5]
    vector<vector<int>> matrix2 = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}}; // Output: [1,2,3,4,8,12,11,10,9,5,6,7]

    vector<int> ans1 = spiralMatrix(matrix1, matrix1.size(), matrix1[0].size());
    vector<int> ans2 = spiralMatrix(matrix2, matrix2.size(), matrix2[0].size());

    cout << "The spiral form of matrix1 is: ";
    for(int el: ans1) cout << el << ' ';
    cout << endl;

    cout << "The spiral form of matrix1 is: ";
    for(int el: ans2) cout << el << ' ';
    cout << endl;

    return 0;
}