int findMaxConsecutiveOnes(vector<int>& nums) {
    int res = 0;
    int cnt = 0;
    for(int val : nums){
        if(val == 1){
            cnt+=1;
            res = max(res, cnt);
        }
        else{
            cnt = 0;
        }
    }
    return res;
}