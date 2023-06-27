
// res = s.size()- LPS(s)

int lcs(string s1, string s2, int n, int m){
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n ;i++){
        for(int j = 1; j <= m ; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }   
        }
    }
    return dp[n][m];
}
int longestPalindromeSubseq(string s) {
    string s1 = s;
    reverse(s.begin(), s.end());
    return lcs(s1, s, s1.size(), s.size());
}
int findMinInsertions(string S){
    int a = longestPalindromeSubseq(S);
    return S.size()-a;
}