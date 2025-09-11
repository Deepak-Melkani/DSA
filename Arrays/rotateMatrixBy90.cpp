// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>>& mat, int n, int m) { // Brute force
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            ans[j][n-1-i] = mat[i][j];
        }
    }
    return ans;
}

void rotateMatrix1(vector<vector<int>>& mat, int n, int m) { // Optimal (Modifying in-place O(1) space)
    for(int i=0; i<n-1; i++) { // Step1 : Transpose
        for(int j=i+1; j<n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for(int i=0; i<n; i++) {    // Step2 : Reverse each row
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    int n = matrix.size();
    int m = matrix[0].size();
    // Input: matrix = [[1,2,3],
    //                  [4,5,6],
    //                  [7,8,9]]

    // Output: [[7,4,1],
    //          [8,5,2],
    //          [9,6,3]]
    rotateMatrix1(matrix, n, m);
    cout << "The matrix is: " << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}