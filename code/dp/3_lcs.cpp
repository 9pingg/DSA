// recursion + memo
int solve(vector<vector<int> > &dp, string &text1, string &text2, int s1, int s2){
        if(s1 == 0) return 0; // if text1 = "", then there is no char common in both, so return 0
        if(s2 == 0) return 0; // if text2 = "", then there is no char common in both, so return 0
        if(dp[s1][s2] != -1) return dp[s1][s2];
        if(text1[s1-1] == text2[s2-1]){ // both equal
            return dp[s1][s2] = 1 + solve(dp, text1, text2, s1-1, s2-1);
        }else{ 
            return dp[s1][s2] = max(solve(dp, text1, text2, s1-1, s2), solve(dp, text1, text2, s1, s2-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> > dp(text1.size()+1, vector<int> (text2.size()+1, -1));
        return solve(dp, text1, text2, text1.size(), text2.size());
    }




//tabulation
int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();
        vector<vector<int> > dp(s1+1, vector<int> (s2+1, -1));
        // initialization
        for(int i = 0 ; i <= s1 ; i++){
            dp[i][0] = 0;
        }
        for(int i = 0 ; i <= s2 ; i++){
            dp[0][i] = 0;
        }
        // choice
        for(int i = 1 ; i <= s1 ;i++){
            for(int j =1; j <= s2;j++){
                if(text1[i-1] == text2[j-1]){ 
                    dp[i][j] = 1 + dp[i-1][j-1]; // if both are eq we move ahead both the strings
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[s1][s2];
}