// recursion + memo
// NOTE: this only prints 1 of the many lcs's. 

string solve(vector<vector<string> > &dp, string &text1, string &text2, int s1, int s2){
    if(s1 == 0) return ""; // if text1 = "", then there is no char common in both, so return ""
    if(s2 == 0) return ""; // if text2 = "", then there is no char common in both, so return ""
    if(dp[s1][s2].size() != 0) return dp[s1][s2];
    if(text1[s1-1] == text2[s2-1]){ // both equal
        return dp[s1][s2] = solve(dp, text1, text2, s1-1, s2-1) + text1[s1-1];
    }else{ 
        string a = solve(dp, text1, text2, s1-1, s2);
        string b = solve(dp, text1, text2, s1, s2-1);
        if(a.size() > b.size()) return dp[s1][s2] = a;
        else return dp[s1][s2] = b;
        
    }
}
string print_longest_common_subsequences(string s1, string s2)
{
    vector<vector<string> > dp(s1.size()+1, vector<string> (s2.size()+1));
    cout << solve(dp, s1, s2, s1.size(), s2.size()) << endl;        
}

// tabulation : note, this only prints 1 of the lcs
string longest_common_subsequences(string s1, string s2)
{
    vector<vector<string> > dp(s1.size()+1, vector<string> (s2.size()+1));

    int n = s1.size();
    int m = s2.size();    
    
    for(int i = 0 ; i<= n ; i++){dp[i][0] = "";}
    for(int i = 0 ; i<= m ; i++){dp[0][i] = "";}
    
    for(int i = 1; i<= n ;i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + s1[i-1];
            }else{
                string a = dp[i-1][j];
                string b = dp[i][j-1];
                if(a.size() > b.size()) dp[i][j] = a;
                else dp[i][j] = b;
            }
        }
    }
    return dp[n][m];
}

// any better way to get to result without saving the string in dp
// get the table after lcs(s1,s2,n,m) and itr through that table


string longest_common_subsequences(string s1, string s2)
{
    vector<vector<int> > dp(s1.size()+1, vector<int> (s2.size()+1, -1));

    int n = s1.size();
    int m = s2.size();    
    
    for(int i = 0 ; i<= n ; i++){dp[i][0] = 0;}
    for(int i = 0 ; i<= m ; i++){dp[0][i] = 0;}
    
    for(int i = 1; i<= n ;i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
               dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string res = "";
    // itr through the table
   int i = n;
    int j = m;
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){ // check if char at s1[n-1] and s2[m-1] are eq, if yes add in resultant string
            res += s1[i-1];
            i--;
            j--; // move diag
        }else{
            if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
            // move in the dir with higher dp[i][j]
        }
    }
    reverse(res.begin(), res.end());
    return res;
}