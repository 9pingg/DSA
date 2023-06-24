
// now a substring is diff than a subsequence : substring is continuous and subsequence can have gaps

// x: abcd y: abed 
// lcsubsequnce : abd 
// lcsubstring : ab 


// recursion : notice there are 3 changing variables n1, n2 and count is there is no point in memorizing this, so we move to tabulation method
int max_count = 0;
    void solve(int n1, int n2, int count, string s1, string s2){
        if(n1 == 0 || n2 == 0) return;
        if(s1[n1-1] == s2[n2-1]) {
            count++;
            max_count = max(count, max_count);
            solve(n1-1, n2-1, count, s1, s2);
        }else{
            count = 0;
            max_count = max(count, max_count);
            solve(n1-1, n2, count, s1, s2);
            solve(n1, n2-1, count, s1, s2);
        }
    } 

// more readable rec approach : has 3 state variables requires dp[][][] for memo 
// notice the similarity with longest common subsequence
int solve(int n1, int n2, int count, string s1, string s2){
        if(n1 == 0 || n2 == 0) return count;
        if(s1[n1-1] == s2[n2-1]) {
            
            return solve(n1-1, n2-1, count+1, s1, s2);
        }else{
            return max(count, max(solve(n1-1, n2, 0, s1, s2), solve(n1, n2-1, 0, s1, s2)));
        }
    } 
int longestCommonSubstr (string S1, string S2, int n, int m)
{
    return solve(n, m, 0, S1, S2);
}
int longestCommonSubstr (string S1, string S2, int n, int m)
{
solve(n, m, 0, S1, S2);
    return max_count;
}


// tabulation method


int longestCommonSubstr (string S1, string S2, int n, int m)
{
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    // if s2 = ""
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = 0;   
    }
    // if s1 = ""
    for(int i = 0 ; i <= m ; i++){
        dp[0][i] = 0;   
    }
    
    int maxlen = 0;
    for(int i = 1; i <= n ;i++){
        for(int j = 1; j <= m ; j++){
            if(S1[i-1] == S2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxlen = max(maxlen, dp[i][j]);
            }
            else{ 
                dp[i][j] = 0;
            }
        }
    }
    return maxlen;
    //return dp[n][m]; // this doesnt have the maximum lcsubstring value
}