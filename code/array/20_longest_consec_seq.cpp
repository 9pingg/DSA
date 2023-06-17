
// SEQUENCE not the same as SUBARRAY 

// brute force use set so nums sorted now start with num, set.contains(nums+1) len++; O(n*log(n))
// we can do this O(n) by using unordered_set as we know the next number we need to find has to be +1. but what if we tkae 
// any number and traverse both sides prev and next. use set.find()
// next = val+1
// prev = val-1

//optimal solution : O(N)


int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> m (nums.begin(), nums.end()); // BEST WAY TO CONVERT VECTOR TO SET
        
        int prev = 0;
        int next = 0;
        int len = 0;
        int max_len = INT_MIN;

        for(int val : nums){

            if(m.find(val) == m.end()) continue; //no need to process deleted elements.
            
            len = 1; // include val in the sequence.

            prev = val-1; // if val = 3 (nums = 1,2,3,4,10) then prev = 2, 1  
            next = val+1; // next = 4
            m.erase(val); 
            // find prev and del them 
            while(m.find(prev) != m.end()){
                cout << prev << endl;
                m.erase(prev);
                len++;
                prev--;
            }
        
            while(m.find(next) != m.end()){
                cout << next << endl;
                m.erase(next);
                len++;
                next++;
            }
 
            max_len = max(len, max_len);
        }   
        return max_len;
    }











// READ THIS YOU CANNOT DELETE VALUES FROM THE SET WHEN UR ITERATING IN THE SET
int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> m (nums.begin(), nums.end());
        int prev = 0;
        int next = 0;
        int len = 0;
        int max_len = INT_MIN;
        for(int val : m){
            if(m.find(val) == m.end()) continue;
            m.erase(val); //CANNOT DO THIS wrong, instead use the orignal vector nums for iterating.
            cout << "val " << val << endl;
            len = 1;
            prev = val-1;
            next = val+1;
            while(m.find(prev) != m.end()){
                cout << prev << endl;
                m.erase(prev);
                len++;
                prev--;
            }
            while(m.find(next) != m.end()){
                cout << next << endl;
                m.erase(next);
                len++;
                next++;
            }
             

            max_len = max(len, max_len);
        }   
        return max_len;
    }