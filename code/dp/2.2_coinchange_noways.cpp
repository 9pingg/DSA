/*
Given an integer array coins[ ] of size N representing different
denominations of currency and an integer sum, find the number of
ways you can make sum by using different combinations from coins[ ].  
Note: Assume that you have an infinite supply of each type of coin.
 */

// seems similar to subset sum where we have to count subsets which on summing up are eq to k
// there are two  cases in the subset sum = k to question whether in the input array 0's are given or not.
// if not given then follow simple base case, if 0's given then follow adv base case.
// here we assume 0's inc in the array

// tabulation apr
long long int count(int coins[], int n, int sum) {
    
    vector<vector<long long> > dp(n+1, vector<long long> (sum+1, -1));

    // adv ini case
    dp[0][0] = 1;
    for(int i = 1 ; i <=  sum ; i++){
        dp[0][i] = 0; 
    }   
    // basic ini case

    // for(int i = 0 ; i <= n ;i++){
    //     for(int j = 0; j <= sum ; j++){
    //         if(j == 0){
    //             dp[i][j] = 1;        
    //         } else if(i == 0){
    //             dp[i][j] = 0;    
    //         }
    //     }
    // }
    
    for(int i = 1 ; i <= n ;i++){
        for(int j = 0; j <= sum ; j++){
            if(j >= coins[i-1]){
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];    
            }   
            else{
                dp[i][j] = dp[i-1][j] ;
            }
        }
    }
    return dp[n][sum];
    
}

