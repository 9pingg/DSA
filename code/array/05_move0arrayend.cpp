class Solution {
public:
//ERASE IN VECTOR ALWAYS O(n) because u need to shift elements
// GOOD QUES
    void moveZeroes(vector<int>& nums) {
        // find the first position where 0 is at.
        int pos_z = -1;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0) {
                pos_z = i;
                break;
            }
        }
        if(pos_z == -1) return; // IMP if no zero found return 
        for(int i = pos_z + 1 ;i < nums.size() ; i++){
            if(nums[i]!=0){
                swap(nums[i], nums[pos_z++]); // pos_z has to be always incremeted not pos_z = i.
            }    
        }
        // total complexity still O(N) when both loops added.
    }
    
};