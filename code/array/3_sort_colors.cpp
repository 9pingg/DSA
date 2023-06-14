class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p2 = nums.size()-1;
        for(int i = 0 ; i <= p2 ; i++){
            if(nums[i] == 0)  swap(nums[p0++], nums[i]);
            if(nums[i] == 2) swap(nums[p2--], nums[i--]);

        }
    }
};