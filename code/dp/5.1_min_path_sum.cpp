// instead of moving from top to bottom, changed the code to move form bottom to top 
// so rec is easier to read
// o(n*m)
long long dp[205][205];
long long solve(int i, int j, vector<vector<int>>& grid){
    if(i == 0 and j == 0) return grid[0][0];
    if(i < 0 || j < 0) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = (long long)grid[i][j] + min(solve(i-1, j, grid), solve(i, j-1, grid));
}
// up j-1 and left i-1
int minPathSum(vector<vector<int>>& grid) {

    int m = grid.size();
    int n = grid[0].size();
    memset(dp, -1, sizeof(dp));
    return solve(m-1, n-1, grid);
}

// tabulation of the same code, initialization could be done better
int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else if(i == 0) dp[i][j] = grid[i][j] + dp[i][j-1];
                else if(j == 0) dp[i][j] = grid[i][j] + dp[i-1][j];
                else{
                    dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m-1][n-1];
    }