// Memoizing the Solution

bool canSum(int target, vector<int>& nums, map<int, bool>& memo){
    if(target == 0) return true;
    
    if(target < 0) return false;
    
    if(memo.find(target) != memo.end()) return memo[target];
    
    for(auto it:nums){
        int rem = target - it;
        if(canSum(rem, nums, memo)){
            memo[target] = true;
            return memo[target];
        };
    }
    memo[target] = false;
    return false;
}

// Here, the problem is broken down by subtracting the target with the numbers from the array as long as the target is > 0.
// If target eventually becomes 0, the path it takes to become 0 is the sum to form the target.
