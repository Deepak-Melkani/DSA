// Given an unsorted array arr[] of size n, containing elements from the range 1 to n, it is known that one number in this range is missing, and another number occurs twice in the array, find both the duplicate number and the missing number.

// Input: arr[] = [2, 2]
// Output: [2, 1]
// Explanation: Repeating number is 2 and the missing number is 1.

// Input: arr[] = [4, 3, 6, 2, 1, 1]
// Output: [1, 5]
// Explanation: Repeating number is 1 and the missing number is 5.

#include<bits/stdc++.h>
using namespace std;

vector<int> findTwoElement(vector<int>& arr) { // Brute force
    int n = arr.size();
    vector<int> hash(n+1, 0);
    int rep = -1;
    int miss = -1;
    
    for(int el: arr) hash[el]++;
    
    for(int i=1; i<n+1; i++) {
        if(hash[i] == 2) rep = i;
        else if(hash[i] == 0) miss = i;
        if(rep != -1 and miss != -1) break;
    }
    
    return {rep, miss};
}

vector<int> findTwoElement2(vector<int>& arr) { // Optimal (using maths), The other optimal way uses the XOR 
    long long n = arr.size();
    
    long long SN = (n*(n+1))/2;
    long long S2N = (n*(n+1)*(2*n+1)) / 6;
    long long S = 0, S2 = 0;
    
    for(int i=0; i<n; i++) {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }
    
    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 /= val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    
    
    return {(int)x, int(y)};
}

int main() {
    vector<int> nums = {4, 3, 6, 2, 1, 1}; // Output: [1, 5]
    vector<int> ans = findTwoElement2(nums);

    cout << "The repeating number is: " << ans[0] << endl;
    cout << "The missing number is: " << ans[1];

    return 0;
}