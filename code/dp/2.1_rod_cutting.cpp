/*
Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. 
Determine the maximum value obtainable by cutting up the rod and selling the pieces.
*/
// in unbounded we can choose one item many times, so in func call when we choose item dont change n-1 
// notice no weight array is given, generally in 01 knapsack we were always given wt array but no value array.
// here we value array but no weight arr
// upon reading the question we can form the wt array 
// for eq: if n = 9 then wt = [1,2,3,4,5,6,7,8] or wt[n-1] = n

// top down approach
int solve(vector<vector<int>> &dp, int *price, int n, int w){
    if(n == 0) return 0;
    if(w == 0) return 0;
    if(dp[n][w] != -1) return dp[n][w];
    if(w >= n) return dp[n][w] = max(price[n-1] + solve(dp, price, n, w-n), solve(dp, price, n-1, w));        
    else return dp[n][w] = solve(dp, price, n-1, w);
}
int cutRod(int price[], int n) {
    //code here
    vector<vector<int> > dp(n+1, vector<int> (n+1, -1));
    return solve(dp, price, n, n);
}

// tabulation appraoch

int cutRod(int price[], int n) {
    //code here
    vector<vector<int> > dp(n+1, vector<int> (n+1, -1));
    
    // initilaization
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= n ; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
        }
    }
    
    
    for(int i = 1 ; i <= n ;i++){
        for(int j = 1; j <= n ; j++){
            if(j >= i){ // wt[i-1] == i
                dp[i][j] = max(price[i-1] + dp[i][j-i], dp[i-1][j]);    
            }   
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][n];
}