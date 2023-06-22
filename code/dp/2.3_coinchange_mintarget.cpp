
/*
You are given an integer array coins representing coins of different denominations 
and an integer amount representing a total amount of money. Return the fewest number 
of coins that you need to make up that amount. If that amount of money cannot be made 
up by any combination of the coins, return -1.
*/

long long solve(vector<vector<long long> > &dp, int n, int amount, vector<int>& coins){
        if(amount == 0) return 0;
        if(n == 0) return INT_MAX;
        if(dp[n][amount]!=INT_MAX) return dp[n][amount];
        if(amount >= coins[n-1]){
            return dp[n][amount] = min(1 + solve(dp, n, amount-coins[n-1], coins), solve(dp, n-1, amount, coins)) ;
        }else{
            return dp[n][amount] = solve(dp, n-1, amount, coins);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long long> > dp(n+1, vector<long long> (amount+1, INT_MAX));
        int res = solve(dp, n, amount, coins);
        return res == INT_MAX? -1 : res;
    }