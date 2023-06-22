// o(n*sum) uses stuff from partion question and is subset sum question.
/*
Given an array arr of size n containing non-negative integers, the task is to divide it into two sets S1
and S2 such that the absolute difference between their sums is minimum and find the minimum difference

*/
int minDifference(int arr[], int n)  { 
	    long long sum = 0;
        for(int i = 0; i < n ; i++){
            sum += arr[i];    
        }
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
	               dp[i][j] = dp[i-1][j-arr[i-1]]|| dp[i-1][j];
	               
	           }else{
	               dp[i][j] = dp[i-1][j];
 	           }
	        }
	        
	    }
        // tabulation can be used here as it calculates all teh dp[n][sum]
        // if we loop dp[n][i = 0 to sum] we can find which all sums's are possible, after getting this we minimize the sum diff btw s1 and s2      
	    long long res = INT_MAX;
	    for(int i = 0 ; i <= sum ; i++){
	        if(dp[n][i] == 1){
	            res = min(1LL*res, abs(sum - 2 * i));
	        }
	    }
	    return res;
	} 

    