int longestPalindromeSubseq(string s) {
    int n = s.size();
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n ;i++){
        dp[i][i] = 1;
    }
    // notice how it is  i+1, and j-1 
    // this gives an idea tha loop for i should start from n-1 and for j = 0
    for(int i = n-1; i >= 0 ;i--){
        for(int j = 0; j < n ; j++){
            if(i == j) dp[i][j] = 1;
            else if( i > j) dp[i][j] = 0;
            else if(s[i] == s[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            }else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }   
        }
    }
//    /
    return dp[0][s.size()-1];
}
int minDeletions(string str, int n) { 
    int x = longestPalindromeSubseq(str);
    return n-x;
} 