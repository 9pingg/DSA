/*
basically an array is given we have give the count of how many such,  if we div the array into two partitions
which have sum s1 and s2, then the difference s1-s2 should be eq to target
*/

// the question has many similarities to 1.4, only the last loop is different
//NOTE: this only works for arrays with distinct values 
int count_diff_subsets(int arr[], int n, int target)  { 
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
	    long long count = 0;
	    for(int i = 0 ; i <= sum ; i++){
	        if(dp[n][i] == 1){
                if(abs(2*i - sum) == target){
                    count++;
                }
	        }
	    }
	    return count;
	}

// optimal : this works for duplicate elements as well.


int count_diff_subsets(int arr[], int n, int target)  { 
    long long sum = 0;
    for(int i = 0; i < n ; i++){
        sum += arr[i];    
    }
    vector<vector<int> > dp(n+1, vector<int> (sum+1, 0)); 
    
    // below dp code dp[i][j] returns the number of subsets which have sum j for length of arr = i
    // though this tabulation only works for non neg integers if it has zero then it doesnt work refer 1.3 for this
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
    long long count = 0;
    int target = 1;
    // why go from 0 to sum/2: because after sum/2 it counts the same sets twice
    // suppose s1 = 3 and s2 = 4, when i <= sum/2 but after i> sum/2 s1 = 4 and s2 = 3 so it counts the same thing twice
    // we could also return count/2 instead of looping from 0 to sum/2
    for(int i = 0 ; i <= (sum/2) ; i++){
        if(dp[n][i] != -1){
            
            if(abs(2*i - sum) == target){
                cout << i << " " << dp[n][i] << endl;
                count = count+dp[n][i];
            }
        }
    }
    return count;
	}