// memo top down appraoch
int solve(vector< unordered_map<int,int> > &dp, int n, int target, vector<int>& nums){
        if(n == 0) return target == 0; // same base case as 1.3
        // if(target < 0) return 0; // here target could also go below 0 but can come back to 0 again so
        if(dp[n].count(target)) return dp[n][target];
        return dp[n][target] = solve(dp, n-1, target-nums[n-1], nums) + solve(dp, n-1, target+nums[n-1], nums);        
    }
int findTargetSumWays(vector<int>& nums, int target) {
    // this cant be used here target could go below 0 so we cannot store in vector
    // vector< vector<int> > dp(nums.size()+1, vector<int> (10000+1, -1));
    vector<unordered_map<int,int> > dp(nums.size()+1); 
    return solve(dp, nums.size(), target, nums);
}


// another way : this question is the exact same copy of 1.5 but is formatted diff.
// both of them would return the same thing.