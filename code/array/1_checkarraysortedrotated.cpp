// 1)check array is sorted
// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/


class Solution {
public:
    // 1st approach starting loop from 1

    // basically if the array is rotated and sorted their must be a
    // 1 break point. if more than 1 breakpoint array cannot be sorted
    
    // two cases when true:
    // 1) when array has count = 0
    // 2) when array has count = 1, if count is then the last element of the array has to be less than the first element of the array.
    // this due to how count is measure, count inc when an element comes which is less than all the elements which prev came, 
    // so all the elements comming after count element shoulod be less than all the elements comming before count element.

    bool check(vector<int>& arr) {
        int count = 0;
        for(int i = 1; i < arr.size() ; i++){
            if(count > 1) return false;
            if(arr[i-1] <= arr[i]) {
                continue;
            }
            else {
                count++;
            }
        }
        if(count == 1 && arr[arr.size()-1] > arr[0]) return false;
        if(count <= 1) return true;
        return false;
    }
    // OR do this

    bool check(vector<int>& arr) {
        int count = 0;
        for(int i = 0; i < arr.size() ; i++){
            if(count > 1) return false;
            if(arr[i] > arr[(i+1) % arr.size()]) count++;            
        }
        // if(count == 1 && arr[arr.size()-1] > arr[0]) return false; this condition does need to be checked here.
        if(count <= 1) return true;
        return false;
    }

};