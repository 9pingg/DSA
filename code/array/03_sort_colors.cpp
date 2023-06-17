class Solution {
public:
// O(N) in place two pointer appraoch other approach : freq array or sort
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p2 = nums.size()-1;
        for(int i = 0 ; i <= p2 ; i++){ // i <= p2 remember
            if(nums[i] == 0)  swap(nums[p0++], nums[i]); // after the swapping here nums[i] could become 2 so we need to check for nums[i] = 2 also 
            if(nums[i] == 2) swap(nums[p2--], nums[i--]); // reason for no else if => 

        }
    }
};