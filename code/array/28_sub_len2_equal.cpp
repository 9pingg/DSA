/*
Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.
Return true if these subarrays exist, and false otherwise.
A subarray is a contiguous non-empty sequence of elements within an array.

*/
// o(n) and o(n) space
bool findSubarrays(vector<int>& nums) {
    unordered_set<int> m; // using a hash set
    for(int i = 0 ; i < nums.size()-1 ; i++){
        int s = nums[i] + nums[i+1]; // taking two numbers at one time, and checking if they exist in set or not
        if(m.count(s)){
            return true;
        }
        else{
            m.insert(s);
        }
    }    
    return false;
}