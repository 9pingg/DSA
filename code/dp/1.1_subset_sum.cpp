int dp[101][10001];
// O(n * sum)
int solve(vector<int> &arr, int target, int n){
    // there are two base conditions target = 0, and n = 0  both of them return diff values
    // which one would come first the target one or the n == 0 ? the target one
    if(target == 0){
        return 1;
    }
    if(n == 0 || target < 0){
        return 0;
    }
    if(dp[n][target] != -1) return dp[n][target];
    if(arr[n-1] <= target){
        return dp[n][target] = solve(arr, target-arr[n-1], n-1) || solve(arr, target, n-1); 
    }else{
        return dp[n][target] = solve(arr, target, n-1);   
    }
    return dp[n][target];
}
bool isSubsetSum(vector<int>arr, int sum){
    memset(dp, -1, sizeof(dp));
    int n = arr.size();
    solve(arr, sum, n);
    return dp[n][sum];    
}



// same thing in tabulation method bas convert karna recursive code ko dp mae
// if we have two changing variable n, and w aur woh knapsack mae change ho rahe asse knapsack(n-1, w-w[n-1]);
// toh isse we can write this in tabular form dp mae, dp[n-1][w-w[n-1]]


bool isSubsetSum(vector<int>arr, int sum){
    int n = arr.size();
    vector< vector<int> > dp(n+1, vector<int> (sum+1, 0));
    // initialization step
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j<= sum ; j++){
            if(j == 0){
                dp[i][j] = 1;
            }
            else if(i == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j<= sum ; j++){
            if(arr[i-1] <= j){
                dp[i][j] = max(dp[i-1][j-arr[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
        
    return dp[n][sum];
}