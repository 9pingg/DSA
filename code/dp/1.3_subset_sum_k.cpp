int solve_non_neg_values(vector< vector<int> > &dp, int *arr, int n, int sum){
    // this only works when arr only has non neg integers (so no 0)
    // if inp is (0,1,2) and sum = 0 it will always return 1 but the ans should be 2 because ({}, {0}) so sum == 0 condition doesnt work
    if(sum == 0) return 1; // if n == 0, and sum == 0 so what should we return (true, because {} is a set whose sum is eq to 0)
    else if(n<=0) return 0;
    
    if(dp[n][sum]!= -1) return dp[n][sum];
    if(sum >= arr[n-1])  return dp[n][sum] = solve(dp, arr, n-1,sum-arr[n-1]) + solve(dp, arr, n-1, sum);
    else{
        return dp[n][sum] = solve(dp, arr, n-1, sum);
    }
}
// used in q 1.5 
int tabulation_non_neg_values(int *arr, int n, int sum){
    vector<vector<int> > dp(n+1, vector<int> (sum+1, 0)); 
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= sum ; j++){
            if(j == 0){
                dp[i][j] = 1;
            }
            else if(n == 0){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= sum ; j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }   
    }

}

// implementing for both 0 and non neg values
int solve(vector< vector<int> > &dp, int *arr, int n, int sum){
    // imp statement 
    if(n == 0) return sum == 0;     
    if(dp[n][sum]!= -1) return dp[n][sum];
    if(sum >= arr[n-1])  return dp[n][sum] = (solve(dp, arr, n-1,sum-arr[n-1])% 1000000007  + solve(dp, arr, n-1, sum)% 1000000007)% 1000000007;
    else{
        return dp[n][sum] = solve(dp, arr, n-1, sum)%1000000007;
    }
}

int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    vector< vector<int> > dp(n+1, vector<int> (sum+1, -1));
    
    return solve(dp, arr, n, sum);
    
}

// No tabulation for this as the initialization part has to be read again.

// note the base case was if(n == 0) return target == 0
// now lets move to the table: in the initialiazation if we go by base case there is no need to initializer  sum==0 n
// bc phelae if we ini sum == 0 wala coloumn jisme n random hae it doesnt work for {0,1,2}.

// we only need to ini when  for values of sum and n == 0
// only ini values which we are sure of 

int subsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    int tab[n + 1][sum + 1];
  // Initializing the first value of matrix
    tab[0][0] = 1; // n = 0 , sum = 0
    for (int i = 1; i <= sum; i++) // if n is 0 and sum is not then return 0
        tab[0][i] = 0;
     
   
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
          // if the value is greater than the sum
            if (a[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
            else
            {
                tab[i][j] = tab[i - 1][j] + tab[i - 1][j - a[i - 1]];
            }
        }
    }
 
 
    return tab[n][sum];
}