class Solution {
public:
// basically print the number which appears more than floor(n/2) times
// if n = 9, print element which has freq > 4
// if n = 8 print element freq > 4
// basic approach map O(N) t and O(N) space 
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m; //O(N) space 
        // declaring a map with key as element and value as count 
        for(auto val : nums){
            m[val]++;
            if(m[val] > floor(nums.size() / 2)) return val; // after updating map we can check if the val is a majority element with in the same loop.
        }
        return -1;
    }
};

// optimal approach MOORE'S VOTING ALGO  = MAJORITY ELEMENT
// USED TO FIND CANDIDATE WHICH SCORED MORE THAN 50 % OF THE VOTES
// ONLY WORKS IF ARRAY GURANTEED HAS A MAJORITY ELEMENT
// O(N), O(1)
int majorityElement(vector<int>& nums) {
        int count = 0;
        int  majority_element = -1;
        for(int i = 0; i < nums.size() ;i++){
            if(count == 0) { // if count = 0 then we set a new majority element
                             // as the prev element got cancelled out
                             // set count to 1

                majority_element = nums[i];
                count++;
            }else if(nums[i] == majority_element){
                // if majority element found then inc count
                count++;
            }else count--; // not majority element then dec count
        }
        // if we are sure that a majority element is there in ana array then only
        // we can use this algorithm and at last after loop we always have the
        // majority element
        return majority_element;
    }