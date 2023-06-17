// Longest Subarray with sum K (subarray is contigous part of an array it is diff from subsequence, which is not contiguos but maintains the same order as org array)

// brute force approach O(N^2) doesnt work for neg values but works for 0 and pos values.
int lenOfLongSubarr(int a[],  int N, int K) 
    { 
        // Complete the function
        // form all possible subarrays and check if the sum is eq to K and then check their length
        //
        int sum = 0;
        int len = 0; // result max length
        for(int i = 0 ; i < N; i++){
            for(int j = i ; j < N; j++){
                sum += a[j]; // i = 0, j = 0 first sub array 
                if(sum == K){
                    len = max(len, j-i+1);
                    // cout << i << " " << j << " " << len << endl;
                }
            }
            sum = 0;
        }
        return len;
    } 

// O(N) and space O(N), using hashmap if we are at sum x, we need to find a point in array with sum x-k so that from that point sum is eq to k.
// works for pos neg and 0 values // BEST SOLUTION IF ALL POS AND NEG BOTH
int longestSubarrayWithSumK(vector<int> a, long long K) {
   unordered_map<long long,int> mp;
        int len = 0;
        int N = a.size();
        // mp[sum] = index at which it was achieved
        long long prefix_sum = 0;
        for(int i = 0 ; i < N; i++){
            prefix_sum += a[i];
            if(prefix_sum == K) len = max(len, i+1);
            //WHY DO U ONLY UPDATE WHEN we dont have prefix sum lets suppose we update prefix sum at pos 0, 
            //and then have the same value of prefix sum so here we will update the value written at pos 0, this 
            //would dec the length of subarray as it increases the index position.
            if(!mp.count(prefix_sum)) mp[prefix_sum] = i; // store prefix sum and index, only if it doesnt exist VERY IMP IF INPUT HAS 0 VAL
            auto it = mp.find(prefix_sum - K); // find p_sum such that p_sum_now - p_sum = K
            if(it!=mp.end()){
                // cout << i << " " << (*it).second << endl;
                len = max(len, i - (*it).second); // len =  // it.second element is not included in the subarray
            }
        }
        return len;
}

// only works for pos values O(2*N) and O(1)

int longestSubarrayWithSumK(vector<int> a, long long K) {
   int len = 0;
   long long p_sum = 0;
   int j = 0; // two pointer approach
   for(int i = 0 ; i < a.size() ; i++){
        p_sum += a[i];
        if(a[i] == K) len = max(len, 1);
        while(p_sum > K && j <= i){ // this updates the psum value so should be put before the p_sum == k thing or error comes
            p_sum = p_sum - a[j]; // when p_sum > k we move j such that psum <= k
            j++;
        }
        if(p_sum == K) len = max(len, i-j+1);
   }
   return len;
}