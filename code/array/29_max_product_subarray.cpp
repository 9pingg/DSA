// brute force aproach generate all subarrays O(n^2) gives tle on leetcode
// note : to gen all subsequences we need o(2^n) complexity but for subarray it is o(n^2)
int maxProduct(vector<int>& nums) {
    int ans = INT_MIN;
    int pro = 1;
    for(int i = 0 ; i < nums.size() ; i++){
        for(int j = i; j < nums.size() ; j++){
            pro *= nums[j];
            ans = max(ans, pro);
        }
        pro = 1;
    }
    return ans;
}

// O(N)
// calc prefix and suffix at every point either one of the values would have the highest product possible
// when one of them is eq to 0, reset them to 1. 0's break the arr into subarrays [1 2 3 4 5] 0 [4 2 5 9 9] 0 [9 8 9 1]
int maxProduct(vector<int>& nums) {
    // two cases: even cnt of neg vals or odd cnt
    int prefix = 1;
    int suffix = 1;
    int ans = INT_MIN;
    int n = nums.size();
    for(int i = 0 ; i < nums.size() ; i++){
        // if somehow prefix becomes 0, whihch means nums has a zero, 
        // so we start with prefix agian with 1, 0 breaks teh arr into subarrays
        if(prefix == 0){
            prefix = 1;
        }
        if(suffix == 0){
            suffix = 1;
        }
        prefix *= nums[i];
        suffix *= nums[n-1-i];
        ans = max(ans,max(prefix, suffix));
    }
    return ans;
}