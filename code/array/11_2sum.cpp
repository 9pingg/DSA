class Solution {
public:
// O(N) and O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for(int i = 0 ; i < nums.size() ; i++){
            if(m.count(target-nums[i])){
                return vector<int> {i, m[target-nums[i]]};
            } 
            m[nums[i]] = i;
        }
        return vector<int> {0,0};
    }
};
