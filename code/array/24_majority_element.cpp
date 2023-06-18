
// O(n) BUT USES extra o(n) space
vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int val : nums){
            m[val]++;
        }
        vector<int> res;
        for(pair<int,int> p: m){
            if(p.second > floor(nums.size()/3)) res.push_back(p.first);
        }
        return res;
    }

//optimal aproach is again based on moore voting algo just like in majority element n/2
// ques: it asks use to give integers whose freq > floor(n/3). so ques comes who many such integer could exist.
// answer: at max 2 can exist because freq1 + freq2> floor(n/2) so they would cover more than 50% of the array no space
// for a third majority element.

// Moore Majority Vote algorithm set majority element if next cval same inc counter if not dec counter
// here we can have 2 elements so we take two counters 

vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int count1 = 0;
        int count2 = 0;
        int m1 = -1;
        int m2 = -1;

        for(int val : nums){
            if(count1 == 0 && val != m2){ // check this element is not eq to m2
                count1++;
                m1 = val;
            }
            else if(count2 == 0 && val != m1){ // same check for this
                count2++;
                m2 = val;
            }
            else if(m1 == val) count1++;
            else if (m2 == val) count2++;
            else{
                count1--;
                count2--;
            }   
        }
        count1 = 0;
        count2 = 0; 
        for(int val : nums){
            if(m1 == val) count1++;
            if(m2 == val) count2++;
        }
        if(count1 > floor(nums.size()/ 3)) res.push_back(m1);
        if(m1!=m2 && count2 > floor(nums.size()/ 3)) res.push_back(m2);
        return res;
    }