#include <bits/stdc++.h>
class Solution {
public:
// basic approach:
// we can make a map(frequency array) of size n and check what element doesnt exist


// optimal approach : 
// O(n) basically sum(0,n) - sum(nums) which would give the number which was not included
    int missingNumber(vector<int>& nums) {
        // something involving sum
        // brute make a map
        // optimal mae sum hoga
        int n = nums.size();
        int sum = ((n + 1) * n) / 2;
        for(auto val : nums){
            sum = sum - val;
        }
        return sum;
    }
};

// there is one more aproach which involves bit manipulation, just like single number question we can use xor here.
int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            res = res ^ i;
            res = res ^ nums[i]; a^a^b = b
        } // so here we didnt do res ^ n
        int n = nums.size();
        return res ^ n;
}

