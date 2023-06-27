int dp[110][110];

// complexity o(n^3) with memo. for one rec, 2 calls are made n times in loop.
int solve(int *arr, int i, int j){
    if(i>= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    long long ans = (long long)1e18; 
    for(int k = i ; k < j ; k++){
        long long temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1] * arr[j] * arr[k];
        ans = min(temp ,ans);
    }
    return dp[i][j] = (int)ans;
}
int matrixMultiplication(int N, int arr[])
{
    memset(dp, -1, sizeof(dp));
    return solve(arr, 1, N-1);
}