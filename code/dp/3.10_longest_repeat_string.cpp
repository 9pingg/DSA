/*
Given string str, find the length of the longest repeating subsequence such 
that it can be found twice in the given string.

The two identified subsequences A and B can use the same ith character from 
string str if and only if that ith character has different indices in A and B.
For example, A = "xax" and B = "xax" then the index of first "x" must be different 
in the original string for A and B.
*/

int LongestRepeatingSubsequence(string s1){
    int dp[s1.size()+1][s1.size()+1];
    memset(dp, -1, sizeof(dp));
    string s2 = s1;
    int n = s1.size();
    int m = s2.size();    
    
    for(int i = 0 ; i<= n ; i++){dp[i][0] = 0;}
    for(int i = 0 ; i<= m ; i++){dp[0][i] = 0;}
    
    for(int i = 1; i<= n ;i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1] && i != j){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];   
}

string printLongestRepeatingSubsequence(string s1){
    int dp[s1.size()+1][s1.size()+1];
    memset(dp, -1, sizeof(dp));
    string s2 = s1;
    int n = s1.size();
    int m = s2.size();    
    
    for(int i = 0 ; i<= n ; i++){dp[i][0] = 0;}
    for(int i = 0 ; i<= m ; i++){dp[0][i] = 0;}
    
    for(int i = 1; i<= n ;i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1] && i != j){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string lcs = "";
    int i = n;
    int j = m;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1] && i != j){
            lcs += s1[i-1];
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return lcs;
   
}