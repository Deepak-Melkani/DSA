// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

#include<bits/stdc++.h>
using namespace std;

void setRow(vector<vector<int>>& matrix, int row) {
    int n = matrix[0].size();
    for(int i=0; i<n; i++) {
        matrix[row][i] = -1;
    }
}

void setCol(vector<vector<int>>& matrix, int col) {
    int n = matrix.size();
    for(int i=0; i<n; i++) {
        matrix[i][col] = -1;
    }
}

void setMatrixZero(vector<vector<int>>& matrix, int n, int m) { // Brute Force
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] != 0) {
                setRow(matrix, i);
                setCol(matrix, j);
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] == -1) matrix[i][j] = 0;
        }
    }
}

void setMatrixZero1(vector<vector<int>>& matrix, int n, int m) { // Better 
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(row[i] || row[j]) matrix[i][j] = 0;
        }
    }
}

void setMatrixZero2(vector<vector<int>>& matrix, int n, int m) {    // Optimal
    int col0 = 1;   // Using 0th row and 0th col instead of maintaining seperate arrays
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;

                if(j != 0) matrix[0][j] = 0;
                else col0 = 0;
            }
        }
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(matrix[i][j] != 0) {
                if(matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0] == 0) {
        for(int j=0; j<m; j++) matrix[0][j] = 0;
    }

    if(col0 == 0) {
        for(int i=0; i<n; i++) matrix[i][0] = 0;
    }
}

int main() {
    vector<vector<int>> matrix = {{1,1,1}, {1,0,1}, {1,1,1}};
    int n = matrix.size();
    int m = matrix[0].size();
    // Input: matrix = [[1,1,1],
    //                  [1,0,1],
    //                  [1,1,1]]

    // Output: [[1,0,1],
    //          [0,0,0],
    //          [1,0,1]]
    setMatrixZero2(matrix, n, m);
    cout << "The matrix after modifications is: " << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
}