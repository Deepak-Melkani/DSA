//       1        (Row 1)
//      1 1       (Row 2)  ==> PASCAL TRIANGLE (nth row contains n elements)
//     1 2 1      (Row 3)
//    1 3 3 1     (Row 4)

// Variation 1: Given row r and column c, find the element at that position => sol : Find r-1 C c-1 which means nCr(r-1, c-1)
// Variation 2: Given row r and column c, find the complete row's values
// Variation 3: Given the number of rows, find the complete pascal's triangle

#include<bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    int res = 1;
    for(int i=0; i<r; i++) {
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}
 
vector<int> generateRow(int row) {
    vector<int> ans;
    long long res = 1;
    ans.push_back(res);
    for(int col=1; col<row; col++) {
        res *= (row-col);
        res /= col;
        ans.push_back(res);
    }
    return ans;
}

int main() {
    cout << "The element in 4th row at 3rd position is: " << nCr(3,2) << endl; // Variation 1

    cout << "The 4th row is: "; // Variation 2
    vector<int> ans = generateRow(4);
    for(int el: ans) cout << el << ' ';

    cout << "The pascal triangle with 10 rows is: " << endl; // Variation 3
    int rows = 10 ;
    vector<vector<int>> pascal;
    for(int i=1; i<=rows; i++) {
        pascal.push_back(generateRow(i));
    }
    int spaces = rows - 1;
    for(int i=0; i<rows; i++) {
        int k = spaces;
        while(k--) cout << ' ';
        for(int j=0; j<pascal[i].size(); j++) cout << pascal[i][j] << ' ';
        cout << endl;
        spaces--;
    }

    return 0;
}