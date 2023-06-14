
https://leetcode.com/problems/single-number/description/
#include <bits/stdc++.h>

class Solution {
public:
    int singleNumber(vector<int>& v) {
        int res = 0;
        for(auto val :v){
            res = res ^ val; // xor 1^1 = 0 1^ 0 =1 so duplicates would result in 0 0^single_num = single_num
        }
        return res;
    }
};