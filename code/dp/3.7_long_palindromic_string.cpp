
// first way to calculate longest palindromic string O(n^2) RECURSIVE + MEMO

// [l,r] denotes the range of s in consideration
int solve(vector<vector<int> > &dp, int l, int r, string &s){
    if(l == r) return 1; // if both are same, length s = 1 so count = 1 
    if(l > r) return 0; // invalid index count = 0
    if(dp[l][r] != -1) return dp[l][r];
    if(s[l] == s[r]){
        return dp[l][r] = 2 + solve(dp, l+1, r-1, s); // we inc by 2 as s[l] and s[r] both included
    }
    else{
        return dp[l][r] = max(solve(dp, l+1, r,s), solve(dp, l, r-1, s)); // similar to lcs basically check in either l+1, r or l, r-1 range
    }
}
int longestPalindromeSubseq(string s) {
    int n = s.size();
    // int dp[n+1][n+1];
    // memset(dp, 0, sizeof(dp));
    vector<vector<int> >dp (n+1, vector<int> (n+1, -1));
    return solve(dp, 0, s.size()-1, s);
}

// same way but uses tabulation : simply convert rec to tabulation

// THIS IS THE WRONG WAY TO DO TABULATION
int longestPalindromeSubseq(string s) {
    int n = s.size();
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    // notice how it is  i+1, and j-1 
    // this gives an idea tha loop for i should start from n-1 and for j = 0
    // so i+1, j-1 would already be calc when calc dp[i][j]
    // all the base cases handled within the loop
    for(int i = 0; i < n ;i++){
        for(int j = n-1; j >= 0 ; j--){
            if(i == j) dp[i][j] = 1; // 1st base case
            else if( i > j) dp[i][j] = 0; // next base case 
            else if(s[i] == s[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            }else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }   
        }
    }
    return dp[0][s.size()-1]; 
}

// RIGHT WAY TO DO TABULATION l = i, r = j 
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
    // when we call the memo function solve(0, s.size()-1) so here also we do the samne thing dp[0][s.size()-1]
    return dp[0][s.size()-1];
}


// WHO IS THIS RELATED TO LCS? 
// basically lcs of s and reverse of s == longest palindromic subsequence.

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
