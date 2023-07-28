vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> t;
    if(nums.size() < 4) return res;
    
    for(int i = 0 ; i < nums.size()-3; i++){       
        // remove duplicates for i
        // if(i > 0 && nums[i] == nums[i-1]) continue;     
        for(int j = i+1 ; j < nums.size()-2 ; j++){
            // remove duplicates for j (never check this j = i+1)
            // if(j > i+1 && nums[j] == nums[j-1]) continue;    
            int l = j+1;
            int r = nums.size()-1;

            while(l < r){
                t = {};
                // adding 4 nums > INT_MAX
                long long sum = 1LL*nums[i] + 1LL*nums[j] + 1LL*nums[l] + 1LL*nums[r];
                if(sum == target){
                    t = {nums[i], nums[j], nums[l], nums[r]};
                    res.push_back(t);
                    while(l+1 < r && nums[l+1] == t[2]) l++; // remove duplicates for l
                    while(l < r-1 && nums[r-1] == t[3]) r--; // remove duplicates for r
                    l++;
                    r--;
                }
                else if(sum < target){
                    l++;
                    
                }
                else{
                    r--;
    
                }
            }
            // remove duplicates of j
            // always better to remove duplicates after we are done with nums[j]
            
            while(j+1 < nums.size() && nums[j] == nums[j+1]) j++;
        }
        // remove duplicates of i
        while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
    }   
    return res;
}
