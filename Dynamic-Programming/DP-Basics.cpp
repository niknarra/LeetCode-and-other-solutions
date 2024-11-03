// Memoization Examples

#include <bits/stdc++.h>
using namespace std;

// Example 1 - Fibonacci Sequence

// With Memoization
int memoFib(int n, map<int, int>&memo){
    if(n<2) return n;
    
    if (memo.find(n) != memo.end()) return memo[n];
    
    memo[n] = memoFib(n-1, memo) + memoFib(n-2, memo);
    
    return memo[n];
}

// Or, in this specific case as we know the indexes, we can use a vector,
int memoFib(int n, vector<int>&memo){
    if(n<2) return n;
    
    if (memo[n] != -1) return memo[n];
    
    memo[n] = memoFib(n-1, memo) + memoFib(n-2, memo);
    
    return memo[n];
}

// Original Recursion approach
int fib(int n){
    if(n<2) return n;
    
    return fib(n-1) + fib(n-2);
}
// This takes O(2^n) which is not optimal.


int main() {
    // Write C++ code here
    cout << "Dynamic Programming"<<endl;
    int n = 7;   

    map<int, int> mpp;
    vector<int> memo(n+1, -1); // Initialize a memo vector with -1s of size n

    cout<<memoFib(7,mpp);
    // cout<<fib(7);
    // cout<<fib(8);

    return 0;
}



