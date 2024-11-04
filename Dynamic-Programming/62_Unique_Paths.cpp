// Approach 1
// Memoization, TC: O(m*n); SC: O(n+m)

class Solution {
public:

    int pathFinder(int m, int n, map<pair<int, int>,int>& memo){
        if(m == 0 || n == 0) return 0; 

        if(m == 1 && n == 1) return 1;

        if(memo.find({m,n}) != memo.end()) return memo[{m,n}];

        memo[{m,n}] = pathFinder(m-1, n, memo) + pathFinder(m, n-1, memo);

        return memo[{m,n}];

    }

    int uniquePaths(int m, int n) {
        map<pair<int, int>,int> mpp;

        return pathFinder(m, n, mpp);

    }
};

// Or, we can slightly reduce the number of recursion frames by checking for n,m as m,n and n,m will have same paths, just inverted i.e., left and right paths swapped.

class Solution {
public:

    int pathFinder(int m, int n, map<pair<int, int>,int>& memo){
        if(m == 0 || n == 0) return 0; 

        if(m == 1 && n == 1) return 1;

        if(memo.find({m,n})!= memo.end()){
            return memo[{m,n}];
        }
        else if (memo.find({n,m}) != memo.end()){
            return memo[{n,m}];
        }

        memo[{m,n}] = pathFinder(m-1, n, memo) + pathFinder(m, n-1, memo);

        return memo[{m,n}];

    }

    int uniquePaths(int m, int n) {
        map<pair<int, int>,int> mpp;

        return pathFinder(m, n, mpp);

    }
};
