// BASIC DO RECURSION FIND ALL PERMUTATIONS O(N*N!), then put them in a set and do linear search to find the desired permuation of arr.

// better appraoch : use stl next_permuation(arr.begin(), arr.end())

// optimal approach: two traversals O(2*N)
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if(n <= 1) return ;
    int min_e = INT_MAX;
    
    int j = -1;
    for(int i = n-1 ; i >= 1 ; i--){
        if(nums[i-1] < nums[i]){
            // found the pivot point which has to be changed i-1
            // find a value from i to n-1 which is greater than i-1 and min of all values let it be index j
            // NOTE ALL VALUES FROM i to n-1 would be in descending order

            // find j using this loop, replace i-1 with j
            for(int k = n-1 ; k >= i ; k--){ // one of them would replace i-1
                if(nums[k] > nums[i-1] && min_e > nums[k]){
                    min_e = min(min_e, nums[k]);
                    j = k; // only set this if min_e > num[k]
                }
            }
            swap(nums[i-1], nums[j]);

            // now sort/reverse i to n-1 
            reverse(nums.begin()+i, nums.end());
            return;
        }

    }
    // if the array is already is desceding order return the reverse of it.
    // [3,2,1] => [1,2,3]
    reverse(nums.begin(), nums.end());
}