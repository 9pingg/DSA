// many ways to solve this : rec, tabulation of same, lcs(s,t).size() == s.size(), simple looping string

// recursion: here notice the choice diagram is different than lcs case we do not itr string s in else case

int solve(string &s, string &t, int n, int m){
    if(n == 0) return 1; // if s = "", then obv it is a subsequence of t
    if(m == 0) return 0; // if s has some length and m = "" then t doesnt have s as subsequence
    if(s[n-1] == t[m-1]){
        return solve(s, t, n-1, m-1);
    }else{
        return solve(s, t, n, m-1);
    }
}
bool isSubsequence(string s, string t) {
    return solve(s, t, s.size(), t.size());
}

// tabulation of the same rec O(n^2) with ini and choice diagram in same loop
bool isSubsequence(string s, string t) {
    int n = s.size();
    int m = t.size();
    if(s.size() > t.size()) return false;
    int dp[n+1][m+1];
    memset(dp, -1, sizeof(dp));
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0; j <= m ;j++){
            if(i == 0) dp[i][j] = 1;
            else if(j == 0) dp[i][j] = 0;
            else{
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[n][m];
}