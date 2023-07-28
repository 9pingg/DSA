// time complexity: O(n^2)
// for every i loop from i+1 to n-1 using two pointer
// so the inner loop takes n/2
// so O(n * n/2)

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    vector<int> vals = {};
    //  n >= 3 is must to find 3 values
    for(int i = 0 ; i < nums.size()-2 ; i++){
        // sum cannot be eq to 0 if nums[i] > 0
        if(nums[i] > 0) break;
        // triplet for i-1 are already found out, so skip the duplicate elements
        if(i > 0 && nums[i] == nums[i-1]) continue;

        // let nums[i] be the first of the 3 vals, find the other two in [i+1, n) 
        int l = i+1;
        int r = nums.size()-1;
    
        while(l < r){
            vals = {};
            if(nums[i] + nums[l] + nums[r] == 0) {
                vals = {nums[i], nums[l], nums[r]};
                res.push_back(vals);
                // duplicates to be removed only when they are chosen
                // remove all duplicates of vals[1]
                while(l < r && nums[l+1] == vals[1]) l++;
                // remove all duplicates of vals[2]
                while(l < r && nums[r-1] == vals[2]) r--; 
                l++;
                r--;
            }
            

            // l doesnt have high enough value
            else if(nums[i] + nums[l] + nums[r] < 0){
                l++;
            }
            // r doesnt have low enough value
            else if(nums[i] + nums[l] + nums[r] > 0){
                r--;
            }
            
        }
    }
    return res;  
}
