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