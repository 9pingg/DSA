
// generally dont use 2darrays instead use vectors
// in teh brute force appraoch we try to form every subset and check if that subset is max or no.
// As we considering all the testcases and so there will be 2^n  subsets . So time complexity will be O(2^n) .
// Space complexity : As we not storing any values and auxiliary stack space is O(n) for recursion stack .

// better approach : temporary array  dp[][] . We can construct the array in top down . 
/* 
Time complexity :  As we looping through an array of size (N*W) . The time complexity will be O(N*W) .
Space complexity :  As we keeping an array of (N*W) .  The space complexity is O(N*W) .
*/

int solve(vector<vector<int> > &dp, int w, int *wt, int *val, int n){
        if(n == 0 || w == 0){
            return 0;
        }   
        if(dp[n][w] != -1) return dp[n][w];
        
        if(w >= wt[n-1]){
            return dp[n][w] = max(val[n-1] + solve(dp, w-wt[n-1],wt, val, n), solve(dp, w, wt, val, n-1));
        }else{
            return dp[n][w] = solve(dp, w, wt, val, n-1);    
        }
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        vector<vector<int> > dp (n+1, vector<int> (w+1, -1));
        return solve(dp, w, wt, val, n);
       // Your code here
    }


// bottom up tabulation appraoch : 
/* 
Time complexity :  As we looping through an array of size (N*W) . The time complexity will be O(N*W) .
Space complexity :  As we keeping an array of (N*W) .  The space complexity is O(N*W) .
*/

int knapSack(int w, int wt[], int val[], int n) 
    { 
    vector<vector<int> > dp (n+1, vector<int> (w+1, 0));
    for(int i = 0; i <= n ; i++){
        for(int j = 0 ; j <= w ; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0; // initialize    
            }
        }
    }
    
    for(int i = 1; i <= n ; i++){ // i = n, j = w
                                    
        for(int j = 1 ; j <= w ; j++){
            if(j >= wt[i-1]){
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]); // notice how it remains dp[i] when an item is choosen, it can again be choosen.
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
        
    }
        
    
    return dp[n][w];
}

