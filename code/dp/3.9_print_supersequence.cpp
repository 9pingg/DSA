
// two ways to do this: 

//1) find lcs string, then itr both the strings s1 and s2 together
// if s1[i] != lcs[pos] && s2[j] != lcs[pos] then add them to result, if eq then inc pos
// better understood by seeing the code
// time O(MN + LCS_gen(max(m,n)) + SSC_gen(max(m,n))) dp, space O(MN) * O(string), but actually we can also save the storage of string.

// 2) using the table after we are done with lcs, this table was also used to print lcs, here with some changes it can 
// print supersequence.

string printLCS(string text1, string text2){
    int s1 = text1.size();
    int s2 = text2.size();
    vector<vector<int> > dp(s1+1, vector<int> (s2+1, -1));
    for(int i = 0 ; i <= s1 ; i++){
        dp[i][0] = 0;
    }
    for(int i = 0 ; i <= s2 ; i++){
        dp[0][i] = 0;
    }
    
    for(int i = 1 ; i <= s1 ;i++){
        for(int j =1; j <= s2;j++){
            if(text1[i-1] == text2[j-1]){ 
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string lcs = "";
    int i = s1;
    int j = s2;
    // getting the lcs string O(max(m,n))
    while(i > 0 && j > 0){
        if(text1[i-1] == text2[j-1]){
            lcs += text1[i-1];
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
string shortestCommonSupersequence(string s1, string s2) {
    string lcs = printLCS(s1,s2);    
    cout << lcs;

    string res = "";
    int i = 0;
    int j = 0;
    int pos = 0;
    int n = s1.size();
    int m = s2.size();
    // getting the scs string O(max(m,n))
    // not easy to understand, changed
    // while(i < n && j < m && pos < lcs.size()){
    //     if(lcs[pos] == s1[i]){
    //         while(lcs[pos] != s2[j]){
    //             res += s2[j];
    //             j++;
    //         }
    //         i++;
    //         j++;
    //         res += lcs[pos++];
    //     }
    //     else if(lcs[pos] == s2[j]){
    //         while(lcs[pos] != s1[i]){
    //             res += s1[i];
    //             i++;
    //         }
    //         i++;
    //         j++;
    //         res += lcs[pos++];
    //     }else{
    //         res += s1[i++];
    //         res += s2[j++];
    //     }
    // }
    // if(i != n){
    //     while(i < n){
    //         res += s1[i++];
    //     }
    // }
    // if(j!=m){
    //     while(j < m){
    //         res += s2[j++];
    //     }
    // }
    for(char c : lcs){
        while(s1[i] != c){
            res += s1[i++];
        }
        while(s2[j] != c){
            res += s2[j++];
        }
        res += c;
        // s1[i] and s2[j] are eq to c now
        i++; 
        j++;
    }
    // add rest of the charaters left
    if(i != n){
            while(i < n){
                res += s1[i++];
            }
        }
    if(j!=m){
        while(j < m){
            res += s2[j++];
        }
    }
    return res; 
}

// way 2

