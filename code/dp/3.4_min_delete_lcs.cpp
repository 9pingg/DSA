class Solution {
public:
    int lcs(string s1, string s2, int n, int m){
        vector<vector<int> > dp(s1.size()+1, vector<int> (s2.size()+1, -1));
        for(int i = 0 ; i<= n ; i++){dp[i][0] = 0;}
        for(int i = 0 ; i<= m ; i++){dp[0][i] = 0;}
        
        for(int i = 1; i<= n ;i++){
            for(int j = 1 ; j <= m ; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string s1, string s2) {
        //  find lcs
        int n = s1.size();
        int m = s2.size();
        int len = lcs(s1, s2, n, m);
        return (m+n-2*len);
    }
};