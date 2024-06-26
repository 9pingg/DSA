int dp[101][101];
int solve(int i, int j){
    if(i < 0 || j < 0) return 0;
    if(i == 0 and j == 0) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = solve(i-1, j) + solve(i, j-1);
}
int uniquePaths(int m, int n) {
    memset(dp, -1, sizeof(dp));
    return solve(m-1,n-1);
}