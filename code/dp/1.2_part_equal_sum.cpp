// same ques as subset sum with slight modification

/*
Given an array arr[] of size N, check if it can be partitioned into two parts 
such that the sum of elements in both parts is the same.
*/

//top down approach o(n*sum)
int solve(vector<vector<int> > &dp, int *arr, int n, int sum){
    if(sum == 0) return true;
    if(n == 0) return false; 
    if(dp[n][sum] != -1) return dp[n][sum];
    if(sum >= arr[n-1])
        return dp[n][sum] = solve(dp, arr, n-1,sum-arr[n-1]) || solve(dp, arr, n-1, sum);
    else{
        return dp[n][sum] = solve(dp, arr, n-1, sum);
    }
    
}   
int equalPartition(int N, int arr[])
{
    long long sum = 0;
    for(int i = 0; i < N ; i++){
        sum += arr[i];    
    }
    // IMP condition. notice if two partitions exists who have same sum S, then total_sum = 2*S .. so it is even  
    // must put it here, it converts complexity from O(n*sum) to O(n) for many cases.
    if(sum % 2 != 0) return 0;
    
    // now we need to find a subset whose sum is S = total_sum / 2. if we find such subset the remaining elements would also sum to s
    vector<vector<int> > dp(N+1, vector<int> (sum+1, -1)); 
    return solve(dp, arr, N, sum/2);
}

int equalPartition(int N, int arr[])
    {
        long long sum = 0;
        for(int i = 0; i < N ; i++){
            sum += arr[i];    
        }
        // IMP condition. notice if two partitions exists who have same sum S, then total_sum = 2*S .. so it is even  
        // must put it here, it converts complexity from O(n*sum) to O(n) for many cases.
        if(sum % 2 != 0) return 0;
        
        // now we need to find a subset whose sum is S = total_sum / 2
        vector<vector<int> > dp(N+1, vector<int> (sum+1, -1));
        
        // we need to find sum/2 = S (NOTE IMP)
        sum = sum/2;
        int n = N;
        
        for(int i = 0 ; i <= n ; i++){
            for(int j = 0 ; j<= sum ; j++){
                if(j == 0){ // if sum == 0, then return true
                    dp[i][j] = 1;
                }
                else if(i == 0){ // if num == 0 return false no elements
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j<= sum ; j++){
                if(arr[i-1] <= j){
                    dp[i][j] = max(dp[i-1][j-arr[i-1]], dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
            
        return dp[n][sum];
        
}