// kadane algo  == MAXIMUM SUBARRAY SUM


// BRUTE FORCE APPROACH check all subarrays for max sum O(N^2)

long long maxSubarraySum(int a[], int n)
{
    long long res = 0;
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
      for (int j = i; j < n;j++) {
          sum += a[j];
          res = max(res, sum);
      }
      sum = 0;
    }
    return res;

}

// better approach O(N) no extra space
// also known as kadane algo
// notice the similarity btw find subarray len max whose sum is eq to K (only positive values) two pointer wala method
int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int max_sum = INT_MIN; // initialize to int_min as nums has neg values
    for(auto val : nums){
        sum += val; // inc the sum
        max_sum = max(max_sum, sum); // update max
        if(sum < 0) sum = 0; // if sum < 0 then drop it 
    }
    return max_sum;
 }


// Within this can we add l, r such that it gives the range of the subbarray.

int maxSubArray(vector<int>& nums) {
    int sum = 0;
    int max_sum = INT_MIN; // initialize to int_min as nums has neg values
    int l,r;
    for(int i = 0 ; i < nums.size() ; i++){
      if(sum == 0){ // starting a new subarray 
                    // now where do we end this and find r, we update r when we have sum greater than max_sum
        l = i;
      }
      sum += val; // inc the sum
      max_sum = max(max_sum, sum); // update max
      if(max_sum == sum){  // new r
        r = i;
      }
      if(sum < 0) sum = 0; // if sum < 0 then drop it 
    }

    // after loop we would l, r, max_sum
    return max_sum;
 }