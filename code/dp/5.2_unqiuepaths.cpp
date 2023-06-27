
// o(n*m) almost same as 5.1 ques tabulation would be similar to.

class Solution {
public:
    int dp[105][105];
    int solve(int i, int j){
        if(i == 0 and j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(i-1, j) + solve(i, j-1);
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(m-1, n-1);
    }
};