// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

// There is only one repeated number in nums, return this repeated number.


// two soln:

// 1) using freq arr or hashmap o(n), o(n)
int findDuplicate(vector<int>& nums) {
    unordered_map<int,int> m;
    for(int val : nums){
        if(m.count(val)) return val;
        m[val] = 1;
    } 
    return -1;
}

// 2) the question is formatted in a way, that it can be solved using cycle entry point like in linked list
// if asked check format

int findDuplicate(vector<int>& nums) {
        // marking visited within the array solves teh ques
    int s = nums[0];
    int f = nums[0];    
    int n = nums.size();
    int start = nums[0];
    while(true){
        s = nums[s]; // move by 1
        f = nums[nums[f]]; // move by 2
        if(s == f){
            while(start != s){
                start = nums[start];
                s = nums[s];
            }               
            return s; 
        }
    }
    return -1;
}
